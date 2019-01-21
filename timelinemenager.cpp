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
Timelinemenager::Timelinemenager(QList<Task *> &toDoTasks,QList <Task*> &inProgressTasks,QList <Task*> &doneTasks,QList <Task*> &calendarTasks): toDoTasks(toDoTasks), inProgressTasks(inProgressTasks),doneTasks(doneTasks),calendarTasks(calendarTasks)
{

}
void Timelinemenager::readtimeline()
{
    for(auto task1:toDoTasks)
    {
       // qDebug() << "D1";
       // qDebug()<<task1->getStartingData();

    if(task1->getStartingData()=="pon. sty 21 2019") //sztywno dla sprawdzenia, potem zastapic na QStringa edi
    {
        //calendarTasks.push_back(task1);
        Task* tmp=new Task(task1->getTaskData());
        calendarTasks.push_back(tmp);
        qDebug() << "Dodano taska do kalendarza";

    }
    }
    for(auto task2:inProgressTasks)
    {
        if(task2->getStartingData()=="21.01.2019") calendarTasks.push_back(task2);
    }


}
