/********************************************************************************
** Form generated from reading UI file 'newseanswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSEANSWINDOW_H
#define UI_NEWSEANSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewSeansWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *computerInformation;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *currentTime;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QTimeEdit *duration;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *clue;
    QSpacerItem *horizontalSpacer;
    QPushButton *startSession;
    QPushButton *cancel;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *NewSeansWindow)
    {
        if (NewSeansWindow->objectName().isEmpty())
            NewSeansWindow->setObjectName("NewSeansWindow");
        NewSeansWindow->resize(400, 241);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::Computer));
        NewSeansWindow->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(NewSeansWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        computerInformation = new QLabel(NewSeansWindow);
        computerInformation->setObjectName("computerInformation");
        computerInformation->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(computerInformation);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        nameEdit = new QLineEdit(NewSeansWindow);
        nameEdit->setObjectName("nameEdit");

        horizontalLayout_4->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        passwordEdit = new QLineEdit(NewSeansWindow);
        passwordEdit->setObjectName("passwordEdit");

        horizontalLayout_3->addWidget(passwordEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(NewSeansWindow);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        currentTime = new QLineEdit(NewSeansWindow);
        currentTime->setObjectName("currentTime");
        currentTime->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_2->addWidget(currentTime);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(NewSeansWindow);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        duration = new QTimeEdit(NewSeansWindow);
        duration->setObjectName("duration");

        horizontalLayout->addWidget(duration);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        clue = new QLabel(NewSeansWindow);
        clue->setObjectName("clue");

        horizontalLayout_8->addWidget(clue);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        horizontalLayout_7->addLayout(horizontalLayout_8);

        startSession = new QPushButton(NewSeansWindow);
        startSession->setObjectName("startSession");

        horizontalLayout_7->addWidget(startSession);

        cancel = new QPushButton(NewSeansWindow);
        cancel->setObjectName("cancel");

        horizontalLayout_7->addWidget(cancel);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(NewSeansWindow);

        QMetaObject::connectSlotsByName(NewSeansWindow);
    } // setupUi

    void retranslateUi(QDialog *NewSeansWindow)
    {
        NewSeansWindow->setWindowTitle(QCoreApplication::translate("NewSeansWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\320\265\320\260\320\275\321\201", nullptr));
        computerInformation->setText(QCoreApplication::translate("NewSeansWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("NewSeansWindow", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\262\320\265\321\200\320\274\321\217 ", nullptr));
        label_2->setText(QCoreApplication::translate("NewSeansWindow", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        clue->setText(QString());
        startSession->setText(QCoreApplication::translate("NewSeansWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\201\320\265\320\260\320\275\321\201", nullptr));
        cancel->setText(QCoreApplication::translate("NewSeansWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewSeansWindow: public Ui_NewSeansWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSEANSWINDOW_H
