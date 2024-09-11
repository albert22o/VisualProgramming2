/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAuthors;
    QAction *actionquit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *VL;
    QPushButton *Square;
    QPushButton *Rectangle;
    QPushButton *Rhombus;
    QPushButton *Trianlge;
    QPushButton *Trapezoid;
    QPushButton *Circle;
    QPushButton *Sector;
    QVBoxLayout *verticalLayout;
    QLabel *ParOneName;
    QLineEdit *ParOne;
    QLabel *ParTwoName;
    QLineEdit *ParTwo;
    QLabel *ParThreeName;
    QLineEdit *ParThree;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *Image;
    QLabel *answer;
    QPushButton *CalculateButton;
    QPushButton *ClearButton;
    QMenuBar *menuBar;
    QMenu *menuAuthors;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(731, 458);
        actionAuthors = new QAction(MainWindow);
        actionAuthors->setObjectName(QString::fromUtf8("actionAuthors"));
        actionquit = new QAction(MainWindow);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        VL = new QVBoxLayout();
        VL->setSpacing(6);
        VL->setObjectName(QString::fromUtf8("VL"));
        Square = new QPushButton(centralWidget);
        Square->setObjectName(QString::fromUtf8("Square"));

        VL->addWidget(Square);

        Rectangle = new QPushButton(centralWidget);
        Rectangle->setObjectName(QString::fromUtf8("Rectangle"));

        VL->addWidget(Rectangle);

        Rhombus = new QPushButton(centralWidget);
        Rhombus->setObjectName(QString::fromUtf8("Rhombus"));

        VL->addWidget(Rhombus);

        Trianlge = new QPushButton(centralWidget);
        Trianlge->setObjectName(QString::fromUtf8("Trianlge"));

        VL->addWidget(Trianlge);

        Trapezoid = new QPushButton(centralWidget);
        Trapezoid->setObjectName(QString::fromUtf8("Trapezoid"));

        VL->addWidget(Trapezoid);

        Circle = new QPushButton(centralWidget);
        Circle->setObjectName(QString::fromUtf8("Circle"));

        VL->addWidget(Circle);

        Sector = new QPushButton(centralWidget);
        Sector->setObjectName(QString::fromUtf8("Sector"));

        VL->addWidget(Sector);


        gridLayout->addLayout(VL, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ParOneName = new QLabel(centralWidget);
        ParOneName->setObjectName(QString::fromUtf8("ParOneName"));

        verticalLayout->addWidget(ParOneName);

        ParOne = new QLineEdit(centralWidget);
        ParOne->setObjectName(QString::fromUtf8("ParOne"));

        verticalLayout->addWidget(ParOne);

        ParTwoName = new QLabel(centralWidget);
        ParTwoName->setObjectName(QString::fromUtf8("ParTwoName"));

        verticalLayout->addWidget(ParTwoName);

        ParTwo = new QLineEdit(centralWidget);
        ParTwo->setObjectName(QString::fromUtf8("ParTwo"));

        verticalLayout->addWidget(ParTwo);

        ParThreeName = new QLabel(centralWidget);
        ParThreeName->setObjectName(QString::fromUtf8("ParThreeName"));

        verticalLayout->addWidget(ParThreeName);

        ParThree = new QLineEdit(centralWidget);
        ParThree->setObjectName(QString::fromUtf8("ParThree"));

        verticalLayout->addWidget(ParThree);

        horizontalSpacer = new QSpacerItem(50, 250, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Image = new QLabel(centralWidget);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setTextFormat(Qt::AutoText);
        Image->setPixmap(QPixmap(QString::fromUtf8(":/figure/img/rectangle.jfif")));
        Image->setScaledContents(false);
        Image->setWordWrap(false);
        Image->setOpenExternalLinks(false);

        verticalLayout_2->addWidget(Image);

        answer = new QLabel(centralWidget);
        answer->setObjectName(QString::fromUtf8("answer"));
        answer->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(answer);

        CalculateButton = new QPushButton(centralWidget);
        CalculateButton->setObjectName(QString::fromUtf8("CalculateButton"));

        verticalLayout_2->addWidget(CalculateButton);

        ClearButton = new QPushButton(centralWidget);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));

        verticalLayout_2->addWidget(ClearButton);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 21));
        menuBar->setNativeMenuBar(true);
        menuAuthors = new QMenu(menuBar);
        menuAuthors->setObjectName(QString::fromUtf8("menuAuthors"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuAuthors->menuAction());
        menuAuthors->addAction(actionAuthors);
        menuAuthors->addAction(actionquit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAuthors->setText(QApplication::translate("MainWindow", "Authors", nullptr));
        actionquit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        Square->setText(QApplication::translate("MainWindow", "Square", nullptr));
        Rectangle->setText(QApplication::translate("MainWindow", "Rectangle", nullptr));
        Rhombus->setText(QApplication::translate("MainWindow", "Rhombus", nullptr));
        Trianlge->setText(QApplication::translate("MainWindow", "Triangle", nullptr));
        Trapezoid->setText(QApplication::translate("MainWindow", "Trabezoid", nullptr));
        Circle->setText(QApplication::translate("MainWindow", "Circle", nullptr));
        Sector->setText(QApplication::translate("MainWindow", "Sector", nullptr));
        ParOneName->setText(QString());
        ParTwoName->setText(QString());
        ParThreeName->setText(QString());
        Image->setText(QString());
        answer->setText(QString());
        CalculateButton->setText(QApplication::translate("MainWindow", "Calculate", nullptr));
        ClearButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        menuAuthors->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
