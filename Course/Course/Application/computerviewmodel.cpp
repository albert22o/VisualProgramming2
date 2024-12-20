#include "computerviewmodel.h"

ComputerViewModel::ComputerViewModel(Computer computer) {
    this->computer = computer;
}

void ComputerViewModel::StartTimer(int remainSeconds){

    remainTimeInSeconds = remainSeconds;

    timer = new QTimer();
    timer->start(1000);

    QObject::connect(timer, &QTimer::timeout, this, &ComputerViewModel::OnTimerTick);
}

void ComputerViewModel::StopTimer(){
    timer->stop();
    remainTimeInSeconds = 0;
}

void ComputerViewModel::SetComputerStatus(QString status){
    computer.Status = status;
}

void ComputerViewModel::OnTimerTick(){

    if (remainTimeInSeconds > 0) {
        remainTimeInSeconds--;
        emit timeUpdated(computer, remainTimeInSeconds);
    } else {
        emit timerStopped(computer, remainTimeInSeconds);
        timer->stop();
    }
}

Computer ComputerViewModel::GetComputer(){
    return computer;
}
