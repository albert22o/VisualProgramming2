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
    void timerStopped(const Computer& comp, int newTimeInMinutes);
    void timeUpdated(const Computer& comp, int newTimeInMinutes);

private:
    int remainTimeInMinutes = 0;
    Computer computer;
    QTimer* timer;

    void OnTimerTick();
};

#endif // COMPUTERVIEWMODEL_H
