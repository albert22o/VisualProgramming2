/********************************************************************************
** Form generated from reading UI file 'sessionshistorypage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SESSIONSHISTORYPAGE_H
#define UI_SESSIONSHISTORYPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SessionsHistoryPage
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QWidget *SessionsHistoryPage)
    {
        if (SessionsHistoryPage->objectName().isEmpty())
            SessionsHistoryPage->setObjectName("SessionsHistoryPage");
        SessionsHistoryPage->resize(821, 511);
        verticalLayout = new QVBoxLayout(SessionsHistoryPage);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(SessionsHistoryPage);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);


        retranslateUi(SessionsHistoryPage);

        QMetaObject::connectSlotsByName(SessionsHistoryPage);
    } // setupUi

    void retranslateUi(QWidget *SessionsHistoryPage)
    {
        SessionsHistoryPage->setWindowTitle(QCoreApplication::translate("SessionsHistoryPage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SessionsHistoryPage: public Ui_SessionsHistoryPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SESSIONSHISTORYPAGE_H
