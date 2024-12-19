#ifndef STATISTICSPAGE_H
#define STATISTICSPAGE_H

#include <QWidget>
#include <QPieSeries>
#include <QChartView>

namespace Ui {
class StatisticsPage;
}

class StatisticsPage : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsPage(QWidget *parent = nullptr);
    ~StatisticsPage();

private:
    QChartView *chartView;
    Ui::StatisticsPage *ui;

    QPieSeries* CreateDiagramm();
};

#endif // STATISTICSPAGE_H
