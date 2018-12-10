#include "taskmanagement.h"
#include <QVBoxLayout>
#include "taskdialog.h"
#include "task.h"
#include <QDebug>
#include <algorithm>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
TaskManagement::TaskManagement(QVBoxLayout *toDo, QVBoxLayout *inProgress, QVBoxLayout *done)
    : toDoLayout(toDo), inProgressLayout(inProgress), doneLayout(done), jsonManager(toDoTasks)
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

    Task *task;

    if(taskData.beginTime.isEmpty() || taskData.endTime.isEmpty()){
        task = new Task(taskData.name, taskData.description, taskData.priority,
                              taskData.beginDate, taskData.endDate);
    }
    else{
        task = new Task(taskData.name, taskData.description, taskData.priority,
                              taskData.beginDate, taskData.endDate, taskData.beginTime, taskData.endTime);
    }

    toDoTasks.push_front(task);

    QObject::connect(task, &Task::leftClicked, this, &TaskManagement::moveTaskLeft);
    QObject::connect(task, &Task::rightClicked, this, &TaskManagement::moveTaskRight);
    QObject::connect(task, &Task::removeClicked, this, &TaskManagement::deleteTask);

    refreshLayouts();
}
void TaskManagement::LoadTasks(QString filename)
{
    QFile read(filename);
    read.open(QFile::ReadOnly);
    QJsonDocument docred=QJsonDocument().fromJson(read.readAll());
    QJsonArray arr=docred.array();
    QString name=docred["name"].toString();
    QString priority=docred["priority"].toString();
    QString description=docred["description"].toString();
    QString beginDate=docred["beginDate"].toString();
    QString endDate=docred["endDate"].toString();

    Task *tsk=new Task(docred["name"].toString() ,docred["description"].toString(),docred["priority"].toString(),docred["beginDate"].toString(),docred["endDate"].toString());
    //Task *tsk=new Task(name,description,priority,beginDate,endDate); //tak tez mozna, ale wtedy trzeba dodatkowe zmienne deklarowac
    toDoTasks.push_front(tsk);

    //toDoLayout->insertWidget(0,tsk);
    QObject::connect(tsk, &Task::leftClicked, this, &TaskManagement::moveTaskLeft);
    QObject::connect(tsk, &Task::rightClicked, this, &TaskManagement::moveTaskRight);
    QObject::connect(tsk, &Task::removeClicked, this, &TaskManagement::deleteTask);
    refreshLayouts();
}

void TaskManagement::addNew(Task* A)
{
    toDoLayout->insertWidget(0,A);
    refreshLayouts();

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

    // Czyszczenie każdego z layoutów
    while(QLayoutItem *item = toDoLayout->takeAt(0)){
        delete item;
    }

    while(QLayoutItem *item = inProgressLayout->takeAt(0)){
        delete item;
    }

    while(QLayoutItem *item = doneLayout->takeAt(0)){
        delete item;
    }
    // Koniec czyszczenia

    int i = 0; // zmienna pomocnicza do ustalenia obecnego id taska

    // Wypełnianie layoutów na podstawie kontenerów oraz ustawienie odpowiedniego id i layoutNumber
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

    jsonManager.saveToJsonFile();


    //tutaj wstawić zapisywanie do jsona
}

void TaskManagement::sortByName()
{
    // sortuje po kolei każdy z kontenerów
    std::sort(toDoTasks.begin(), toDoTasks.end(), Task::caseInsensitiveByName);
    std::sort(inProgressTasks.begin(), inProgressTasks.end(), Task::caseInsensitiveByName);
    std::sort(doneTasks.begin(), doneTasks.end(), Task::caseInsensitiveByName);

    refreshLayouts(); // odświeżenie layoutów - czyli zsynchronizowanie kontenera z widokiem
}

void TaskManagement::sortByDateAndTime()
{
    // TODO
}

void TaskManagement::moveTaskLeft()
{
    // ustalam który obiekt wysłał sygnał i rzutuje go na typ Task*
    Task *task = dynamic_cast<Task*>(sender());

    // ustalam do której sekcji należy task wysyłający sygnał
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
    // task został usunięty z kontenera w którym się znajdował i dodany do nowego kontenera

    refreshLayouts(); // odświeżenie layoutów - czyli zsynchronizowanie kontenera z widokiem
}

void TaskManagement::moveTaskRight()
{
    // ustalam który obiekt wysłał sygnał i rzutuje go na typ Task*
    Task *task = dynamic_cast<Task*>(sender());

    // ustalam do której sekcji należy task wysyłający sygnał
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
    // task został usunięty z kontenera w którym się znajdował i dodany do nowego kontenera

    refreshLayouts(); // odświeżenie layoutów - czyli zsynchronizowanie kontenera z widokiem
}

void TaskManagement::deleteTask()
{
    // ustalam który obiekt wysłał sygnał i rzutuje go na typ Task*
    Task *task = dynamic_cast<Task*>(sender());

    // ustalam do której sekcji należy task wysyłający sygnał
    if(task->layoutNumber == toDo){
        toDoTasks.removeOne(task);
    }
    else if(task->layoutNumber == inProgress){
        inProgressTasks.removeOne(task);
    }
    else{
        doneTasks.removeOne(task);
    }
    // task został usunięty z kontenera w którym się znajdował

    delete task; // usunięcie obiektu

    refreshLayouts(); // odświeżenie layoutów - czyli zsynchronizowanie kontenera z widokiem
}
