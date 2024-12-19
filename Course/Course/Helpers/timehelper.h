#ifndef TIMEHELPER_H
#define TIMEHELPER_H

#include <QDateTime>

class TimeHelper
{
public:
    static QDateTime ParseDateTime(const QString& input);
};

#endif
