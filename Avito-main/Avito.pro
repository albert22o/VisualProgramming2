QT       += core gui
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Application/announcementsearchsystem.cpp \
    Db/TableShemas/announcementshema.cpp \
    Db/TableShemas/basetableshema.cpp \
    Db/TableShemas/categoriesshema.cpp \
    Db/TableShemas/rolesshema.cpp \
    Db/TableShemas/usershema.cpp \
    Db/dbseeder.cpp \
    Domain/announcement.cpp \
    Domain/category.cpp \
    Domain/entity.cpp \
    Domain/user.cpp \
    Repositories/announcementrepository.cpp \
    Repositories/baserepository.cpp \
    Repositories/categoryrepository.cpp \
    Repositories/usersrepository.cpp \
    RoleManagment/rolemanager.cpp \
    Session/currentsession.cpp \
    ViewModels/announcementdetailsviewmodel.cpp \
    ViewModels/announcementviewmodel.cpp \
    ViewModels/createannouncementviewmodel.cpp \
    ViewModels/homepage.cpp \
    ViewModels/loginviewmodel.cpp \
    main.cpp \
    mainwindow.cpp \
    rolechangedtracker.cpp

HEADERS += \
    Application/announcementsearchsystem.h \
    Db/TableShemas/announcementshema.h \
    Db/TableShemas/basetableshema.h \
    Db/TableShemas/categoriesshema.h \
    Db/TableShemas/rolesshema.h \
    Db/TableShemas/usershema.h \
    Db/dbseeder.h \
    Domain/announcement.h \
    Domain/category.h \
    Domain/entity.h \
    Domain/user.h \
    Repositories/announcementrepository.h \
    Repositories/baserepository.h \
    Repositories/categoryrepository.h \
    Repositories/usersrepository.h \
    RoleManagment/rolemanager.h \
    RoleManagment/roles.h \
    Session/currentsession.h \
    ViewModels/announcementdetailsviewmodel.h \
    ViewModels/announcementviewmodel.h \
    ViewModels/createannouncementviewmodel.h \
    ViewModels/homepage.h \
    ViewModels/loginviewmodel.h \
    mainwindow.h \
    rolechangedtracker.h

FORMS += \
    ViewModels/announcementdetailsviewmodel.ui \
    ViewModels/announcementviewmodel.ui \
    ViewModels/createannouncementviewmodel.ui \
    ViewModels/homepage.ui \
    ViewModels/loginviewmodel.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
