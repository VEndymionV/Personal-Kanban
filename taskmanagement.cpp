#include "taskmanagement.h"
#include <QVBoxLayout>
#include "taskdialog.h"
#include "task.h"
#include <QDebug>
#include <algorithm>


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

    Task *task = new Task(taskData.name, taskData.description, taskData.priority,
                          taskData.beginDate, taskData.endDate);

    toDoTasks.push_front(task);

    QObject::connect(task, &Task::leftClicked, this, &TaskManagement::moveTaskLeft);
    QObject::connect(task, &Task::rightClicked, this, &TaskManagement::moveTaskRight);
    QObject::connect(task, &Task::removeClicked, this, &TaskManagement::deleteTask);


    refreshLayouts();








//    if(taskData.beginTime.isEmpty()){
//        toDoLayout->insertWidget(0, new Task(taskData.name, taskData.description, taskData.priority,
//                                             taskData.beginDate, taskData.endDate));
//    }
//    else{
//        toDoLayout->insertWidget(0, new Task(taskData.name, taskData.description, taskData.priority,
//                                             taskData.beginDate, taskData.endDate, taskData.beginTime, taskData.endTime));
//    }


//    qDebug() << toDoLayout->indexOf()

}

void TaskManagement::addFewTasks()
{
    QString arr[] = {"Morele", "Gruszki", "Jabłka", "Kolega", "Dzwon", "Olejek", "Alkohol", "Mandarynka", "Karta",
                    "Samochód", "Silnik", "Benzynowy", "Gaz", "Kefir", "Jajko"};
    for(int i = 0; i < (int) (sizeof(arr) / sizeof(*arr)); ++i){
        Task *task = new Task(arr[i], "To jest fajny, przykladowy opis.", QString::number(i % 4),
                              "15.10.1997", "28.11.2018");
        toDoTasks.push_front(task);
        QObject::connect(task, &Task::leftClicked, this, &TaskManagement::moveTaskLeft);
        QObject::connect(task, &Task::rightClicked, this, &TaskManagement::moveTaskRight);
        QObject::connect(task, &Task::removeClicked, this, &TaskManagement::deleteTask);
    }
    refreshLayouts();
}

void TaskManagement::refreshLayouts() {

    while(QLayoutItem *item = toDoLayout->takeAt(0)){
        delete item;
    }

    while(QLayoutItem *item = inProgressLayout->takeAt(0)){
        delete item;
    }

    while(QLayoutItem *item = doneLayout->takeAt(0)){
        delete item;
    }

    int i = 0;

    for(QList <Task*>::const_reverse_iterator it = toDoTasks.rbegin(); it != toDoTasks.rend(); ++it){
        ++i;
        (*it)->id = toDoTasks.size() - i;
        (*it)->layoutNumber = toDo;
        toDoLayout->insertWidget(0, *it);
    }

    i = 0;

    for(QList <Task*>::const_reverse_iterator it = inProgressTasks.rbegin(); it != inProgressTasks.rend(); ++it){
        ++i;
        (*it)->id = inProgressTasks.size() - i;
        (*it)->layoutNumber = inProgress;
        inProgressLayout->insertWidget(0, *it);
    }

    i = 0;

    for(QList <Task*>::const_reverse_iterator it = doneTasks.rbegin(); it != doneTasks.rend(); ++it){
        ++i;
        (*it)->id = doneTasks.size() - i;
        (*it)->layoutNumber = done;
        doneLayout->insertWidget(0, *it);
    }

//    foreach(Task *task, toDoTasks) {
//        toDoLayout->insertWidget(0, task);
//    }


}

void TaskManagement::sortByName()
{
    qDebug() << "TaskManagement: sortuj";
    std::sort(toDoTasks.begin(), toDoTasks.end(), Task::caseInsensitiveByName);
    std::sort(inProgressTasks.begin(), inProgressTasks.end(), Task::caseInsensitiveByName);
    std::sort(doneTasks.begin(), doneTasks.end(), Task::caseInsensitiveByName);
    refreshLayouts();
}

void TaskManagement::sortByDateAndTime()
{

}

void TaskManagement::moveTaskLeft()
{
    qDebug() << "moveTaskLeft";
    Task *task = dynamic_cast<Task*>(sender());

    if(task->layoutNumber == toDo){
        doneTasks.push_front(task);
        toDoTasks.removeOne(task);
    }
    else if(task->layoutNumber == inProgress){
        toDoTasks.push_front(task);
        inProgressTasks.removeOne(task);
    }
    else{
        inProgressTasks.push_front(task);
        doneTasks.removeOne(task);
    }

    refreshLayouts();
}

void TaskManagement::moveTaskRight()
{
    qDebug() << "moveTaskRight";
    Task *task = dynamic_cast<Task*>(sender());

    if(task->layoutNumber == toDo){
        inProgressTasks.push_front(task);
        toDoTasks.removeOne(task);
    }
    else if(task->layoutNumber == inProgress){
        doneTasks.push_front(task);
        inProgressTasks.removeOne(task);
    }
    else{
        toDoTasks.push_front(task);
        doneTasks.removeOne(task);
    }

    refreshLayouts();
}

void TaskManagement::deleteTask()
{
    qDebug() << "deleteTask";
    Task *task = dynamic_cast<Task*>(sender());

    if(task->layoutNumber == toDo){
        toDoTasks.removeOne(task);
//        toDoLayout->removeWidget(task);
    }
    else if(task->layoutNumber == inProgress){
//        inProgressLayout->removeWidget(task);
        inProgressTasks.removeOne(task);
    }
    else{
//        doneLayout->removeWidget(task);
        doneTasks.removeOne(task);
    }

    refreshLayouts();

    delete task;

//    qDebug() << dynamic_cast<QVBoxLayout*> (task->layout())->indexOf(task);

    //toDoLayout->removeWidget(task);
    //inProgressLayout->removeWidget(task);
    //doneLayout->removeWidget(task);
}
