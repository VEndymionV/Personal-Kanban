#include "timelinemenager.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <task.h>
#include <QDebug>
#include <QVector>
#include <QCalendarWidget>
Timelinemenager::Timelinemenager()
{

}
Timelinemenager::Timelinemenager(QList<Task *> &toDoTasks,QList <Task*> &inProgressTasks,QList <Task*> &doneTasks)
    : toDoTasks(toDoTasks), inProgressTasks(inProgressTasks),doneTasks(doneTasks)
{

}
