#include "computerviewmodel.h"

ComputerViewModel::ComputerViewModel(Computer computer) {
    this->computer = computer;
}

void ComputerViewModel::StartTimer(int remainMinutes){

    remainTimeInMinutes = remainMinutes;

    timer = new QTimer();
    timer->start(60000);

    QObject::connect(timer, &QTimer::timeout, this, &ComputerViewModel::OnTimerTick);
}

void ComputerViewModel::OnTimerTick(){

    if (remainTimeInMinutes > 0) {
        remainTimeInMinutes--;
        emit timeUpdated(computer, remainTimeInMinutes);
    } else {
        emit timerStopped(computer, remainTimeInMinutes);
        timer->stop();
    }
}

Computer ComputerViewModel::GetComputer(){
    return computer;
}
