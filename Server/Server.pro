#-------------------------------------------------
#
# Project created by QtCreator 2015-12-08T19:28:40
#
#-------------------------------------------------

QT       += core gui
QT       +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    mythread.cpp

HEADERS  += dialog.h \
    mythread.h

FORMS    += dialog.ui
