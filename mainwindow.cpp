#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskdialog.h"
#include "task.h"
#include <QtCore>
#include <QWidget>
#include <iostream>
#include <fstream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QList>
#include "stylesheet.h"
#include <QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), nightModeIconOn(":/res/icons/switchON256n.png"), nightModeIconOff(":/res/icons/switchOFF256.png"),KanbanNI(":/res/icons/calendar256n.png"),TimelineNI(":/res/icons/tmeline256n.png"),
    StatsNI(":/res/icons/diagram256n.png"),SummaryNI(":/res/icons/summary256n.png"),NotificationsNI(":/res/icons/notification256n.png"),SettingsNI(":/res/icons/settings256n.png"),AddNI(":/res/icons/plus256n.png"),KanbanN(":/res/icons/calendar256.png"),TimelineN(":/res/icons/tmeline256.png"),
    StatsN(":/res/icons/diagram256.png"),SummaryN(":/res/icons/summary256.png"),NotificationsN(":/res/icons/notification256.png"),SettingsN(":/res/icons/settings256.png"),AddN(":/res/icons/plus256.png"),LeftNI(":/res/icons/arrowLn.png"),RightNI(":/res/icons/arrowRn.png"),
    nightMode(false)

{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(StackedIndex::KANBAN);
    setStyleSheet( mywidget_style_light );
    taskManagement = new TaskManagement(ui->centralVLayout_Todo, ui->centralVLayout_InProgress, ui->centralVLayout_Done,ui->calendar_Layout);
    //JsonManager jsonmanager(taskManagement->toDoTasks,taskManagement->inProgressTasks,taskManagement->doneTasks)

    //taskManagement->jsonManager.loadFromJsonFile(0,"toDoTasks.json");
    //taskManagement->jsonManager.loadFromJsonFile(1,"inProgressTasks.json");
    //taskManagement->jsonManager.loadFromJsonFile(2,"doneTasks.json");
    taskManagement->refreshLayouts();
//ui->calendar_Layout;

}

MainWindow::~MainWindow()
{
    taskManagement->jsonManager.saveToJsonFile();
    delete ui;
}

void MainWindow::on_pBtn_Kanban_clicked()
{
    ui->stackedWidget->setCurrentIndex(StackedIndex::KANBAN);
}

void MainWindow::on_pBtn_Summary_clicked()
{
    ui->stackedWidget->setCurrentIndex(StackedIndex::SUMMARY);
}

void MainWindow::on_pBtn_Timeline_clicked()
{
    ui->stackedWidget->setCurrentIndex(StackedIndex::TIMELINE);
}

void MainWindow::on_pBtn_Stats_clicked()
{
    ui->stackedWidget->setCurrentIndex(StackedIndex::STATS);
}

void MainWindow::on_pBtn_Notifications_clicked()
{
    ui->stackedWidget->setCurrentIndex(StackedIndex::NOTIFICATIONS);
}

