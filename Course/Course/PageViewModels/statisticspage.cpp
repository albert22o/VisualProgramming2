#include "statisticspage.h"
#include "ui_statisticspage.h"

#include <QPieSeries>
#include <QChart>

#include "Database/TableShemas/computerrates.h"

StatisticsPage::StatisticsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatisticsPage)
{
    ui->setupUi(this);

    QPieSeries *series = new QPieSeries();

    auto gamingTariff = ComputerRateConverter::ParseRate(ComputerRate::gaming);
    auto standartTariff = ComputerRateConverter::ParseRate(ComputerRate::standart);
    auto officeTariff = ComputerRateConverter::ParseRate(ComputerRate::office);

    series->append(gamingTariff, 30);
    series->append(standartTariff, 20);
    series->append(officeTariff, 25);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Диаграмма наиграных часов");
    chart->legend()->setVisible(true);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(ui->graphicsView);
    layout->addWidget(chartView);
    ui->graphicsView->setLayout(layout);

    ui->graphicsView->setFrameShape(QFrame::NoFrame);
}

StatisticsPage::~StatisticsPage()
{
    delete ui;
}
