/********************************************************************************
** Form generated from reading UI file 'loginviewmodel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINVIEWMODEL_H
#define UI_LOGINVIEWMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginViewModel
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *username;
    QHBoxLayout *horizontalLayout_15;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *enterButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *LoginViewModel)
    {
        if (LoginViewModel->objectName().isEmpty())
            LoginViewModel->setObjectName("LoginViewModel");
        LoginViewModel->resize(774, 511);
        verticalLayout_2 = new QVBoxLayout(LoginViewModel);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label = new QLabel(LoginViewModel);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_16->addWidget(label);


        verticalLayout_4->addLayout(horizontalLayout_16);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        username = new QLineEdit(LoginViewModel);
        username->setObjectName("username");

        horizontalLayout_14->addWidget(username);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        password = new QLineEdit(LoginViewModel);
        password->setObjectName("password");

        horizontalLayout_15->addWidget(password);


        verticalLayout_4->addLayout(horizontalLayout_15);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_6);

        enterButton = new QPushButton(LoginViewModel);
        enterButton->setObjectName("enterButton");

        horizontalLayout_18->addWidget(enterButton);

        cancelButton = new QPushButton(LoginViewModel);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_18->addWidget(cancelButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_18);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(LoginViewModel);

        QMetaObject::connectSlotsByName(LoginViewModel);
    } // setupUi

    void retranslateUi(QWidget *LoginViewModel)
    {
        LoginViewModel->setWindowTitle(QCoreApplication::translate("LoginViewModel", "Form", nullptr));
        label->setText(QCoreApplication::translate("LoginViewModel", "\320\222\321\205\320\276\320\264", nullptr));
        username->setText(QString());
        password->setText(QString());
        enterButton->setText(QCoreApplication::translate("LoginViewModel", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        cancelButton->setText(QCoreApplication::translate("LoginViewModel", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginViewModel: public Ui_LoginViewModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINVIEWMODEL_H
