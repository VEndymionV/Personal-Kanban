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



//Timelinemenager::highlight()

}

void Timelinemenager::highlight(QPainter *painter, const QRect &rect, const QDate &date)
{
    QCalendarWidget::paintCell(painter, rect, date);

    for(auto task1:toDoTasks)
    {
        QString Data = task1->getStartingData();
        QDate Date = QDate::fromString(Data,"dd/MM/yyyy");

    if (date == Date)
    {
        painter->setPen(m_outlinePen);
        painter->setBrush(m_transparentBrush);
        painter->drawRect(rect.adjusted(0, 0, -1, -1));
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
