#ifndef TASKMANAGEMENT_H
#define TASKMANAGEMENT_H

#include <QWidget>
#include "taskdialog.h"
#include "task.h"
#include <QLinkedList>

class QVBoxLayout;

class TaskManagement : public QObject
{
public:
    TaskManagement(QVBoxLayout *toDo, QVBoxLayout *inProgress, QVBoxLayout *done);
    void addNewTask();
    void refreshLayouts();
    void sortByName();
    void sortByDateAndTime();
private:
    QVBoxLayout *toDoLayout;
    QVBoxLayout *inProgressLayout;
    QVBoxLayout *doneLayout;
    QLinkedList <Task*> toDoTasks;
    QLinkedList <Task*> inProgressTasks;
    QLinkedList <Task*> doneTasks;

public slots:
    void moveTaskLeft();
    void moveTaskRight();
    void deleteTask();
};

#endif // TASKMANAGEMENT_H
