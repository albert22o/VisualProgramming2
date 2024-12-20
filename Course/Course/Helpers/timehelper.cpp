#include "timehelper.h"

QDateTime TimeHelper::ParseDateTime(const QString& input) {
    QStringList parts = input.split('/');
    if (parts.size() != 2)
        return QDateTime();
    
    QDate date = QDate::fromString(parts[0], "dd.MM.yyyy");
    QTime time = QTime::fromString(parts[1], "hh:mm:ss");
    
    if (!date.isValid() || !time.isValid())
        return QDateTime();
    
    return QDateTime(date, time);
}
