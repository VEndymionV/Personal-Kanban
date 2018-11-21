#ifndef TASKMANAGEMENT_H
#define TASKMANAGEMENT_H

#include <QWidget>

class QVBoxLayout;

class TaskManagement
{
public:
    TaskManagement(QVBoxLayout *toDo, QVBoxLayout *inProgress, QVBoxLayout *done);
    void addNewTask(QString taskName, QString taskDescription, QString taskPriority,
                    QString taskBeginDate, QString taskEndDate, QString taskBeginTime = "",
                    QString taskEndTime = "");
private:
    QVBoxLayout *toDoLayout;
    QVBoxLayout *inProgressLayout;
    QVBoxLayout *doneLayout;
};

#endif // TASKMANAGEMENT_H
