/********************************************************************************
** Form generated from reading UI file 'registrationpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONPAGE_H
#define UI_REGISTRATIONPAGE_H

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

class Ui_RegistrationPage
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *nameValidationClue;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *passwordValidationClue;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *submitPassword;
    QHBoxLayout *horizontalLayout_8;
    QLabel *submitPasswordValidationClue;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addUserButton;
    QPushButton *clearFields;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *RegistrationPage)
    {
        if (RegistrationPage->objectName().isEmpty())
            RegistrationPage->setObjectName("RegistrationPage");
        RegistrationPage->resize(904, 551);
        verticalLayout_2 = new QVBoxLayout(RegistrationPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        nameEdit = new QLineEdit(RegistrationPage);
        nameEdit->setObjectName("nameEdit");

        horizontalLayout->addWidget(nameEdit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        nameValidationClue = new QLabel(RegistrationPage);
        nameValidationClue->setObjectName("nameValidationClue");

        horizontalLayout_5->addWidget(nameValidationClue);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        horizontalLayout->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        passwordEdit = new QLineEdit(RegistrationPage);
        passwordEdit->setObjectName("passwordEdit");

        horizontalLayout_2->addWidget(passwordEdit);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        passwordValidationClue = new QLabel(RegistrationPage);
        passwordValidationClue->setObjectName("passwordValidationClue");

        horizontalLayout_6->addWidget(passwordValidationClue);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        horizontalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        submitPassword = new QLineEdit(RegistrationPage);
        submitPassword->setObjectName("submitPassword");

        horizontalLayout_4->addWidget(submitPassword);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        submitPasswordValidationClue = new QLabel(RegistrationPage);
        submitPasswordValidationClue->setObjectName("submitPasswordValidationClue");

        horizontalLayout_8->addWidget(submitPasswordValidationClue);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        horizontalLayout_4->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        addUserButton = new QPushButton(RegistrationPage);
        addUserButton->setObjectName("addUserButton");

        horizontalLayout_3->addWidget(addUserButton);

        clearFields = new QPushButton(RegistrationPage);
        clearFields->setObjectName("clearFields");

        horizontalLayout_3->addWidget(clearFields);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(RegistrationPage);

        QMetaObject::connectSlotsByName(RegistrationPage);
    } // setupUi

    void retranslateUi(QWidget *RegistrationPage)
    {
        RegistrationPage->setWindowTitle(QCoreApplication::translate("RegistrationPage", "Form", nullptr));
        nameValidationClue->setText(QString());
        passwordValidationClue->setText(QString());
        submitPasswordValidationClue->setText(QString());
        addUserButton->setText(QCoreApplication::translate("RegistrationPage", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\320\276\320\263\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        clearFields->setText(QCoreApplication::translate("RegistrationPage", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\262\321\201\320\265 \320\277\320\276\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationPage: public Ui_RegistrationPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONPAGE_H
