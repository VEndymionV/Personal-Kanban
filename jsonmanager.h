#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <QList>

class Task;

class JsonManager
{
public:
    JsonManager(QList <Task*> &toDoTasks, const QString &fileName = "toDoTasks.json");
    bool saveToJsonFile();
    bool loadFromJsonFile();
private:
    QList <Task*> &toDoTasks; // referencja na kontener z klasy TaskManager

    QString fileName;

    bool write(QJsonObject &jsonObject, Task *task) const;
    QJsonObject write(Task *task) const;
};

#endif // JSONMANAGER_H
