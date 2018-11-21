#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskdialog.h"
#include "task.h"
#include <QWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), nightModeIconOn(":/res/icons/switchON256.png"), nightModeIconOff(":/res/icons/switchOFF256.png"),
    nightMode(false)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(StackedIndex::KANBAN);
    taskManagement = new TaskManagement(ui->centralVLayout_Todo, ui->centralVLayout_InProgress, ui->centralVLayout_Done);
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
    TaskDialog taskDialog;
    taskDialog.exec();
    if(!taskDialog.getState()){
        return;
    }
    //pobieranie danych do konstruktora taska
    QString temp=taskDialog.getname();
    QString temp2=taskDialog.gettaskDesciption();
    QString temp3=taskDialog.gettaskPriority();
    QString temp4=taskDialog.gettaskBeginDate();
    QString temp5=taskDialog.gettaskEndDate();

    taskManagement->addNewTask(temp, temp2, temp3, temp4, temp5);
    /*
    Task *task=new Task(nullptr,temp,temp2,temp3,temp4,temp5);
    ui->centralVLayout_Todo->insertWidget(0,task);
    //klasa glowna que
    //que to do
    //que done
    //lista dwukierunkowa
   // ui->centralVLayout_Todo->removeWidget()


    */
}

void MainWindow::on_pBtn_InProgressAdd_clicked()
{

}

//do testowania taska, wywalić potem
void MainWindow::on_pBtn_DoneAdd_clicked()
{
    Task *G=new Task;
    Task *H=new Task;
    Task *K=new Task;
   //ui->centralVLayout_Todo->addWidget(G);
    ui->centralVLayout_Todo->insertWidget(0,G);
    ui->centralVLayout_InProgress->insertWidget(0,H);
    ui->centralVLayout_Done->insertWidget(0,K)
;
}
