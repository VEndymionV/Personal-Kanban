#include "jsonmanager.h"
#include <QJsonObject>
#include <QJsonDocument>
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

    QVector <QJsonObject> jsonObjects;
    jsonObjects.reserve(toDoTasks.size());

    for(auto task : toDoTasks){
        jsonObjects.push_back(QJsonObject());
        if(!write(jsonObjects.back(), task)){
            return false;
        }
        QJsonDocument jsonDocument(jsonObjects.back());
        jsonFile.write(jsonDocument.toJson());
    }


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
