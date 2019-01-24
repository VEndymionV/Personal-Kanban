#ifndef TIMELINEMENAGER_H
#define TIMELINEMENAGER_H
#include <QList>
#include <QDate>
#include <QPainter>
#include <QCalendarWidget>
class Qstring;
class Task;
class Timelinemenager:public QCalendarWidget
{
public:
//    Timelinemenager();
    Timelinemenager(QList<Task *> &toDoTasks, QList <Task*> &inProgressTasks,
                    QList <Task*> &doneTasks,QList <Task*> &calendarTasks);
    void readtimeline(QString date);
    void highlight(QPainter *painter, const QRect &rect, const QDate &date);
    void cleanup();
    QList <Task*> &toDoTasks; // referencja na kontener z klasy TaskManager
    QList <Task*> &inProgressTasks; // referencja na kontener z klasy TaskManager
    QList <Task*> &doneTasks; // referencja na kontener z klasy TaskManager
    QList <Task*> &calendarTasks;
    QPen m_outlinePen;
    QBrush m_transparentBrush;
};


#endif // TIMELINEMENAGER_H
