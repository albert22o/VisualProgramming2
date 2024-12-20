#ifndef COMPUTERVIEWMODEL_H
#define COMPUTERVIEWMODEL_H

#include "Domain/computer.h"
#include <QTimer>

class ComputerViewModel : public QObject
{
    Q_OBJECT
public:
    ComputerViewModel(Computer computer);
    void StartTimer(int remainMinutes);

    Computer GetComputer();

signals:
    void timerStopped(const Computer& comp, int newTimeInSeconds);
    void timeUpdated(const Computer& comp, int newTimeInSeconds);

private:
    int remainTimeInSeconds = 0;
    Computer computer;
    QTimer* timer;

    void OnTimerTick();
};

#endif // COMPUTERVIEWMODEL_H
