#ifndef STATISTICSPAGE_H
#define STATISTICSPAGE_H

#include <QWidget>
#include <QPieSeries>
#include <QChartView>

#include "Database/TableShemas/computerrates.h"
#include "Repositories/sessionsrepository.h"

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
    SessionsRepository repos;

    int GetPlayedMinutesFromDbByComputerRate(ComputerRate computerRate);

    QPieSeries* CreateDiagramm();
};

#endif // STATISTICSPAGE_H
