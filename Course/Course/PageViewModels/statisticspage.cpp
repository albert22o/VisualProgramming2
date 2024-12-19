#include "statisticspage.h"
#include "ui_statisticspage.h"

#include <QChart>

#include "Database/TableShemas/computerrates.h"
#include "Helpers/timehelper.h"

StatisticsPage::StatisticsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatisticsPage)
{
    ui->setupUi(this);

    QChart *chart = new QChart();
    chart->addSeries(CreateDiagramm());
    chart->setTitle("Диаграмма наиграных часов");
    chart->legend()->setVisible(true);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(ui->graphicsView);
    layout->addWidget(chartView);
    ui->graphicsView->setLayout(layout);

    ui->graphicsView->setFrameShape(QFrame::NoFrame);
}

QPieSeries* StatisticsPage::CreateDiagramm(){

    auto series = new QPieSeries();

    auto gamingTariff = ComputerRateConverter::ParseRate(ComputerRate::gaming);
    auto standartTariff = ComputerRateConverter::ParseRate(ComputerRate::standart);
    auto officeTariff = ComputerRateConverter::ParseRate(ComputerRate::office);

    series->append(gamingTariff, 30);
    series->append(standartTariff, 20);
    series->append(officeTariff, 25);

    return series;
}

int StatisticsPage::GetPlayedMinutesFromDbByComputerRate(ComputerRate computerRate){

    auto sessions = repos.GetSessionsByComputerRate(computerRate, SessionStatus::Closed);
    int playedMinutes = 0;

    TimeHelper timeHelper;

    for(auto& session : sessions){
        playedMinutes += session.GetAllTimeInMinutes();
    }

    return playedMinutes;
}

StatisticsPage::~StatisticsPage()
{
    delete ui;
}
