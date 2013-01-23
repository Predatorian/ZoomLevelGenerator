#-------------------------------------------------
#
# Project created by QtCreator 2013-01-11T17:05:03
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ZoomLevelGenerator
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    fileorganizer.cpp \
    filehandler.cpp

OTHER_FILES += \
    README.md \
    COPYING

HEADERS += \
    fileorganizer.h \
    filehandler.h \
    structs.h

LIBS += -LC:\Qt\4.7.0\lib -lQtGui4




