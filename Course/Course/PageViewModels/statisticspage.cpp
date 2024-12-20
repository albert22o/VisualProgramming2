#include "statisticspage.h"
#include "ui_statisticspage.h"

#include <QChart>

#include "Database/TableShemas/computerrates.h"

StatisticsPage::StatisticsPage(QSqlDatabase& db, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatisticsPage),
    repos(db)

{
    ui->setupUi(this);

    Setup();
}

void StatisticsPage::UpdateView(){

    QChart *chart = new QChart();
    chart->addSeries(CreateDiagramm());
    chart->setTitle("Диаграмма наиграных часов");
    chart->legend()->setVisible(true);

    chartView->setChart(chart);
    chartView->update();

    ui->totalHoursPlayed->setText("Общее количество наигранных минут: " + QString::number(totalHoursPlayed));
}

void StatisticsPage::Setup(){

    InitGraphicsView();

    ui->totalHoursPlayed->setText("Общее количество наигранных минут: " + QString::number(totalHoursPlayed));
}

void StatisticsPage::InitGraphicsView(){

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

    int gamingTariffPlayed = GetPlayedMinutesFromDbByComputerRate(ComputerRate::gaming);
    int standartTariffPlayed = GetPlayedMinutesFromDbByComputerRate(ComputerRate::standart);
    int officeTariffPlayed = GetPlayedMinutesFromDbByComputerRate(ComputerRate::office);

    totalHoursPlayed = gamingTariffPlayed + standartTariffPlayed + officeTariffPlayed;

    series->append(gamingTariff, gamingTariffPlayed);
    series->append(standartTariff, standartTariffPlayed);
    series->append(officeTariff, officeTariffPlayed);

    series->setLabelsVisible(true);

    for (const auto& slice : series->slices()) {
        slice->setLabel(QString("%1: %2 мин").arg(slice->label()).arg(slice->value()));
    }

    return series;
}

int StatisticsPage::GetPlayedMinutesFromDbByComputerRate(ComputerRate computerRate){

    auto sessions = repos.GetSessionsByComputerRate(computerRate, SessionStatus::Closed);
    int playedMinutes = 0;

    for(auto& session : sessions){
        playedMinutes += session.GetTimeDiffrenceInMinuters();
    }

    return playedMinutes;
}

StatisticsPage::~StatisticsPage()
{
    delete ui;
}
