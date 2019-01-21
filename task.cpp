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
    ui->description->setWordWrap(true);
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

Task::Task(Task::TaskData taskData) : ui(new Ui::Task)
{
    ui->setupUi(this);

    ui->name->setText(taskData.name);
    ui->priority->setText(taskData.priority);
    ui->description->setText(taskData.description);
    ui->beginDate->setText(taskData.beginDate);
    ui->endDate->setText(taskData.endDate);

    if(taskData.beginDate.isEmpty() || taskData.beginTime.isEmpty()){

        ui->beginTime->hide();
        ui->endTime->hide();
        ui->BEGINTIME->hide();
        ui->ENDTIME->hide();
    }
    else{
        ui->beginTime->setText(taskData.beginTime);
        ui->endTime->setText(taskData.endTime);
    }

    layoutNumber = toDo;

    // TYMCZASOWO, TO TRZEBA ZROBIĆ PORZĄDNIE, PRZEBUDOWAĆ CAŁY PROJEKT ŻEBY SIĘ OPIERAŁ NA TEJ STRUKTURZE, NARAZIE TU JEST TOTALNY SYYYYF
    taskName = taskData.name;
    taskDescription = taskData.description;
    taskPriority = taskData.priority;
    taskBeginDate = taskData.beginDate;
    taskEndDate = taskData.endDate;
    taskBeginTime = taskData.beginTime;
    taskEndTime = taskData.endTime;
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

Task::TaskData Task::getTaskData()
{
    return TaskData(taskName, taskDescription, taskPriority, taskBeginDate, taskBeginTime, taskEndDate, taskEndTime);
}
QString Task::getStartingData()
{
    return taskBeginDate;
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
