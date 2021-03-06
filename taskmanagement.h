#ifndef TASKMANAGEMENT_H
#define TASKMANAGEMENT_H

#include <QWidget>
#include "taskdialog.h"
#include "task.h"
#include <QList>
#include <jsonmanager.h>
#include <timelinemenager.h>
class QVBoxLayout;

class TaskManagement : public QObject
{
public:
    // konstruktor przyjmuje trzy wskaźniki na kolejne layouty
    TaskManagement(QVBoxLayout *toDo, QVBoxLayout *inProgress, QVBoxLayout *done,QVBoxLayout *calendar);
    // dodawanie nowego taska do sekcji toDo
    void addNewTask();
    // dodawanie nowego taska do sekcji toDo na podstawie taskData - wykorzystywane przy wczytywaniu z pliku .json
    void addNewTask(Task::TaskData taskData);
    // dodawanie kilku tasków do sekcji toDo
    void addFewTasks();
    // czyści wszystkie trzy layouty a potem dodaje w odpowiedniej kolejności elementy z trzech kontenerów (synchronizacja)
    void refreshLayouts(bool timeline = false);
    // sortowanie po nazwie taska
    void sortByName();
    // TODO sortowanie po dacie i czasie
    void sortByDateAndTime();






    //wczytywanie taskow z pliku json
    void LoadTasks(QString filename);
    //test
    void addNew(Task* A);

private:
    // trzy sekcje - trzy layouty:
    QVBoxLayout *toDoLayout;
    QVBoxLayout *inProgressLayout;
    QVBoxLayout *doneLayout;
    QVBoxLayout *calendarLayout;
    // trzy sekcje - trzy kontenery synchronizujące się z layoutami poprzez metodę refreshLayouts()
    QList <Task*> toDoTasks;
    QList <Task*> inProgressTasks;
    QList <Task*> doneTasks;
    QList <Task*> calendarTasks;

public:
    JsonManager jsonManager;
    Timelinemenager timelinemenager;
    void loadFromJsonFile(const QString &fileName);
    /*
     * Sloty otrzymują sygnał z konkretnego obiektu klasy Task, rozpoznają go po jego polach - id oraz layoutNumber
    */
public slots:
    // task idzie do sekcji lewej od obecnej
    void moveTaskLeft();
    // task idzie do sekcji prawej od obecnej
    void moveTaskRight();
    // usuwanie taska z kontenera - resztą zajmuje się metoda refreshLayouts()
    void deleteTask();
};

#endif // TASKMANAGEMENT_H
