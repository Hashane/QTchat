#-------------------------------------------------
#
# Project created by QtCreator 2015-12-06T20:32:54
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui


TARGET = multiServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp \
    mythread.cpp

HEADERS += \
    myserver.h \
    mythread.h
