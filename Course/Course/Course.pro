#-------------------------------------------------
#
# Project created by QtCreator 2024-12-10T15:35:18
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Course
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
        Database/TableShemas/basetableshema.cpp \
        Database/TableShemas/closedsessionsshema.cpp \
        Database/TableShemas/computershema.cpp \
        Database/TableShemas/computerstatuses.cpp \
        Database/TableShemas/sessionshema.cpp \
        Database/TableShemas/usershema.cpp \
        Database/dbseeder.cpp \
        Domain/computer.cpp \
        Domain/entity.cpp \
        Domain/session.cpp \
        Domain/user.cpp \
        Repositories/baserepository.cpp \
        Repositories/computersrepository.cpp \
        Repositories/usersrepository.cpp \
        main.cpp \
        adminpanel.cpp

HEADERS += \
        Database/TableShemas/basetableshema.h \
        Database/TableShemas/closedsessionsshema.h \
        Database/TableShemas/computershema.h \
        Database/TableShemas/computerstatuses.h \
        Database/TableShemas/sessionshema.h \
        Database/TableShemas/usershema.h \
        Database/dbseeder.h \
        Domain/computer.h \
        Domain/entity.h \
        Domain/session.h \
        Domain/user.h \
        Repositories/baserepository.h \
        Repositories/computersrepository.h \
        Repositories/usersrepository.h \
        adminpanel.h

FORMS += \
        adminpanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
