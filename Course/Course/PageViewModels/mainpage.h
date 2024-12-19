#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include "Application/computerviewmodel.h"

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_tableWidget_cellClicked(int row, int column);

    void on_startSession_clicked();

    void OnComputerLeaseTimeChanged(const Computer &computer, int updatedTime);
    void OnComputerLeaseFinished(const Computer &computer);

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::MainPage *ui;
    QMap<int, ComputerViewModel*> tableIdToComputer;
    int selectedRow;
    void Setup();
    void GetComputers();
    void CreateComputerTable();

    void ConnectWithComputerViewModel(ComputerViewModel* computerViewModel);

    QString ToDayHoursMinutesView(int minutes);
};

#endif // MAINPAGE_H
