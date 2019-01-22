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
void Timelinemenager::readtimeline(QString date)
{

   //czyszczenie taskow
  while(!calendarTasks.isEmpty())
  {
      calendarTasks.pop_back();
  }



    for(auto task1:toDoTasks)
    {

    if(task1->getStartingData()==date) //
    {
        //calendarTasks.push_back(task1);
        Task* tmp=new Task(task1->getTaskData());
        calendarTasks.push_back(tmp);
        qDebug() << "Dodano taska do kalendarza";

    }
    }
    for(auto task2:inProgressTasks)
    {
        if(task2->getStartingData()==date)

        {
            Task* tmp=new Task(task2->getTaskData());
            calendarTasks.push_back(tmp);


        }
    }


}


void Timelinemenager::cleanup()
{
    while(!calendarTasks.isEmpty())
    {
        calendarTasks.pop_back();
    }

}
