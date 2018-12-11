#include "jsonmanager.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <task.h>
#include <QDebug>
#include <QVector>


JsonManager::JsonManager(QList<Task *> &toDoTasks, const QString &fileName)
    : toDoTasks(toDoTasks), fileName(fileName)
{

}

bool JsonManager::saveToJsonFile()
{
    QFile jsonFile(fileName);

    if(!jsonFile.open(QIODevice::WriteOnly)){
        qWarning("Nie mozna otworzyc pliku do zapisu!");
        return false;
    }

//    QVector <QJsonObject> jsonObjects;
//    jsonObjects.reserve(toDoTasks.size());

    QJsonArray jsonArray;

    for(auto task : toDoTasks){
        jsonArray.push_back(write(task));
//        jsonObjects.push_back(QJsonObject());
//        if(!write(jsonObjects.back(), task)){
//            return false;
//        }
//        QJsonDocument jsonDocument(jsonObjects.back());
//        jsonFile.write(jsonDocument.toJson());
    }

    QJsonDocument jsonDocument(jsonArray);
    jsonFile.write(jsonDocument.toJson());

    jsonFile.close();

    return true;
}

bool JsonManager::loadFromJsonFile()
{
    QFile jsonFile(fileName);

    if(!jsonFile.open(QIODevice::ReadOnly)){
        qWarning("Nie mozna otworzyc pliku do odczytu!");
        return false;
    }

    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFile.readAll());

    QJsonArray jsonArray(jsonDocument.array());

    QVector <Task::TaskData*> tasksData; // wolałbym tutaj bez wskaźnika ale nie mam czasu teraz na łatanie błędów
    for(auto jsonObject : jsonArray){
        tasksData.push_back(new Task::TaskData(jsonObject.toObject()["name"].toString(),
                jsonObject.toObject()["description"].toString(),
                jsonObject.toObject()["priority"].toString(),
                jsonObject.toObject()["beginDate"].toString(),
                jsonObject.toObject()["beginTime"].toString(),
                jsonObject.toObject()["endDate"].toString(),
                jsonObject.toObject()["endTime"].toString()));
    }

    for(auto taskData : tasksData){
        toDoTasks.push_back(new Task(*taskData));
    }

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

QJsonObject JsonManager::write(Task *task) const
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

    return jsonObject;
}
