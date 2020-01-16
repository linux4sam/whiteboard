#-------------------------------------------------
#
# Project created by QtCreator 2018-04-02T10:10:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = whiteboard
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


SOURCES += main.cpp\
        mainwindow.cpp \
    whiteboard.cpp

HEADERS  += mainwindow.h \
    whiteboard.h

target.path = /opt/whiteboard
target.files = $$top_builddir/whiteboard
extra.path = /opt/whiteboard
extra.files = resources/whiteboard.sh
configfile.path = /opt/ApplicationLauncher/applications/xml
configfile.files = resources/12-whiteboard.xml
imagefile.path = /opt/ApplicationLauncher/applications/resources
imagefile.files = resources/whiteboard.png
INSTALLS += target configfile imagefile extra

RESOURCES += \
    media.qrc
