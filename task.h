#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLinkedList>
namespace Ui {
class Task;
}

enum Layout{
    toDo = 0,
    inProgress = 1,
    done = 2
};

class Task : public QWidget
{
    Q_OBJECT

public:
    struct TaskData {
        TaskData(QString name, QString description, QString priority,
                 QString beginDate, QString beginTime, QString endDate,
                 QString endTime) : name(name), description(description), priority(priority),
            beginDate(beginDate), beginTime(beginTime), endDate(endDate), endTime(endTime){

        }
        QString name;
        QString description;
        QString priority;
        QString beginDate;
        QString beginTime;
        QString endDate;
        QString endTime;
    };
    // Sama data
    Task(QString taskName, QString taskDescription, QString taskPriority,
         QString taskBeginDate, QString taskEndDate);
    // Data + czas
    Task(QString taskName, QString taskDescription, QString taskPriority,
         QString taskBeginDate, QString taskEndDate, QString taskBeginTime,
         QString taskEndTime);
    ~Task();

    static bool caseInsensitiveByName(const Task *a, const Task *b);
    static bool caseInsensitiveByDate(const Task &a, const Task &b);

    bool isTimeDisplayed();
    int id;
    Layout layoutNumber;

    TaskData getTaskData();

private slots:
    void on_pushButton_right_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::Task *ui;

    QString taskName;
    QString taskDescription;
    QString taskPriority;
    QString taskBeginDate;
    QString taskEndDate;
    QString taskBeginTime;
    QString taskEndTime;
    QLabel *nameLabel;
    int wsk; //gdzie się znajduje zadanie


signals:
    void removeClicked();
    void leftClicked();
    void rightClicked();
};

#endif // TASK_H
