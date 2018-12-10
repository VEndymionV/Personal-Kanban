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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), nightModeIconOn(":/res/icons/switchON256.png"), nightModeIconOff(":/res/icons/switchOFF256.png"),
    nightMode(false)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(StackedIndex::KANBAN);
    taskManagement = new TaskManagement(ui->centralVLayout_Todo, ui->centralVLayout_InProgress, ui->centralVLayout_Done);
/*
    //testowanie jsona- do wyjebania do innej klasy jak zacznie działać

    QJsonObject test2; //przykładowy task- potem będzie się to ściągać za pomocą np. taskmanager->todolayout->task.name czy cos
//    test2.contains("name"); //tworzymy typ danej w jsonie
//    test2.contains("priority");
//    test2.contains("description");
//    test2.contains("beginDate");
//    test2.contains("endDate");

    test2["name"]= "Zygmunt ";
    test2["priority"]=21;
    test2["description"]="Michauuuu";
    test2["beginDate"]="21.03.02";
    test2["endDate"]="21.04.03";

    QJsonObject test22;
//    test22.contains("name");
//    test22.contains("priority");
//    test22.contains("description");
//    test22.contains("beginDate");
//    test22.contains("endDate");

    test22["name"]= " SHEIL";
    test22["priority"]=1;
    test22["description"]="pkeeeeeeee";
    test22["beginDate"]="1.03.02";
    test22["endDate"]="21.04.3";

    //zapisywanie macierzom
    QJsonArray arr;
    arr.push_back(test2);
    arr.push_back(test22);
    QFile array("array.json");
    QJsonDocument arraydoc(arr);
    array.open(QFile::WriteOnly);
    array.write(arraydoc.toJson());
    array.close();
   // QByteArray bytearr=QJsonDocument().toBinaryData(arr);






        //zapisywanie jako pojedyńcze dokumenty- podobny efekt co macierz, ale mamy dwie osobne klamerki, nie opakowane w jedną
        //porównajcie dokumenty wynikowe
        QFile dupa("dupaa.json");
        dupa.open(QFile::WriteOnly);
        QJsonDocument test3(test2);
        QJsonDocument test33(test22);
        dupa.write(test3.toJson());
        dupa.write(test33.toJson());
        dupa.close();

        //odczytywanie- to nie dziala, nie moge sie dobrac do danej zmiennej np. "name"
        QFile dupaodczyt("dupaa.json");
        dupaodczyt.open(QFile::ReadOnly);
       QJsonDocument test4=QJsonDocument().fromJson(dupaodczyt.readAll()); //dokument typu json
        dupaodczyt.close();
        taskManagement->LoadTasks("dupaa.json");

         //to działa jak jest tylko jeden task



        QString name=test4["name"].toString();
        QString priority=test4["priority"].toString();
        QString description=test4["description"].toString();
        QString beginDate=test4["beginDate"].toString();
        QString endDate=test4["endDate"].toString();
        Task *A=new Task(name,description,priority,beginDate,endDate);
        taskManagement->addNew(A);




*/

}

MainWindow::~MainWindow()
{
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
    if(nightMode){
        ui->pBtn_NightMode->setIcon(nightModeIconOn);
    }
    else{
        ui->pBtn_NightMode->setIcon(nightModeIconOff);
    }

}

//docelowo jedyne tworzenie zadania
void MainWindow::on_pBtn_TodoAdd_clicked() {

    taskManagement->addNewTask();
}

void MainWindow::on_pBtn_InProgressAdd_clicked()
{

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
