#-------------------------------------------------
#
# Project created by QtCreator 2015-05-21T15:31:53
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_ch7
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += D:/opencv/include

LIBS += -L D:/opencv/x86/mingw/lib/libopencv_*.dll.a


SOURCES += \
#    blobs.cpp \
    contours.cpp

HEADERS += \
    edgedetector.h \
    linefinder.h
