#include "mainwindow.h"
#include <QApplication>
#include <task.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    w.showFullScreen();
    w.resize(1200, 800);
    w.show();

    return a.exec();
}
