#-------------------------------------------------
#
# Project created by QtCreator 2015-05-13T16:06:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencv_window_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += D:/opencv/include

LIBS += -L D:/opencv/x86/mingw/lib/libopencv_*.dll.a
