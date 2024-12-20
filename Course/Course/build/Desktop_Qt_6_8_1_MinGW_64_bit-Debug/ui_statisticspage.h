/********************************************************************************
** Form generated from reading UI file 'statisticspage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSPAGE_H
#define UI_STATISTICSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsPage
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *totalHoursPlayed;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *StatisticsPage)
    {
        if (StatisticsPage->objectName().isEmpty())
            StatisticsPage->setObjectName("StatisticsPage");
        StatisticsPage->resize(400, 300);
        gridLayout = new QGridLayout(StatisticsPage);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        totalHoursPlayed = new QLabel(StatisticsPage);
        totalHoursPlayed->setObjectName("totalHoursPlayed");

        horizontalLayout_2->addWidget(totalHoursPlayed);


        verticalLayout_3->addLayout(horizontalLayout_2);

        graphicsView = new QGraphicsView(StatisticsPage);
        graphicsView->setObjectName("graphicsView");

        verticalLayout_3->addWidget(graphicsView);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(StatisticsPage);

        QMetaObject::connectSlotsByName(StatisticsPage);
    } // setupUi

    void retranslateUi(QWidget *StatisticsPage)
    {
        StatisticsPage->setWindowTitle(QCoreApplication::translate("StatisticsPage", "Form", nullptr));
        totalHoursPlayed->setText(QCoreApplication::translate("StatisticsPage", "\320\236\320\261\321\211\320\265\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\275\320\260\320\270\320\263\321\200\320\260\320\275\320\275\321\213\321\205 \321\207\320\260\321\201\320\276\320\262:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsPage: public Ui_StatisticsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSPAGE_H
