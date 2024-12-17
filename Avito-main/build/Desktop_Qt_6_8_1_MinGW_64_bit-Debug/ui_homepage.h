/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *roleMessage;
    QPushButton *createAnnouncement;
    QPushButton *loginButton;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *categorySelector;
    QLineEdit *searchLine;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QGridLayout *catalog;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName("HomePage");
        HomePage->resize(722, 510);
        verticalLayout = new QVBoxLayout(HomePage);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(HomePage);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        roleMessage = new QLabel(HomePage);
        roleMessage->setObjectName("roleMessage");

        horizontalLayout->addWidget(roleMessage);

        createAnnouncement = new QPushButton(HomePage);
        createAnnouncement->setObjectName("createAnnouncement");

        horizontalLayout->addWidget(createAnnouncement);

        loginButton = new QPushButton(HomePage);
        loginButton->setObjectName("loginButton");

        horizontalLayout->addWidget(loginButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        categorySelector = new QComboBox(HomePage);
        categorySelector->setObjectName("categorySelector");

        horizontalLayout_2->addWidget(categorySelector);

        searchLine = new QLineEdit(HomePage);
        searchLine->setObjectName("searchLine");

        horizontalLayout_2->addWidget(searchLine);


        verticalLayout->addLayout(horizontalLayout_2);

        scrollArea = new QScrollArea(HomePage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 698, 411));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName("gridLayout_3");
        catalog = new QGridLayout();
        catalog->setObjectName("catalog");

        gridLayout_3->addLayout(catalog, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QWidget *HomePage)
    {
        HomePage->setWindowTitle(QCoreApplication::translate("HomePage", "Form", nullptr));
        label->setText(QCoreApplication::translate("HomePage", "Leverts", nullptr));
        roleMessage->setText(QCoreApplication::translate("HomePage", "\320\222\321\213 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\276\320\262\320\260\320\275\321\213 \320\272\320\260\320\272 \320\263\320\276\321\201\321\202\321\214", nullptr));
        createAnnouncement->setText(QCoreApplication::translate("HomePage", "\320\235\320\276\320\262\320\276\320\265 \320\276\320\261\321\212\321\217\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        loginButton->setText(QCoreApplication::translate("HomePage", "\320\222\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
