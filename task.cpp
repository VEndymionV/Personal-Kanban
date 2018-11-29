#include "task.h"
#include "ui_task.h"
#include <QLabel>
#include <QDebug>

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

    layoutNumber = toDo;
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

    layoutNumber = toDo;
}

Task::~Task()
{

}

bool Task::caseInsensitiveByName(const Task *a, const Task *b)
{
    return a->taskName.toLower() < b->taskName.toLower();
}

bool Task::caseInsensitiveByDate(const Task &a, const Task &b)
{
    //return a.taskEndDate < b.taskEndDate;
    // TODO
    return true;
}

bool Task::isTimeDisplayed()
{
    if(taskBeginTime.isEmpty() || taskEndTime.isEmpty())
        return false;

    return true;
}

//przesunięcie zadania w prawo
void Task::on_pushButton_right_clicked()
{
    emit rightClicked();

}
//przesunięcie zadania w lewo
void Task::on_pushButton_left_clicked()
{
    emit leftClicked();
}


void Task::on_pushButton_cancel_clicked()
{
    emit removeClicked();
}
