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

    QString format = "dd.MM.yyyy/HH:mm";

    QDateTime endOfLease = QDateTime::fromString(this->EndOfLease, format);

    if (!endOfLease.isValid()) {
        return -1;
    }

    qint64 secondsDifference = startTime.secsTo(endOfLease);

    return secondsDifference;
}

int Session::GetTimeDiffrenceInMinuters(QDateTime startTime){

    QString format = "dd.MM.yyyy/HH:mm";

    QDateTime endOfLease = QDateTime::fromString(this->EndOfLease, format);

    if (!endOfLease.isValid()) {
        return -1;
    }

    qint64 minutesDifference = startTime.msecsTo(endOfLease) / 60000;

    return minutesDifference;
}

int Session::GetTimeDiffrenceInMinuters()
{
    QString format = "dd.MM.yyyy/HH:mm";

    QDateTime dateTime1 = QDateTime::fromString(this->StartOfLease, format);
    QDateTime dateTime2 = QDateTime::fromString(this->EndOfLease, format);
    if (!dateTime1.isValid() || !dateTime2.isValid()) {
        return -1;
    }
    qint64 minutesDifference = dateTime1.msecsTo(dateTime2) / 60000;

    return minutesDifference;
}
