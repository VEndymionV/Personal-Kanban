#include "taskdialog.h"
#include "ui_taskdialog.h"
#include <QDebug>
#include <QDateEdit>
#include <QDateTimeEdit>

TaskDialog::TaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);
    /*
    // TODO Tymczasowo tak robię
    //
    beginDateTimeEditLabel.setText(ui->beginDateLabel->text());
    endDateTimeEditLabel.setText(ui->endDateLabel->text());
    // Usuwam
    ui->formLayout->removeRow(4);
    ui->formLayout->removeRow(3);
    //
    beginDateTimeEdit = new QDateEdit();
    endDateTimeEdit = new QDateEdit();
    //
    ui->formLayout->insertRow(3, &beginDateTimeEditLabel, beginDateTimeEdit);
    ui->formLayout->insertRow(4, &endDateTimeEditLabel, endDateTimeEdit);
    */
    //
    beginActualDateEdit = &beginDateEdit;
    endActualDateEdit = &endDateEdit;
    ui->formLayout->setWidget(3, QFormLayout::FieldRole, beginActualDateEdit);
    ui->formLayout->setWidget(4, QFormLayout::FieldRole, endActualDateEdit);

}

TaskDialog::~TaskDialog()
{
    delete ui;
}

void TaskDialog::on_buttonBox_accepted()
{
    qDebug() << "accepted!";
    qDebug() << ui->nameEdit->text();
    //qDebug() << ui->descriptionEdit->text();
    qDebug() << ui->priorityEdit->text();
    //qDebug() << ui->beginDateEdit->text();
    //delete ui->beginDateEdit;
    //ui->formLayout->insertRow(3, ui->beginDateLabel, new QDateTimeEdit());
   // qDebug() << ui->endDateEdit->text();
    qDebug() << ui->rememberCheckBox->isChecked();

    if(ui->rememberCheckBox->isChecked()){

    }
    else{
        ui->nameEdit->clear();
        ui->descriptionEdit->clear();
        ui->priorityEdit->clear();
        beginDateEdit.clear();
        beginDateTimeEdit.clear();
        endDateEdit.clear();
        endDateTimeEdit.clear();
    }
    this->accept();
    //this->hide();
}

void TaskDialog::on_timeCheckBox_stateChanged(int state) {

    QDateTimeEdit *replacementB, *replacementE;
    if(state){
        beginActualDateEdit = &beginDateEdit;
        replacementB = &beginDateTimeEdit;
        endActualDateEdit = &endDateEdit;
        replacementE = &endDateTimeEdit;
    }
    else{
        beginActualDateEdit = &beginDateTimeEdit;
        replacementB = &beginDateEdit;
        endActualDateEdit = &endDateTimeEdit;
        replacementE = &endDateEdit;
    }
    // Kopia danych
    replacementB->setDate(beginActualDateEdit->date());
    replacementE->setDate(endActualDateEdit->date());
    // Podmiana widgetów
    ui->formLayout->replaceWidget(beginActualDateEdit, replacementB);
    ui->formLayout->replaceWidget(endActualDateEdit, replacementE);
    // Ukrycie starych widgetów oraz pokazanie nowych
    beginActualDateEdit->hide();
    endActualDateEdit->hide();
    replacementB->show();
    replacementE->show();
    // Ustawienie wskaźników
    beginActualDateEdit = replacementB;
    endActualDateEdit = replacementE;
/*
    if(state){
        // Kopia danych
        beginDateTimeEdit.setDate(beginDateEdit.date());
        endDateTimeEdit.setDate(endDateEdit.date());
        // Podmiana widgetu
        ui->formLayout->replaceWidget(&beginDateEdit, &beginDateTimeEdit);
        beginDateEdit.hide();
        beginDateTimeEdit.show();

        ui->formLayout->replaceWidget(&endDateEdit, &endDateTimeEdit);
        endDateEdit.hide();
        endDateTimeEdit.show();
    }
    else{
        // Kopia danych
        beginDateEdit.setDate(beginDateTimeEdit.date());
        endDateEdit.setDate(endDateTimeEdit.date());

        ui->formLayout->replaceWidget(&beginDateTimeEdit, &beginDateEdit);
        beginDateTimeEdit.hide();
        beginDateEdit.show();

        ui->formLayout->replaceWidget(&endDateTimeEdit, &endDateEdit);
        endDateTimeEdit.hide();
        endDateEdit.show();
    }
    */
    /*
    // TODO pozycja zmiany daty jest tutaj ustawiona na sztywno, w przypadku zmiany kolejności będzie problem
    if(state){
        beginDateTimeEditLabel.setText(ui->beginDateLabel->text());
        beginDateTimeEdit.setDate(ui->beginDateEdit->date());

        endDateTimeEditLabel.setText(ui->endDateLabel->text());
        endDateTimeEdit.setDate(ui->endDateEdit->date());

        ui->beginDateLabel->hide();
        ui->beginDateEdit->hide();

        ui->endDateLabel->hide();
        ui->endDateEdit->hide();

        ui->formLayout->removeRow(4);
        ui->formLayout->removeRow(3);

        ui->formLayout->insertRow(3, &beginDateTimeEditLabel, &beginDateTimeEdit);
        ui->formLayout->insertRow(4, &endDateTimeEditLabel, &endDateTimeEdit);

        beginDateTimeEditLabel.show();
        beginDateTimeEdit.show();

        endDateTimeEditLabel.show();
        endDateTimeEdit.show();
    }
    else{
        qDebug() << ui->beginDateLabel->text();
//        ui->beginDateLabel->setText(beginDateTimeEditLabel.text());
//        ui->beginDateEdit->setDate(beginDateTimeEdit.date());

//        ui->endDateLabel->setText(endDateTimeEditLabel.text());
//        ui->endDateEdit->setDate(endDateTimeEdit.date());

        beginDateTimeEditLabel.hide();
        beginDateTimeEdit.hide();

        endDateTimeEditLabel.hide();
        endDateTimeEdit.hide();

        ui->formLayout->removeRow(4);
        ui->formLayout->removeRow(3);

        ui->formLayout->insertRow(3, ui->beginDateLabel, ui->beginDateEdit);
        ui->formLayout->insertRow(4, ui->endDateEdit, ui->endDateEdit);

        ui->beginDateLabel->show();
        ui->beginDateEdit->show();

        ui->endDateLabel->show();
        ui->endDateEdit->show();

    }
*/
}
