#ifndef TASKMANAGEMENT_H
#define TASKMANAGEMENT_H

#include <QWidget>
#include "taskdialog.h"

class QVBoxLayout;

class TaskManagement
{
public:
    TaskManagement(QVBoxLayout *toDo, QVBoxLayout *inProgress, QVBoxLayout *done);
    void addNewTask();
private:
    QVBoxLayout *toDoLayout;
    QVBoxLayout *inProgressLayout;
    QVBoxLayout *doneLayout;
};

#endif // TASKMANAGEMENT_H
