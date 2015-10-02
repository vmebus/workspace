#-------------------------------------------------
#
# Project created by QtCreator 2015-05-22T14:46:44
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_ch10
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
#   foreground.cpp \
    tracking.cpp #\
#    videoprocessing.cpp

HEADERS += \
    BGFGSegmentor.h \
    featuretracker.h \
    videoprocessor.h


INCLUDEPATH += D:/opencv/include

LIBS += -L D:/opencv/x86/mingw/lib/libopencv_*.dll.a
