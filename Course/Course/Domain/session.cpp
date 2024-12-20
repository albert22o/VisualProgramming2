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

int Session::GetTimeDiffrenceInSeconds(QDateTime startTime){

    QString format = "dd.MM.yyyy/HH:mm:ss";

    QDateTime endOfLease = QDateTime::fromString(this->EndOfLease, format);

    if (!endOfLease.isValid()) {
        return -1;
    }

    qint64 secondsDifference = startTime.secsTo(endOfLease);

    return secondsDifference;
}

int Session::GetTimeDiffrenceInSeconds(){

    QString format = "dd.MM.yyyy/HH:mm:ss";

    QDateTime dateTime1 = QDateTime::fromString(this->StartOfLease, format);
    QDateTime dateTime2 = QDateTime::fromString(this->EndOfLease, format);

    if (!dateTime1.isValid() || !dateTime2.isValid()) {
        return -1;
    }

    qint64 secondsDifference = dateTime1.secsTo(dateTime2);

    return secondsDifference;
}
