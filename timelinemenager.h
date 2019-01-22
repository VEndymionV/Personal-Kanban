#ifndef TIMELINEMENAGER_H
#define TIMELINEMENAGER_H
#include <QList>
#include <QDate>
class Qstring;
class Task;
class Timelinemenager
{
public:
//    Timelinemenager();
    Timelinemenager(QList<Task *> &toDoTasks,QList <Task*> &inProgressTasks,QList <Task*> &doneTasks,QList <Task*> &calendarTasks);
    void readtimeline(QString date);
    void cleanup();
    QList <Task*> &toDoTasks; // referencja na kontener z klasy TaskManager
    QList <Task*> &inProgressTasks; // referencja na kontener z klasy TaskManager
    QList <Task*> &doneTasks; // referencja na kontener z klasy TaskManager
     QList <Task*> &calendarTasks;

};


#endif // TIMELINEMENAGER_H
