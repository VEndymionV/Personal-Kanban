#ifndef TIMELINEMENAGER_H
#define TIMELINEMENAGER_H
#include <QList>
class Qstring;
class Task;
class Timelinemenager
{
public:
    Timelinemenager();
    Timelinemenager(QList<Task *> &toDoTasks,QList <Task*> &inProgressTasks,QList <Task*> &doneTasks);
};

#endif // TIMELINEMENAGER_H
