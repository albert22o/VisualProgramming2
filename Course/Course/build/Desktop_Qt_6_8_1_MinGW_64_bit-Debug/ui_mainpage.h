/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *search;
    QPushButton *clearButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *tariff;
    QComboBox *status;
    QTableWidget *tableWidget;
    QLabel *sessionInfo;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startSession;
    QPushButton *endSession;

    void setupUi(QWidget *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName("MainPage");
        MainPage->resize(603, 445);
        verticalLayout_2 = new QVBoxLayout(MainPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        search = new QLineEdit(MainPage);
        search->setObjectName("search");

        horizontalLayout->addWidget(search);

        clearButton = new QPushButton(MainPage);
        clearButton->setObjectName("clearButton");

        horizontalLayout->addWidget(clearButton);

        groupBox = new QGroupBox(MainPage);
        groupBox->setObjectName("groupBox");
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        tariff = new QComboBox(groupBox);
        tariff->setObjectName("tariff");

        horizontalLayout_3->addWidget(tariff);

        status = new QComboBox(groupBox);
        status->setObjectName("status");

        horizontalLayout_3->addWidget(status);


        horizontalLayout->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(MainPage);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        sessionInfo = new QLabel(MainPage);
        sessionInfo->setObjectName("sessionInfo");

        verticalLayout->addWidget(sessionInfo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        startSession = new QPushButton(MainPage);
        startSession->setObjectName("startSession");

        horizontalLayout_2->addWidget(startSession);

        endSession = new QPushButton(MainPage);
        endSession->setObjectName("endSession");

        horizontalLayout_2->addWidget(endSession);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QWidget *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "Form", nullptr));
        clearButton->setText(QCoreApplication::translate("MainPage", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        groupBox->setTitle(QString());
        sessionInfo->setText(QCoreApplication::translate("MainPage", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \321\201\320\265\320\260\320\275\321\201\320\265:", nullptr));
        startSession->setText(QCoreApplication::translate("MainPage", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\201\320\265\320\260\320\275\321\201", nullptr));
        endSession->setText(QCoreApplication::translate("MainPage", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \321\201\320\265\320\260\320\275\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
