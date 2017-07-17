#-------------------------------------------------
#
# Project created by QtCreator 2017-07-09T09:52:06
#
#-------------------------------------------------

QT       += core gui multimedia sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SHUDU
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        welscr.cpp \
    playscr.cpp \
    calculate.cpp \
    diffdia.cpp \
    pausedia.cpp \
    finaldia.cpp \
    helptxt.cpp \
    sound.cpp \
    loginscr.cpp \
    regist.cpp

HEADERS += \
        welscr.h \
    playscr.h \
    diffdia.h \
    pausedia.h \
    finaldia.h \
    helptxt.h \
    sound.h \
    loginscr.h \
    regist.h

FORMS += \
        welscr.ui \
    playscr.ui \
    diffdia.ui \
    pausedia.ui \
    finaldia.ui \
    helptxt.ui \
    loginscr.ui \
    regist.ui

RESOURCES += \
    myimage.qrc \
    myicon.qrc \
    sound.qrc

RC_ICONS=icon.ico
