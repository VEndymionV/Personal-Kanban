#include "taskdialog.h"
#include "ui_taskdialog.h"
#include <QDebug>
#include <QDateEdit>
#include <QDateTimeEdit>

TaskDialog::TaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);

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
        taskName = name;
        taskDescription = description;
        taskPriority = ui->priorityEdit->text();
        taskBeginDate = beginActualDateEdit->date().toString();
        //this->accept();
    }
    else{
        // TODO Komunikat o błędnych danych
    }
}

void TaskDialog::on_timeCheckBox_stateChanged(int state) {

    QDateTimeEdit *replacementB, *replacementE;
    if(state){
        beginActualDateEdit = &beginDateEdit;
        replacementB = &beginDateTimeEdit;
        endActualDateEdit = &endDateEdit;
        replacementE = &endDateTimeEdit;
    }
    else{
        beginActualDateEdit = &beginDateTimeEdit;
        replacementB = &beginDateEdit;
        endActualDateEdit = &endDateTimeEdit;
        replacementE = &endDateEdit;
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
    this->reject();
}

bool TaskDialog::validate(QString name, QString description, QDate beginDate, QDate endDate, QTime beginTime, QTime endTime)
{
    if(name.isEmpty() || description.isEmpty())
        return false;

    // TODO Dalsza walidacja, jeżeli potrzebna.
    if(!beginDate.isValid() || !endDate.isValid())
        return false;

    if(!beginTime.isValid() || !endTime.isValid())
        return false;

    return true;
}
