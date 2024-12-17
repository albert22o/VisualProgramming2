/********************************************************************************
** Form generated from reading UI file 'announcementviewmodel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANNOUNCEMENTVIEWMODEL_H
#define UI_ANNOUNCEMENTVIEWMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnnouncementViewModel
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *image;
    QLabel *name;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *price;
    QLabel *label_5;
    QLabel *category;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *remove;
    QPushButton *edit;
    QPushButton *showDetails;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *AnnouncementViewModel)
    {
        if (AnnouncementViewModel->objectName().isEmpty())
            AnnouncementViewModel->setObjectName("AnnouncementViewModel");
        AnnouncementViewModel->resize(812, 645);
        verticalLayout_2 = new QVBoxLayout(AnnouncementViewModel);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        image = new QLabel(AnnouncementViewModel);
        image->setObjectName("image");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy);
        image->setStyleSheet(QString::fromUtf8(""));
        image->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(image);

        name = new QLabel(AnnouncementViewModel);
        name->setObjectName("name");
        name->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(name);

        verticalLayout_4->setStretch(0, 5);
        verticalLayout_4->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_3 = new QLabel(AnnouncementViewModel);
        label_3->setObjectName("label_3");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        price = new QLabel(AnnouncementViewModel);
        price->setObjectName("price");
        price->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, price);

        label_5 = new QLabel(AnnouncementViewModel);
        label_5->setObjectName("label_5");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        category = new QLabel(AnnouncementViewModel);
        category->setObjectName("category");
        category->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, category);


        verticalLayout->addLayout(formLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        remove = new QPushButton(AnnouncementViewModel);
        remove->setObjectName("remove");

        horizontalLayout->addWidget(remove);

        edit = new QPushButton(AnnouncementViewModel);
        edit->setObjectName("edit");

        horizontalLayout->addWidget(edit);

        showDetails = new QPushButton(AnnouncementViewModel);
        showDetails->setObjectName("showDetails");

        horizontalLayout->addWidget(showDetails);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(3, 3);
        horizontalLayout->setStretch(4, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 5);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        retranslateUi(AnnouncementViewModel);

        QMetaObject::connectSlotsByName(AnnouncementViewModel);
    } // setupUi

    void retranslateUi(QWidget *AnnouncementViewModel)
    {
        AnnouncementViewModel->setWindowTitle(QCoreApplication::translate("AnnouncementViewModel", "Form", nullptr));
        image->setText(QCoreApplication::translate("AnnouncementViewModel", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        name->setText(QCoreApplication::translate("AnnouncementViewModel", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\276\320\261\321\212\321\217\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("AnnouncementViewModel", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        price->setText(QCoreApplication::translate("AnnouncementViewModel", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("AnnouncementViewModel", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        category->setText(QCoreApplication::translate("AnnouncementViewModel", "TextLabel", nullptr));
        remove->setText(QCoreApplication::translate("AnnouncementViewModel", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\276\320\261\321\212\321\217\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        edit->setText(QCoreApplication::translate("AnnouncementViewModel", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\276\320\261\321\212\321\217\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        showDetails->setText(QCoreApplication::translate("AnnouncementViewModel", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\264\320\265\321\202\320\260\320\273\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnnouncementViewModel: public Ui_AnnouncementViewModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANNOUNCEMENTVIEWMODEL_H
