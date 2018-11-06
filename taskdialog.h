#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QDateTimeEdit>

//class QDateTimeEdit;
//class QLabel;

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(QWidget *parent = nullptr);
    ~TaskDialog();

private slots:
    void on_buttonBox_accepted();

    void on_timeCheckBox_stateChanged(int arg1);

private:
    Ui::TaskDialog *ui;

    //QDateTimeEdit beginDateTimeEdit;
   // QDateTimeEdit endDateTimeEdit;
   // QLabel beginDateTimeEditLabel;
    //QLabel endDateTimeEditLabel;
    //QWidget *beginDateTimeEdit;
    //QLabel beginDateTimeEditLabel;
    //QWidget *endDateTimeEdit;
    //QLabel endDateTimeEditLabel;
    QDateEdit beginDateEdit;
    QDateTimeEdit beginDateTimeEdit;
    QDateEdit endDateEdit;
    QDateTimeEdit endDateTimeEdit;

    QDateTimeEdit *beginActualDateEdit;
    QDateTimeEdit *endActualDateEdit;


    //bool validate(QString name, QString description, );
};

#endif // TASKDIALOG_H
