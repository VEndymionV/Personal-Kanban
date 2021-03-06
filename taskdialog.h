#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QDateTimeEdit>

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(QWidget *parent = nullptr);
    ~TaskDialog();
    struct TaskData {
        QString name;
        QString description;
        QString priority;
        QString beginDate;
        QString beginTime;
        QString endDate;
        QString endTime;
    };

private slots:
    void on_buttonBox_accepted();

    void on_timeCheckBox_stateChanged(int arg1);

    void on_buttonBox_rejected();

private:
    Ui::TaskDialog *ui;

    QDateEdit beginDateEdit;
    QDateTimeEdit beginDateTimeEdit;
    QDateEdit endDateEdit;
    QDateTimeEdit endDateTimeEdit;

    QDateTimeEdit *beginActualDateEdit;
    QDateTimeEdit *endActualDateEdit;

    TaskData taskData;

    QString taskName;
    QString taskDescription;
    QString taskPriority;
    QString taskBeginDate;
    QString taskBeginTime;
    QString taskEndDate;
    QString taskEndTime;

    bool timeState;
    bool errorState;


    bool validate(QString name, QString description, QDate beginDate, QDate endDate, QTime beginTime, QTime endTime);
public:
    // TODO nieużywane, do usunięcia
    QString getTaskName();
    QString getTaskDescription();
    QString getTaskPriority();
    QString getTaskBeginDate();
    QString getTaskBeginTime();
    QString getTaskEndDate();
    QString getTaskEndTime();
    // Koniec nieużywanych
    bool getState();
    TaskData getData();
};

#endif // TASKDIALOG_H
