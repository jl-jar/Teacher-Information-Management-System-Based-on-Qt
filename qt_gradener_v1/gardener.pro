#-------------------------------------------------
#
# Project created by QtCreator 2023-08-23T22:53:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gardener
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        course.cpp \
        dialogcourse.cpp \
        dialoggenderfilter.cpp \
        dialoglogin.cpp \
        dialogmarriagefilter.cpp \
        dialogsearch.cpp \
        dialogteacher.cpp \
        dialogtemp.cpp \
        main.cpp \
        mainwindow.cpp \
        teacher.cpp

HEADERS += \
        course.h \
        dialogcourse.h \
        dialoggenderfilter.h \
        dialoglogin.h \
        dialogmarriagefilter.h \
        dialogsearch.h \
        dialogteacher.h \
        dialogtemp.h \
        mainwindow.h \
        teacher.h

FORMS += \
        dialogcourse.ui \
        dialoggenderfilter.ui \
        dialoglogin.ui \
        dialogmarriagefilter.ui \
        dialogsearch.ui \
        dialogteacher.ui \
        dialogtemp.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc

DISTFILES +=

RC_ICONS = gardener.ico #添加图标
