#-------------------------------------------------
#
# Project created by QtCreator 2015-05-20T09:42:51
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_ch3
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    colordetectorLab.cpp \
#    colordetector.cpp \
    colorDetection.cpp \
    colorDetectController.cpp


INCLUDEPATH += D:/opencv/include

LIBS += -L D:/opencv/x86/mingw/lib/libopencv_*.dll.a

HEADERS += \
    colordetectorLab.h \
#    colordetector.h \
    colorDetectController.h
