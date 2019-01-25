#include "timelinemenager.h"
#include "jsonmanager.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <task.h>
#include <QDebug>
#include <QVector>
#include <QCalendarWidget>
#include <QPainter>
#include <QFile>
//Timelinemenager::Timelinemenager()
//{

//}
Timelinemenager::Timelinemenager(QList<Task *> &toDoTasks,QList <Task*> &inProgressTasks,QList <Task*> &doneTasks,QList <Task*> &calendarTasks): toDoTasks(toDoTasks), inProgressTasks(inProgressTasks),doneTasks(doneTasks),calendarTasks(calendarTasks)
{
    m_outlinePen.setColor(Qt::red);
    m_transparentBrush.setColor(Qt::transparent);

}
void Timelinemenager::readtimeline(QString date)
{

    for(auto it = calendarTasks.begin(); it != calendarTasks.end(); ++it){
        delete *it;
    }

    calendarTasks.clear();



   //czyszczenie taskow
//  while(!calendarTasks.isEmpty())
//  {
//      calendarTasks.last();
//      calendarTasks.pop_back();
//  }



    for(auto task1:toDoTasks)
    {

    if(task1->getEndingData()==date) //
    {
        //calendarTasks.push_back(task1);
        Task* tmp=new Task(task1->getTaskData());
        calendarTasks.push_back(tmp);
        qDebug() << "Dodano taska do kalendarza";

    }
    }
    for(auto task2:inProgressTasks)
    {
        if(task2->getEndingData()==date)

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

void Timelinemenager::datetofile()
{
     QFile fp("daty.csv");
     qDebug()<<"utworzono plik";
     fp.open( QFile::WriteOnly| QFile::Truncate);


    for(auto task1:toDoTasks)
    {
         QTextStream out(&fp);
         out<<task1->getEndingData()<<endl;


    }

    for(auto task2:inProgressTasks)
    {


        QTextStream out(&fp);
        out<<task2->getEndingData()<<endl;


    }
    fp.close();





}
