/********************************************************************************
** Form generated from reading UI file 'announcementdetailsviewmodel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANNOUNCEMENTDETAILSVIEWMODEL_H
#define UI_ANNOUNCEMENTDETAILSVIEWMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnnouncementDetailsViewModel
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *Contacts;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *notAuthorizedMessage;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *name;
    QSpacerItem *horizontalSpacer_3;
    QLabel *phoneLabel;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *phoneNumber;
    QSpacerItem *horizontalSpacer_4;
    QWidget *AnnouncementDetails;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout_4;
    QLabel *label_3;
    QLineEdit *announcementName;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *announcementDesc;
    QLabel *label_7;
    QLineEdit *announcementPrice;
    QLineEdit *category;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QLabel *image;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *back;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AnnouncementDetailsViewModel)
    {
        if (AnnouncementDetailsViewModel->objectName().isEmpty())
            AnnouncementDetailsViewModel->setObjectName("AnnouncementDetailsViewModel");
        AnnouncementDetailsViewModel->resize(833, 527);
        verticalLayout = new QVBoxLayout(AnnouncementDetailsViewModel);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(AnnouncementDetailsViewModel);
        tabWidget->setObjectName("tabWidget");
        Contacts = new QWidget();
        Contacts->setObjectName("Contacts");
        verticalLayout_3 = new QVBoxLayout(Contacts);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        notAuthorizedMessage = new QLabel(Contacts);
        notAuthorizedMessage->setObjectName("notAuthorizedMessage");
        notAuthorizedMessage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(notAuthorizedMessage);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        nameLabel = new QLabel(Contacts);
        nameLabel->setObjectName("nameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        name = new QLineEdit(Contacts);
        name->setObjectName("name");

        horizontalLayout_6->addWidget(name);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_6);

        phoneLabel = new QLabel(Contacts);
        phoneLabel->setObjectName("phoneLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, phoneLabel);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        phoneNumber = new QLineEdit(Contacts);
        phoneNumber->setObjectName("phoneNumber");

        horizontalLayout_7->addWidget(phoneNumber);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_7);


        verticalLayout_2->addLayout(formLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(Contacts, QString());
        AnnouncementDetails = new QWidget();
        AnnouncementDetails->setObjectName("AnnouncementDetails");
        horizontalLayout_2 = new QHBoxLayout(AnnouncementDetails);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        label_3 = new QLabel(AnnouncementDetails);
        label_3->setObjectName("label_3");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_3);

        announcementName = new QLineEdit(AnnouncementDetails);
        announcementName->setObjectName("announcementName");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, announcementName);

        label_4 = new QLabel(AnnouncementDetails);
        label_4->setObjectName("label_4");

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(AnnouncementDetails);
        label_5->setObjectName("label_5");

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_5);

        announcementDesc = new QTextEdit(AnnouncementDetails);
        announcementDesc->setObjectName("announcementDesc");
        announcementDesc->setLineWrapMode(QTextEdit::LineWrapMode::WidgetWidth);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, announcementDesc);

        label_7 = new QLabel(AnnouncementDetails);
        label_7->setObjectName("label_7");

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_7);

        announcementPrice = new QLineEdit(AnnouncementDetails);
        announcementPrice->setObjectName("announcementPrice");

        formLayout_4->setWidget(3, QFormLayout::FieldRole, announcementPrice);

        category = new QLineEdit(AnnouncementDetails);
        category->setObjectName("category");

        formLayout_4->setWidget(1, QFormLayout::FieldRole, category);


        horizontalLayout_3->addLayout(formLayout_4);

        horizontalSpacer = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        image = new QLabel(AnnouncementDetails);
        image->setObjectName("image");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy);
        image->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(image);

        verticalLayout_6->setStretch(0, 5);

        horizontalLayout_3->addLayout(verticalLayout_6);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(2, 1);

        horizontalLayout_2->addLayout(horizontalLayout_3);

        tabWidget->addTab(AnnouncementDetails, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        back = new QPushButton(AnnouncementDetailsViewModel);
        back->setObjectName("back");

        horizontalLayout_4->addWidget(back);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(announcementName, announcementPrice);
        QWidget::setTabOrder(announcementPrice, announcementDesc);

        retranslateUi(AnnouncementDetailsViewModel);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AnnouncementDetailsViewModel);
    } // setupUi

    void retranslateUi(QWidget *AnnouncementDetailsViewModel)
    {
        AnnouncementDetailsViewModel->setWindowTitle(QCoreApplication::translate("AnnouncementDetailsViewModel", "Form", nullptr));
        notAuthorizedMessage->setText(QCoreApplication::translate("AnnouncementDetailsViewModel", "\320\237\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260, \320\260\320\262\321\202\320\276\321\200\320\270\320\267\321\203\320\271\321\202\320\265\321\201\321\214 \321\207\321\202\320\276\320\261\321\213 \320\262\320\270\320\264\320\265\321\202\321\214 \320\272\320\276\320\275\321\202\320\260\320\272\321\202\321\213 \320\262\320\273\320\260\320\264\320\265\320\273\321\214\321\206\320\260 \320\276\320\261\321\212\321\217\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        nameLabel->setText(QCoreApplication::translate("AnnouncementDetailsViewModel", "\320\230\320\274\321\217 \320\262\320\273\320\260\320\264\320\265\320\273\321\214\321\206\320\260", nullptr));
        phoneLabel->setText(QCoreApplication::translate("AnnouncementDetailsViewModel", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Contacts), QCoreApplication::translate("AnnouncementDetailsViewModel", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("AnnouncementDetailsViewModel", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\276\320\261\321\212\321\217\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("AnnouncementDetailsViewModel", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("AnnouncementDetailsViewModel", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        label_7->setText(QCoreApplication::translate("AnnouncementDetailsViewModel", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        image->setText(QCoreApplication::translate("AnnouncementDetailsViewModel", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(AnnouncementDetails), QCoreApplication::translate("AnnouncementDetailsViewModel", "\320\232 \320\276\320\261\321\212\321\217\320\262\320\273\320\265\320\275\320\270\321\216", nullptr));
        back->setText(QCoreApplication::translate("AnnouncementDetailsViewModel", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\275\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnnouncementDetailsViewModel: public Ui_AnnouncementDetailsViewModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANNOUNCEMENTDETAILSVIEWMODEL_H
