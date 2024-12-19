#include "session.h"

Session::Session() {}

Session::Session(int id, QString startTime, QString endTime, QString status, int userId, int computerId){

    Id = id;
    StartOfLease = startTime;
    EndOfLease = endTime;
    UserId = userId;
    ComputerId = computerId;
    Status = status;
}
int Session::GetAllTimeInMinutes(){
    QString format = "dd.MM.yyyy/HH:mm";

    QDateTime dateTime1 = QDateTime::fromString(this->StartOfLease, format);
    QDateTime dateTime2 = QDateTime::fromString(this->EndOfLease, format);
    if (!dateTime1.isValid() || !dateTime2.isValid()) {
        return -1;
    }
    qint64 minutesDifference = dateTime1.msecsTo(dateTime2) / 60000;

    return minutesDifference;
}
