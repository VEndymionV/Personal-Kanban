#include <qstring.h>

static QString mywidget_style_light = QString(
            "MainWindow,QPushButton,QFrame#TASKFRAME,Task QLabel,QWidget#scrollAreaWidgetContents_3,QWidget#scrollAreaWidgetContents_4,QWidget#scrollAreaWidgetContents_6,QScrollBar{"                     \
            "    background-color: lightgray;"         \
            "    color: black;"         \
            "     border: 1px solid black;"         \
            "     border-radius: 4px;"         \
            "     padding: 2px;"         \
            "}"
);

static QString mywidget_style_dark = QString(

    "MainWindow,QPushButton,QFrame#TASKFRAME,Task QLabel,QWidget#scrollAreaWidgetContents_3,QWidget#scrollAreaWidgetContents_4,QWidget#scrollAreaWidgetContents_6,QScrollBar{"                     \
    "    background-color: dimgray;"         \
    "    color: lightgrey;"         \
    "     border: 1px solid lightgrey;"         \
    "     border-radius: 4px;"         \
    "     padding: 2px;"         \
    "}"


);
