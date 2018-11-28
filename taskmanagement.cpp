#include "taskmanagement.h"
#include <QVBoxLayout>
#include "taskdialog.h"
#include "task.h"
#include <QDebug>


/*
 * Trzeba pomyśleć o zmianie QVBoxLayout na inny layout, przy tym layoucie ciężko będzie zrobić sortowanie.
 * Gdy taski będą przechowywane na liście to posortowanie listy nie wpłynie na posortowanie widoku w layoucie.
*/
TaskManagement::TaskManagement(QVBoxLayout *toDo, QVBoxLayout *inProgress, QVBoxLayout *done)
    : toDoLayout(toDo), inProgressLayout(inProgress), doneLayout(done)
{

}

void TaskManagement::addNewTask()
{
    TaskDialog taskDialog;
    taskDialog.exec();
    if(taskDialog.getState()){
        return;
    }

    TaskDialog::TaskData taskData = taskDialog.getData();
    if(taskData.beginTime.isEmpty()){
        toDoLayout->insertWidget(0, new Task(taskData.name, taskData.description, taskData.priority,
                                             taskData.beginDate, taskData.endDate));
    }
    else{
        toDoLayout->insertWidget(0, new Task(taskData.name, taskData.description, taskData.priority,
                                             taskData.beginDate, taskData.endDate, taskData.beginTime, taskData.endTime));
    }
}
