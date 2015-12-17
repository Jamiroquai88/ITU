#-------------------------------------------------
#
# Project created by QtCreator 2015-10-17T18:27:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ITU-Ray
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderedwindow.cpp \
    objects.cpp \
    settingsdialog.cpp

HEADERS  += mainwindow.h \
    renderedwindow.h \
    objects.h \
    settingsdialog.h

FORMS    += mainwindow.ui \
    renderedwindow.ui \
    settingsdialog.ui

OTHER_FILES += \
    new.jpg

RESOURCES += \
    render.qrc
