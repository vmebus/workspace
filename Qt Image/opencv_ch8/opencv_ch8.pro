#-------------------------------------------------
#
# Project created by QtCreator 2015-05-21T17:59:16
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_ch8
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
   interestPoints.cpp #\
 #   tracking.cpp

INCLUDEPATH += D:/opencv/include

LIBS += -L D:/opencv/x86/mingw/lib/libopencv_*.dll.a

HEADERS += \
    harrisDetector.h
