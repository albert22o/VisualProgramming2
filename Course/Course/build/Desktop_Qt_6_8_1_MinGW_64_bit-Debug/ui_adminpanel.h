/********************************************************************************
** Form generated from reading UI file 'adminpanel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPANEL_H
#define UI_ADMINPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminPanel
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdminPanel)
    {
        if (AdminPanel->objectName().isEmpty())
            AdminPanel->setObjectName("AdminPanel");
        AdminPanel->resize(400, 300);
        centralWidget = new QWidget(AdminPanel);
        centralWidget->setObjectName("centralWidget");
        AdminPanel->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AdminPanel);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName("menu_5");
        AdminPanel->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AdminPanel);
        mainToolBar->setObjectName("mainToolBar");
        AdminPanel->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AdminPanel);
        statusBar->setObjectName("statusBar");
        AdminPanel->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_5->menuAction());

        retranslateUi(AdminPanel);

        QMetaObject::connectSlotsByName(AdminPanel);
    } // setupUi

    void retranslateUi(QMainWindow *AdminPanel)
    {
        AdminPanel->setWindowTitle(QCoreApplication::translate("AdminPanel", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\260\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200\320\260", nullptr));
        menu->setTitle(QCoreApplication::translate("AdminPanel", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217", nullptr));
        menu_2->setTitle(QCoreApplication::translate("AdminPanel", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        menu_3->setTitle(QCoreApplication::translate("AdminPanel", "\320\241\320\265\320\260\320\275\321\201\321\213", nullptr));
        menu_4->setTitle(QCoreApplication::translate("AdminPanel", "\320\236\321\202\321\207\320\265\321\202\321\213", nullptr));
        menu_5->setTitle(QCoreApplication::translate("AdminPanel", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminPanel: public Ui_AdminPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPANEL_H
