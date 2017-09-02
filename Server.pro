#-------------------------------------------------
#
# Project created by QtCreator 2017-08-25T10:42:13
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp \
    mytcp.cpp \
    control.cpp \
    type.cpp \
    room.cpp \
    light_control.cpp \
    floor.cpp

HEADERS  += server.h \
    mytcp.h \
    control.h \
    type.h \
    room.h \
    light_control.h \
    floor.h

FORMS    += server.ui \
    control.ui \
    type.ui \
    room.ui \
    light_control.ui \
    floor.ui
