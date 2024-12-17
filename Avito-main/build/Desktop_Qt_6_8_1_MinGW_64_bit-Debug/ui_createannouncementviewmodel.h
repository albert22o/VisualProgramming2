/********************************************************************************
** Form generated from reading UI file 'createannouncementviewmodel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEANNOUNCEMENTVIEWMODEL_H
#define UI_CREATEANNOUNCEMENTVIEWMODEL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateAnnouncementViewModel
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout_4;
    QLabel *label_3;
    QLineEdit *announcementName;
    QLabel *label_4;
    QComboBox *categorySelector;
    QLabel *label_5;
    QTextEdit *announcementDesc;
    QLabel *label_7;
    QLineEdit *announcementPrice;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QCommandLinkButton *addImage;
    QLabel *image;
    QLabel *imageName;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *createAnnouncement;
    QPushButton *closeAnnouncement;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CreateAnnouncementViewModel)
    {
        if (CreateAnnouncementViewModel->objectName().isEmpty())
            CreateAnnouncementViewModel->setObjectName("CreateAnnouncementViewModel");
        CreateAnnouncementViewModel->resize(695, 491);
        verticalLayout_2 = new QVBoxLayout(CreateAnnouncementViewModel);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        label_3 = new QLabel(CreateAnnouncementViewModel);
        label_3->setObjectName("label_3");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_3);

        announcementName = new QLineEdit(CreateAnnouncementViewModel);
        announcementName->setObjectName("announcementName");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, announcementName);

        label_4 = new QLabel(CreateAnnouncementViewModel);
        label_4->setObjectName("label_4");

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_4);

        categorySelector = new QComboBox(CreateAnnouncementViewModel);
        categorySelector->setObjectName("categorySelector");

        formLayout_4->setWidget(1, QFormLayout::FieldRole, categorySelector);

        label_5 = new QLabel(CreateAnnouncementViewModel);
        label_5->setObjectName("label_5");

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_5);

        announcementDesc = new QTextEdit(CreateAnnouncementViewModel);
        announcementDesc->setObjectName("announcementDesc");
        announcementDesc->setLineWrapMode(QTextEdit::LineWrapMode::WidgetWidth);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, announcementDesc);

        label_7 = new QLabel(CreateAnnouncementViewModel);
        label_7->setObjectName("label_7");

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_7);

        announcementPrice = new QLineEdit(CreateAnnouncementViewModel);
        announcementPrice->setObjectName("announcementPrice");

        formLayout_4->setWidget(3, QFormLayout::FieldRole, announcementPrice);


        horizontalLayout_3->addLayout(formLayout_4);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label = new QLabel(CreateAnnouncementViewModel);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(label);

        addImage = new QCommandLinkButton(CreateAnnouncementViewModel);
        addImage->setObjectName("addImage");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        addImage->setIcon(icon);

        horizontalLayout_5->addWidget(addImage);


        verticalLayout_6->addLayout(horizontalLayout_5);

        image = new QLabel(CreateAnnouncementViewModel);
        image->setObjectName("image");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy);
        image->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(image);

        imageName = new QLabel(CreateAnnouncementViewModel);
        imageName->setObjectName("imageName");
        imageName->setLineWidth(1);
        imageName->setTextFormat(Qt::TextFormat::RichText);
        imageName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(imageName);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        createAnnouncement = new QPushButton(CreateAnnouncementViewModel);
        createAnnouncement->setObjectName("createAnnouncement");

        horizontalLayout_8->addWidget(createAnnouncement);

        closeAnnouncement = new QPushButton(CreateAnnouncementViewModel);
        closeAnnouncement->setObjectName("closeAnnouncement");

        horizontalLayout_8->addWidget(closeAnnouncement);

        cancelButton = new QPushButton(CreateAnnouncementViewModel);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_8->addWidget(cancelButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout_6->addLayout(horizontalLayout_8);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 5);

        horizontalLayout_3->addLayout(verticalLayout_6);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(2, 1);

        horizontalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(CreateAnnouncementViewModel);

        QMetaObject::connectSlotsByName(CreateAnnouncementViewModel);
    } // setupUi

    void retranslateUi(QWidget *CreateAnnouncementViewModel)
    {
        CreateAnnouncementViewModel->setWindowTitle(QCoreApplication::translate("CreateAnnouncementViewModel", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("CreateAnnouncementViewModel", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\276\320\261\321\212\321\217\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("CreateAnnouncementViewModel", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216", nullptr));
        label_5->setText(QCoreApplication::translate("CreateAnnouncementViewModel", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        label_7->setText(QCoreApplication::translate("CreateAnnouncementViewModel", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("CreateAnnouncementViewModel", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        addImage->setText(QString());
        image->setText(QCoreApplication::translate("CreateAnnouncementViewModel", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        imageName->setText(QCoreApplication::translate("CreateAnnouncementViewModel", "TextLabel", nullptr));
        createAnnouncement->setText(QCoreApplication::translate("CreateAnnouncementViewModel", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\276\320\261\321\212\321\217\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        closeAnnouncement->setText(QCoreApplication::translate("CreateAnnouncementViewModel", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\276\320\261\321\212\321\217\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        cancelButton->setText(QCoreApplication::translate("CreateAnnouncementViewModel", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateAnnouncementViewModel: public Ui_CreateAnnouncementViewModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEANNOUNCEMENTVIEWMODEL_H
