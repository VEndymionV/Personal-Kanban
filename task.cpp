#include "task.h"
#include "ui_task.h"
#include <QLabel>
#include "mainwindow.h"
#include <QDebug>

Task::Task(QWidget *parent) :QWidget(parent),
    ui(new Ui::Task)
{

    ui->setupUi(this);



//sztywno
    taskName="TEST";
    taskDescription="TESTESTESTESTESTESTTESTTEST";
    taskPriority="21";
    taskBeginDate="21.07.1588";
    taskEndDate="21.07.2127";
    wsk=0;


    //przypisywanie
    ui->name->setText(taskName);
    ui->priority->setText(taskPriority);
    ui->description->setText(taskDescription);
    ui->beginDate->setText(taskBeginDate);
    ui->endDate->setText(taskEndDate);
    actualLayoutNumber = Layout::LEFT;
}

Task::Task(QString taskName, QString taskDescription, QString taskPriority,
           QString taskBeginDate, QString taskEndDate) : ui(new Ui::Task),
    taskName(taskName), taskDescription(taskDescription), taskPriority(taskPriority),
    taskBeginDate(taskBeginDate), taskEndDate(taskEndDate)
{
    ui->setupUi(this);

    ui->name->setText(taskName);
    ui->priority->setText(taskPriority);
    ui->description->setText(taskDescription);
    ui->beginDate->setText(taskBeginDate);
    ui->endDate->setText(taskEndDate);

    ui->beginTime->hide();
    ui->endTime->hide();
    ui->BEGINTIME->hide();
    ui->ENDTIME->hide();

    qDebug() << taskEndDate;

    qDebug() << "!!!!";
}

Task::Task(QString taskName, QString taskDescription, QString taskPriority,
           QString taskBeginDate, QString taskEndDate, QString taskBeginTime, QString taskEndTime)
    : ui(new Ui::Task), taskName(taskName), taskDescription(taskDescription), taskPriority(taskPriority),
      taskBeginDate(taskBeginDate), taskEndDate(taskEndDate), taskBeginTime(taskBeginTime), taskEndTime(taskEndTime)
{
    ui->setupUi(this);

    ui->name->setText(taskName);
    ui->priority->setText(taskPriority);
    ui->description->setText(taskDescription);
    ui->beginDate->setText(taskBeginDate);
    ui->endDate->setText(taskEndDate);
    ui->beginTime->setText(taskBeginTime);
    ui->endTime->setText(taskEndTime);

}

Task::Task(QWidget *parent, QString one,QString two,QString three,QString four,QString five) :QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    ui->name->setText(one);
    ui->description->setText(two);
    ui->priority->setText(three);
    ui->beginDate->setText(four);
    ui->endDate->setText(five);
    wsk=0;
    actualLayoutNumber = Layout::LEFT;
}

Task::~Task()
{

}
//przesunięcie zadania w prawo
void Task::on_pushButton_right_clicked()
{
    if(actualLayoutNumber == Layout::LEFT){
        actualLayoutNumber = Layout::CENTER;
    }
    else if(actualLayoutNumber == Layout::CENTER){
        actualLayoutNumber = Layout::RIGHT;
    }
    else{
        // Tutaj nie może tego zrobić
    }

}
//przesunięcie zadania w lewo
void Task::on_pushButton_left_clicked()
{
    if(actualLayoutNumber == Layout::RIGHT){
        actualLayoutNumber = Layout::CENTER;
    }
    else if(actualLayoutNumber == Layout::CENTER){
        actualLayoutNumber = Layout::LEFT;
    }
    else{
        // Tutaj nie może tego zrobić
    }
}
//anulowanie zadania
void Task::on_pushButton__cancel_clicked()
{
    //delete ui;
}
