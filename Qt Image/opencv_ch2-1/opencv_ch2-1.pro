#-------------------------------------------------
#
# Project created by QtCreator 2015-05-13T19:22:59
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_ch2-1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH += D:/opencv/include

LIBS += -L D:/opencv/x86/mingw/lib/libopencv_*.dll.a
