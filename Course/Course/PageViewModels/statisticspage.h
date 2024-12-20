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
    explicit StatisticsPage(QSqlDatabase& db, QWidget *parent = nullptr);
    ~StatisticsPage();

    void UpdateView();

private:
    int totalHoursPlayed;

    QChartView *chartView;
    Ui::StatisticsPage *ui;
    SessionsRepository repos;

    int GetPlayedMinutesFromDbByComputerRate(ComputerRate computerRate);

    void Setup();
    QPieSeries* CreateDiagramm();
    void InitGraphicsView();
};

#endif // STATISTICSPAGE_H
