#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
namespace Ui {
class Task;
}

namespace Layout {
    const int LEFT = -1;
    const int CENTER = 0;
    const int RIGHT = 1;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    // Sama data
    Task(QString taskName, QString taskDescription, QString taskPriority,
         QString taskBeginDate, QString taskEndDate);
    // Data + czas
    Task(QString taskName, QString taskDescription, QString taskPriority,
         QString taskBeginDate, QString taskEndDate, QString taskBeginTime,
         QString taskEndTime);
    explicit Task(QWidget *parent, QString one,QString two,QString three,QString four,QString five);
    ~Task();

private slots:
    void on_pushButton_right_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton__cancel_clicked();

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
    int actualLayoutNumber;

signals:
    void removeClicked();
    void leftClicked();
    void rightClicked();
};

#endif // TASK_H
