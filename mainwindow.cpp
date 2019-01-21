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
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), nightModeIconOn(":/res/icons/switchON256.png"), nightModeIconOff(":/res/icons/switchOFF256.png"),
    nightMode(false)

{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(StackedIndex::KANBAN);
    setStyleSheet( mywidget_style_light );
    taskManagement = new TaskManagement(ui->centralVLayout_Todo, ui->centralVLayout_InProgress, ui->centralVLayout_Done);
    //JsonManager jsonmanager(taskManagement->toDoTasks,taskManagement->inProgressTasks,taskManagement->doneTasks)

    //taskManagement->jsonManager.loadFromJsonFile(0,"toDoTasks.json");
    //taskManagement->jsonManager.loadFromJsonFile(1,"inProgressTasks.json");
    //taskManagement->jsonManager.loadFromJsonFile(2,"doneTasks.json");
    taskManagement->refreshLayouts();

}

MainWindow::~MainWindow()
{
    taskManagement->jsonManager.saveToJsonFiles();
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
        ui->pBtn_NightMode->setIcon(nightModeIconOn);
        setStyleSheet( mywidget_style_dark );
    }
    else
    {
        ui->pBtn_NightMode->setIcon(nightModeIconOff);
        setStyleSheet( mywidget_style_light );
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

void MainWindow::on_pBtn_SaveToFile_clicked()
{
    QFileDialog fileDialog(this);
//    fileDialog.setNameFilter("All C++ files (*.cpp *.cc *.C *.cxx *.c++)");
//    fileDialog.setNameFilter("Pliki json (*.json)");
//    fileDialog.exec();
    fileDialog.setDefaultSuffix("json");
    QString fileName = fileDialog.getSaveFileName(this, "...");
//    QString fileName = QFileDialog::getSaveFileName(this, "Wybierz gdzie zapisać plik", "wtf??");
    qDebug() << fileName;
    taskManagement->jsonManager.saveToJsonFile(fileName);
}

void MainWindow::on_pBtn_LoadFromFile_clicked()
{
    QFileDialog fileDialog(this);

    fileDialog.setNameFilter("Pliki json (*.json)");
//    fileDialog.exec();
//    fileDialog.setDefaultSuffix("json");
    QString fileName = fileDialog.getOpenFileName(this, "Wskaż plik .json");
//    QString fileName = QFileDialog::getSaveFileName(this, "Wybierz gdzie zapisać plik", "wtf??");
    qDebug() << fileName;
    taskManagement->jsonManager.loadFromJsonFile(fileName);
    taskManagement->refreshLayouts();
}
