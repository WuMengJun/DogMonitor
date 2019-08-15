#-------------------------------------------------
#
# Project created by QtCreator 2019-07-19T16:56:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestDogMonitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    systemdevicemonitor.cpp

HEADERS  += mainwindow.h \
    systemdevicemonitor.h

FORMS    += mainwindow.ui
