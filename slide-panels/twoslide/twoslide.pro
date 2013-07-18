#-------------------------------------------------
#
# Project created by QtCreator 2013-07-18T11:19:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = twoSlide
TEMPLATE = app

DESTDIR     = build/bin
OBJECTS_DIR = build/obj
MOC_DIR     = build/moc
RCC_DIR     = build/rc
UI_DIR      = build/ui

INCLUDEPATH += \
            $$PWD/src \
            $$PWD/src/main \
            $$PWD/src/slidewidgets

DEPENDPATH += \
            $$PWD/src \
            $$PWD/src/main \
            $$PWD/src/slidewidgets


SOURCES += main.cpp\
        mainwindow.cpp \
    slidewidget.cpp \
    src/slidewidgets/slidetwo.cpp

HEADERS  += mainwindow.h \
    slidewidget.h \
    src/slidewidgets/slidetwo.h

FORMS    += mainwindow.ui \
    slidewidget.ui \
    src/slidewidgets/slidetwo.ui
