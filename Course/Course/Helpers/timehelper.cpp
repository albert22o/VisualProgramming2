#include "timehelper.h"

int TimeHelper::GetAllTimeInMinutes(Session session) {
    QString format = "dd.MM.yyyy/HH:mm";

    QDateTime dateTime1 = QDateTime::fromString(session.StartOfLease, format);
    QDateTime dateTime2 = QDateTime::fromString(session.EndOfLease, format);
    if (!dateTime1.isValid() || !dateTime2.isValid()) {
        return -1;
    }
    qint64 minutesDifference = dateTime1.msecsTo(dateTime2) / 60000;

    return minutesDifference;
}
