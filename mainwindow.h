#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "taskdialog.h"

#include "taskmanagement.h"

namespace Ui {
class MainWindow;
}

namespace StackedIndex {
    const int SUMMARY = 0;
    const int KANBAN = 1;
    const int TIMELINE = 2;
    const int STATS = 3;
    const int NOTIFICATIONS = 4;
    const int SETTINGS = 5;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pBtn_Kanban_clicked();

    void on_pBtn_Summary_clicked();

    void on_pBtn_Timeline_clicked();

    void on_pBtn_Stats_clicked();

    void on_pBtn_Notifications_clicked();

    void on_pBtn_Settings_clicked();

    void on_pBtn_NightMode_clicked();

    void on_pBtn_TodoAdd_clicked();

    void on_pBtn_InProgressAdd_clicked();

    void on_pBtn_DoneAdd_clicked();

    void on_pBtn_TODO_clicked();

    void on_pBtn_AddFew_clicked();



private:
    Ui::MainWindow *ui;
    // icons:
    QIcon nightModeIconOn;
    QIcon nightModeIconOff;
    bool nightMode;
    // temp
    //TaskDialog taskDialog;
    TaskManagement *taskManagement;
};

#endif // MAINWINDOW_H
