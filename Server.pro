#-------------------------------------------------
#
# Project created by QtCreator 2017-08-25T10:42:13
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp \
    mytcp.cpp

HEADERS  += server.h \
    mytcp.h

FORMS    += server.ui
