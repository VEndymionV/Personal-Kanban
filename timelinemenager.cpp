#include "timelinemenager.h"
#include "jsonmanager.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <task.h>
#include <QDebug>
#include <QVector>
#include <QCalendarWidget>
//Timelinemenager::Timelinemenager()
//{

//}
Timelinemenager::Timelinemenager(QList<Task *> &toDoTasks,QList <Task*> &inProgressTasks,QList <Task*> &doneTasks): toDoTasks(toDoTasks), inProgressTasks(inProgressTasks),doneTasks(doneTasks)
{

}
void Timelinemenager::readtimeline()
{
    for(auto task1:toDoTasks)
    {
    if(task1->getStartingData()=="21.01.2019") //sztywno dla sprawdzenia, potem zastapic na QStringa
    {

    }
    }


}