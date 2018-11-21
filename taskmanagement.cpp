#include "taskmanagement.h"

TaskManagement::TaskManagement(QVBoxLayout *toDo, QVBoxLayout *inProgress, QVBoxLayout *done)
    : toDoLayout(toDo), inProgressLayout(inProgress), doneLayout(done)
{
    toDoLayout->insertWidget(0, new Task(nullptr, "one", "two", "three", "four", "five"));
}

void TaskManagement::addNewTask()
{

}
