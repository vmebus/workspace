#-------------------------------------------------
#
# Project created by QtCreator 2015-05-21T14:32:38
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_ch6
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    derivatives.cpp #\
#    filters.cpp


INCLUDEPATH += D:/opencv/include

LIBS += -L D:/opencv/x86/mingw/lib/libopencv_*.dll.a


HEADERS += \
    laplacianZC.h
