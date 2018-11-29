#ifndef TASKMANAGEMENT_H
#define TASKMANAGEMENT_H

#include <QWidget>
#include "taskdialog.h"
#include "task.h"
#include <QList>

class QVBoxLayout;

class TaskManagement : public QObject
{
public:
    TaskManagement(QVBoxLayout *toDo, QVBoxLayout *inProgress, QVBoxLayout *done);
    void addNewTask();
    void addFewTasks();
    void refreshLayouts();
    void sortByName();
    void sortByDateAndTime();
private:
    QVBoxLayout *toDoLayout;
    QVBoxLayout *inProgressLayout;
    QVBoxLayout *doneLayout;
    QList <Task*> toDoTasks;
    QList <Task*> inProgressTasks;
    QList <Task*> doneTasks;

public slots:
    void moveTaskLeft();
    void moveTaskRight();
    void deleteTask();
};

#endif // TASKMANAGEMENT_H
