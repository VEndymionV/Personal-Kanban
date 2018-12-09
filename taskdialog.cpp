#include "taskdialog.h"
#include "ui_taskdialog.h"
#include <QDebug>
#include <QDateEdit>
#include <QDateTimeEdit>
#include "mainwindow.h"
#include<task.h>

TaskDialog::TaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog), timeState(false), errorState(true)
{
    ui->setupUi(this);
    //wszystko co ma task w nazwie idzie do task.cpp
    beginActualDateEdit = &beginDateEdit;
    endActualDateEdit = &endDateEdit;
    ui->formLayout->setWidget(3, QFormLayout::FieldRole, beginActualDateEdit);
    ui->formLayout->setWidget(4, QFormLayout::FieldRole, endActualDateEdit);

    QDate current = QDate::currentDate();
    beginActualDateEdit->setDate(current);
    endActualDateEdit->setDate(current);
}

TaskDialog::~TaskDialog()
{
    delete ui;
}

void TaskDialog::on_buttonBox_accepted()
{
    QString name = ui->nameEdit->text();
    QString description = ui->descriptionEdit->toPlainText();
    QDate beginDate = beginActualDateEdit->date();
    QDate endDate = endActualDateEdit->date();
    QTime beginTime = beginActualDateEdit->time();
    QTime endTime = endActualDateEdit->time();

    if(validate(name, description, beginDate, endDate, beginTime, endTime)){
        taskData.name = name;
        taskData.description = description;
        taskData.priority = ui->priorityEdit->text();
        taskData.beginDate = beginActualDateEdit->date().toString();
        taskData.endDate = endActualDateEdit->date().toString();
        if(timeState){
            taskData.beginTime = beginActualDateEdit->time().toString();
            taskData.endTime = endActualDateEdit->time().toString();
        }
        else{
            taskData.beginTime = "";
            taskData.endTime = "";
        }
        errorState = false;
        this->accept();

    }
    else{
        // TODO Komunikat o błędnych danych
        errorState = true;
    }
}

void TaskDialog::on_timeCheckBox_stateChanged(int state) {

    QDateTimeEdit *replacementB, *replacementE;
    if(state){
        beginActualDateEdit = &beginDateEdit;
        replacementB = &beginDateTimeEdit;
        endActualDateEdit = &endDateEdit;
        replacementE = &endDateTimeEdit;
        timeState = true;
    }
    else{
        beginActualDateEdit = &beginDateTimeEdit;
        replacementB = &beginDateEdit;
        endActualDateEdit = &endDateTimeEdit;
        replacementE = &endDateEdit;
        timeState = false;
    }
    // Kopia danych
    replacementB->setDate(beginActualDateEdit->date());
    replacementE->setDate(endActualDateEdit->date());
    // Podmiana widgetów
    ui->formLayout->replaceWidget(beginActualDateEdit, replacementB);
    ui->formLayout->replaceWidget(endActualDateEdit, replacementE);
    // Ukrycie starych widgetów oraz pokazanie nowych
    beginActualDateEdit->hide();
    endActualDateEdit->hide();
    replacementB->show();
    replacementE->show();
    // Ustawienie wskaźników
    beginActualDateEdit = replacementB;
    endActualDateEdit = replacementE;
}

void TaskDialog::on_buttonBox_rejected()
{
    errorState = true;
    this->reject();
}

bool TaskDialog::validate(QString name, QString description, QDate beginDate, QDate endDate, QTime beginTime, QTime endTime)
{
    if(name.isEmpty() || description.isEmpty())
        return false;

    // TODO Dalsza walidacja, jeżeli potrzebna.
    if(!beginDate.isValid() || !endDate.isValid())
        return false;

    if(timeState && (!beginTime.isValid() || !endTime.isValid()))
        return false;

    return true;
}

QString TaskDialog::getTaskName()
{
    return taskName;
}
QString TaskDialog::getTaskDescription()
{
    return taskDescription;
}
QString TaskDialog::getTaskPriority()
{
    return taskPriority;
}
QString TaskDialog::getTaskBeginDate()
{
    return taskBeginDate;
}
QString TaskDialog::getTaskBeginTime()
{
    return taskBeginTime;
}
QString TaskDialog::getTaskEndDate()
{
    return taskEndDate;
}

bool TaskDialog::getState()
{
    return errorState;
}

TaskDialog::TaskData TaskDialog::getData()
{
    return taskData;
}
