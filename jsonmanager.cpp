#include "jsonmanager.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <task.h>
#include <QDebug>
#include <QVector>


JsonManager::JsonManager(QList<Task *> &toDoTasks,QList <Task*> &inProgressTasks,QList <Task*> &doneTasks, const QString &fileName)
    : toDoTasks(toDoTasks), fileName(fileName), inProgressTasks(inProgressTasks),doneTasks(doneTasks)
{

}

bool JsonManager::saveToJsonFile(const QString &fileName)
{
    QFile jsonFile(fileName);

    if(!jsonFile.open(QIODevice::WriteOnly)){
        qWarning("Nie mozna otworzyc pliku do zapisu!");
        return false;
    }

    QJsonArray jsonArray;

    for(auto task : toDoTasks){
        jsonArray.push_back(write(task, 1));
    }

    for(auto task2: inProgressTasks)
    {
        jsonArray.push_back(write(task2, 2));
    }

    for(auto task3: doneTasks)
    {
        jsonArray.push_back(write(task3, 3));
    }

    QJsonDocument jsonDocument(jsonArray);

    jsonFile.write(jsonDocument.toJson());

    jsonFile.close();

    return true;
}


bool JsonManager::saveToJsonFiles()
{
    QFile jsonFile("toDoTasks.json");
    QFile jsonFile2("inProgressTasks.json");
    QFile jsonFile3("doneTasks.json");
    jsonFile2.open(QIODevice::WriteOnly);
    jsonFile3.open(QIODevice::WriteOnly);
    if(!jsonFile.open(QIODevice::WriteOnly)){
        qWarning("Nie mozna otworzyc pliku do zapisu!");
        return false;
    }

//    QVector <QJsonObject> jsonObjects;
//    jsonObjects.reserve(toDoTasks.size());

    QJsonArray jsonArray;
    QJsonArray jsonArray2;
    QJsonArray jsonArray3;

    for(auto task : toDoTasks){
        jsonArray.push_back(write(task, 0));
//        jsonObjects.push_back(QJsonObject());
//        if(!write(jsonObjects.back(), task)){
//            return false;
//        }
//        QJsonDocument jsonDocument(jsonObjects.back());
//        jsonFile.write(jsonDocument.toJson());
    }
    for(auto task2: inProgressTasks)
    {
        jsonArray2.push_back(write(task2, 0));
    }
    for(auto task3: doneTasks)
    {
        jsonArray3.push_back(write(task3, 0));
    }

    QJsonDocument jsonDocument(jsonArray);
    QJsonDocument jsonDocument2(jsonArray2);
    QJsonDocument jsonDocument3(jsonArray3);
    jsonFile.write(jsonDocument.toJson());
    jsonFile2.write(jsonDocument2.toJson());
    jsonFile3.write(jsonDocument3.toJson());

    jsonFile.close();
    jsonFile2.close();
    jsonFile3.close();

    return true;
}

bool JsonManager::loadFromJsonFile(const QString &fileName)
{
    QFile jsonFile(fileName);

    if(!jsonFile.open(QIODevice::ReadOnly)){
        qWarning("Nie mozna otworzyc pliku do odczytu!");
        return false;
    }

    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFile.readAll());

    QJsonArray jsonArray(jsonDocument.array());

    QVector <Task::TaskData*> tasksData; // wolałbym tutaj bez wskaźnika
    for(auto jsonObject : jsonArray){

        tasksData.push_back(new Task::TaskData(jsonObject.toObject()["name"].toString(),
                jsonObject.toObject()["description"].toString(),
                jsonObject.toObject()["priority"].toString(),
                jsonObject.toObject()["beginDate"].toString(),
                jsonObject.toObject()["beginTime"].toString(),
                jsonObject.toObject()["endDate"].toString(),
                jsonObject.toObject()["endTime"].toString()));

        QString type = jsonObject.toObject()["type"].toString();

        qDebug() << type;

        if(type == "toDo"){
            toDoTasks.push_back(new Task(*(tasksData.last())));
        }
        else if(type == "inProgress"){
            inProgressTasks.push_back(new Task(*(tasksData.last())));
        }
        else if(type == "done"){
            doneTasks.push_back(new Task(*(tasksData.last())));
        }
    }


    // tymczasowe czyszczenie pamieci po vectorze
    for(auto it = tasksData.begin(); it != tasksData.end(); ++it){
        delete (*it);
    }

    tasksData.clear();

    jsonFile.close();

    return true;
}

bool JsonManager::loadFromJsonFiles(int wsk, QString name)//wsk nam mowi, ktora warstwa wczytujemy 0-todo 1-inprogress 2-done
{
    QFile jsonFile(name);

    if(!jsonFile.open(QIODevice::ReadOnly)){
        qWarning("Nie mozna otworzyc pliku do odczytu!");
        return false;
    }

    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFile.readAll());

    QJsonArray jsonArray(jsonDocument.array());

    QVector <Task::TaskData*> tasksData; // wolałbym tutaj bez wskaźnika
    for(auto jsonObject : jsonArray){
        tasksData.push_back(new Task::TaskData(jsonObject.toObject()["name"].toString(),
                jsonObject.toObject()["description"].toString(),
                jsonObject.toObject()["priority"].toString(),
                jsonObject.toObject()["beginDate"].toString(),
                jsonObject.toObject()["beginTime"].toString(),
                jsonObject.toObject()["endDate"].toString(),
                jsonObject.toObject()["endTime"].toString()));
    }
    if(wsk == 0)
    for(auto taskData : tasksData){
        toDoTasks.push_back(new Task(*taskData));
    }
    else if(wsk == 1)
    for(auto taskData : tasksData){
        inProgressTasks.push_back(new Task(*taskData));
    }
    else if(wsk == 2)
    for(auto taskData : tasksData){
        doneTasks.push_back(new Task(*taskData));
    }
    \


    // tymczasowe czyszczenie pamieci po vectorze
    for(auto it = tasksData.begin(); it != tasksData.end(); ++it){
        delete (*it);
    }

    tasksData.clear();

    jsonFile.close();

    return true;
}

bool JsonManager::write(QJsonObject &jsonObject, Task *task) const
{
    Task::TaskData taskData = task->getTaskData();

    jsonObject["name"] = taskData.name;
    jsonObject["description"] = taskData.description;
    jsonObject["priority"] = taskData.priority;
    jsonObject["beginDate"] = taskData.beginDate;
    jsonObject["beginTime"] = taskData.beginTime;
    jsonObject["endDate"] = taskData.endDate;
    jsonObject["endTime"] = taskData.endTime;

    return true;
}

QJsonObject JsonManager::write(Task *task, int type) const
{
    Task::TaskData taskData = task->getTaskData();

    QJsonObject jsonObject;

    jsonObject["name"] = taskData.name;
    jsonObject["description"] = taskData.description;
    jsonObject["priority"] = taskData.priority;
    jsonObject["beginDate"] = taskData.beginDate;
    jsonObject["beginTime"] = taskData.beginTime;
    jsonObject["endDate"] = taskData.endDate;
    jsonObject["endTime"] = taskData.endTime;

    switch(type){
    case 0:
        break;
    case 1:
        jsonObject["type"] = "toDo";
        break;
    case 2:
        jsonObject["type"] = "inProgress";
        break;
    case 3:
        jsonObject["type"] = "done";
        break;
    default:
        break;
    }

    return jsonObject;
}
