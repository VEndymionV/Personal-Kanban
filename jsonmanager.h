#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <QList>

class QString;

class Task;

class JsonManager
{
public:
    JsonManager(QList<Task *> &toDoTasks,QList <Task*> &inProgressTasks,QList <Task*> &doneTasks, const QString &fileName = "toDoTasks.json");
    bool saveToJsonFile(const QString &fileName);
    bool saveToJsonFiles();
    bool loadFromJsonFile(const QString &fileName);
    bool loadFromJsonFiles(int wsk, QString name);
private:
    QList <Task*> &toDoTasks; // referencja na kontener z klasy TaskManager
    QList <Task*> &inProgressTasks; // referencja na kontener z klasy TaskManager
    QList <Task*> &doneTasks; // referencja na kontener z klasy TaskManager

    QString fileName;

    bool write(QJsonObject &jsonObject, Task *task) const;
    QJsonObject write(Task *task, int type) const;
};

#endif // JSONMANAGER_H
