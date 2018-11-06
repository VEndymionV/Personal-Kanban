#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), nightModeIconOn(":/res/icons/switchON256.png"), nightModeIconOff(":/res/icons/switchOFF256.png"),
    nightMode(false)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(StackedIndex::KANBAN);
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

void MainWindow::on_pBtn_TodoAdd_clicked() {
    taskDialog.exec();
}

void MainWindow::on_pBtn_InProgressAdd_clicked()
{

}

void MainWindow::on_pBtn_DoneAdd_clicked()
{

}
