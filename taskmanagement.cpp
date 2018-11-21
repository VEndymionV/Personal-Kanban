#include "taskmanagement.h"
#include <QVBoxLayout>
#include "taskdialog.h"
#include "task.h"


/*
 * Trzeba pomyśleć o zmianie QVBoxLayout na inny layout, przy tym layoucie ciężko będzie zrobić sortowanie.
 * Gdy taski będą przechowywane na liście to posortowanie listy nie wpłynie na posortowanie widoku w layoucie.
*/
TaskManagement::TaskManagement(QVBoxLayout *toDo, QVBoxLayout *inProgress, QVBoxLayout *done)
    : toDoLayout(toDo), inProgressLayout(inProgress), doneLayout(done)
{
    toDoLayout->insertWidget(0, new Task(nullptr, "one", "two", "three", "four", "five"));
}

void TaskManagement::addNewTask(QString taskName, QString taskDescription, QString taskPriority,
                                QString taskBeginDate, QString taskEndDate, QString taskBeginTime,
                                QString taskEndTime)
{

    if(taskBeginTime.isEmpty() || taskEndTime.isEmpty()){
        // wyświetlenie samej daty
        toDoLayout->insertWidget(0, new Task(taskName, taskDescription, taskPriority, taskBeginDate, taskEndDate));
    }
    else{
        // wyświetlenie daty i czasu
        toDoLayout->insertWidget(0, new Task(taskName, taskDescription, taskPriority, taskBeginDate, taskEndDate, taskBeginTime, taskEndTime));
    }
}