void MainWindow::on_pBtn_Settings_clicked()
{
    ui->stackedWidget->setCurrentIndex(StackedIndex::SETTINGS);
}

 void MainWindow::on_pBtn_NightMode_clicked()
{
    nightMode = !nightMode;
    if(nightMode)
    {

        setStyleSheet("background-color:black;");
        ui->label_InProgress->setStyleSheet("background-color:black;"
                                             "color:white;");
        ui->label_Todo->setStyleSheet("background-color:black;"
                                             "color:white;");
        ui->label_Done->setStyleSheet("background-color:black;"
                                          "color:white;");

        ui->pBtn_Kanban->setIcon(KanbanNI);
        ui->pBtn_Kanban->setStyleSheet("background-color:black;"
                                       "color:white;");

        ui->pBtn_Stats->setIcon(StatsNI);
        ui->pBtn_Stats->setStyleSheet("background-color:black;"
                                       "color:white;");
        ui->pBtn_Summary->setIcon(SummaryNI);
        ui->pBtn_Summary->setStyleSheet("background-color:black;"
                                       "color:white;");
        ui->pBtn_Timeline->setIcon(TimelineNI);
        ui->pBtn_Timeline->setStyleSheet("background-color:black;"
                                       "color:white;");
        ui->pBtn_Notifications->setIcon(NotificationsNI);
        ui->pBtn_Notifications->setStyleSheet("background-color:black;"
                                       "color:white;");
        ui->pBtn_Settings->setIcon(SettingsNI);
        ui->pBtn_Settings->setStyleSheet("background-color:black;"
                                       "color:white;");
        ui->pBtn_DoneAdd->setIcon(AddNI);
        ui->pBtn_DoneAdd->setStyleSheet("background-color:black;"
                                       "color:white;");
        ui->pBtn_TodoAdd->setIcon(AddNI);
        ui->pBtn_TodoAdd->setStyleSheet("background-color:black;"
                                       "color:white;");
        ui->pBtn_InProgressAdd->setIcon(AddNI);
        ui->pBtn_InProgressAdd->setStyleSheet("background-color:black;"
                                       "color:white;");
        ui->line->setStyleSheet("color:white;"
                                "border: 1px solid white;");
        ui->line_2->setStyleSheet("color:white;"
                                "border: 1px solid white;");
        ui->line_3->setStyleSheet("color:white;"
                                "border: 1px solid white;");
        ui->line_4->setStyleSheet("color:white;"
                                "border: 1px solid white;");
        ui->scrollAreaWidgetContents_3->setStyleSheet("background-color:black;"
                                      "color:white;"
                                      "border: 1px solid white;");
        ui->scrollAreaWidgetContents_4->setStyleSheet("background-color:black;"
                                      "color:white;"
                                      "border: 1px solid white;");
        ui->scrollAreaWidgetContents_6->setStyleSheet("background-color:black;"
                                      "color:white;"
                                      "border: 1px solid white;");
        ui->scrollAreaWidgetContents_7->setStyleSheet("background-color:black;"
                                      "color:white;"
                                      "border: 1px solid white;");
        ui->pBtn_TODO->setStyleSheet("background-color:black;"
                                     "color:white;"
                                     "border: 1px solid white;"
                                        );
        ui->pBtn_AddFew->setStyleSheet("background-color:black;"
                                       "color:white;"
                                       "border: 1px solid white;");
       ui->calendarWidget->setStyleSheet("background-color:black;"
                                         "color:white;"
                                         "border: 1px solid white;");

     //Task::strzalks(LeftNI,RightNI);
//scrollAreaWidgetContents_7

        ui->pBtn_NightMode->setIcon(nightModeIconOn);

        //setStyleSheet( mywidget_style_dark );
    }
    else
    {
        ui->pBtn_NightMode->setIcon(nightModeIconOff);

        setStyleSheet("background-color:lightgray;");
        ui->label_InProgress->setStyleSheet("background-color:lightgray;"
                                             "color:black;");
        ui->label_Todo->setStyleSheet("background-color:lightgray;"
                                             "color:black;");
        ui->label_Done->setStyleSheet("background-color:lightgray;"
                                          "color:black;");

        ui->pBtn_Kanban->setIcon(KanbanN);
        ui->pBtn_Kanban->setStyleSheet("background-color:lightgray;"
                                       "color:black;");

        ui->pBtn_Stats->setIcon(StatsN);
        ui->pBtn_Stats->setStyleSheet("background-color:lightgray;"
                                       "color:black;");
        ui->pBtn_Summary->setIcon(SummaryN);
        ui->pBtn_Summary->setStyleSheet("background-color:lightgray;"
                                       "color:black;");
        ui->pBtn_Timeline->setIcon(TimelineN);
        ui->pBtn_Timeline->setStyleSheet("background-color:lightgray;"
                                       "color:black;");
        ui->pBtn_Notifications->setIcon(NotificationsN);
        ui->pBtn_Notifications->setStyleSheet("background-color:lightgray;"
                                       "color:black;");
        ui->pBtn_Settings->setIcon(SettingsN);
        ui->pBtn_Settings->setStyleSheet("background-color:lightgray;"
                                       "color:black;");
        ui->pBtn_DoneAdd->setIcon(AddN);
        ui->pBtn_DoneAdd->setStyleSheet("background-color:lightgray;"
                                       "color:black;");
        ui->pBtn_TodoAdd->setIcon(AddN);
        ui->pBtn_TodoAdd->setStyleSheet("background-color:lightgray;"
                                       "color:black;");
        ui->pBtn_InProgressAdd->setIcon(AddN);
        ui->pBtn_InProgressAdd->setStyleSheet("background-color:lightgray;"
                                       "color:black;");
        ui->line->setStyleSheet("color:black;"
                                );
        ui->line_2->setStyleSheet("color:black;"
                                );
        ui->line_3->setStyleSheet("color:black;"
                                );
        ui->line_4->setStyleSheet("color:black;"
                                );
        ui->scrollAreaWidgetContents_3->setStyleSheet("background-color:lightgray;"
                                      "color:black;"
                                      "border: 1px solid black;");
        ui->scrollAreaWidgetContents_4->setStyleSheet("background-color:lightgray;"
                                      "color:black;"
                                      "border: 1px solid black;");
        ui->scrollAreaWidgetContents_6->setStyleSheet("background-color:lightgray;"
                                      "color:black;"
                                      "border: 1px solid black;");
        ui->scrollAreaWidgetContents_7->setStyleSheet("background-color:lightgray;"
                                      "color:black;"
                                      "border: 1px solid black;");



        ui->pBtn_TODO->setStyleSheet("background-color:lightgray;"
                                     "color:black;"
                                     "border: 1px solid black;"
                                        );
        ui->pBtn_AddFew->setStyleSheet("background-color:lightgray;"
                                       "color:black;"
                                       "border: 1px solid black;");
       ui->calendarWidget->setStyleSheet("background-color:lightgray;"
                                         "color:black;"
                                         "border: 1px solid black;");

        //setStyleSheet( mywidget_style_light );


    }
}
//docelowo jedyne tworzenie zadania
void MainWindow::on_pBtn_TodoAdd_clicked() {

    taskManagement->addNewTask();
}

void MainWindow::on_pBtn_InProgressAdd_clicked()
{
//próbne wczytywanie

}

void MainWindow::on_pBtn_DoneAdd_clicked()
{
}

void MainWindow::on_pBtn_TODO_clicked()
{
    taskManagement->sortByName();
    qDebug() << "MainWindows: sortuj";
}

void MainWindow::on_pBtn_AddFew_clicked()
{
    taskManagement->addFewTasks();
}




void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
//    taskManagement->timelinemenager.cleanup(); //nic nie robi w sumie
    QString tmp=date.toString("ddd MMM d yyyy");
    qDebug()<<tmp;
    taskManagement->timelinemenager.readtimeline(tmp); //pkeeee
    taskManagement->refreshLayouts(true);
}
