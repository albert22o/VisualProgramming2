#include "statisticspage.h"
#include "ui_statisticspage.h"

#include <QPieSeries>
#include <QChart>
#include <QChartView>

StatisticsPage::StatisticsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatisticsPage)
{
    ui->setupUi(this);

    QPieSeries *series = new QPieSeries();
    series->append("Категория 1", 30);
    series->append("Категория 2", 20);
    series->append("Категория 3", 25);
    series->append("Категория 4", 15);
    series->append("Категория 5", 10);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Пример круговой диаграммы");
    chart->legend()->setVisible(true);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->graphicsView->setViewport(chartView);
}

StatisticsPage::~StatisticsPage()
{
    delete ui;
}
