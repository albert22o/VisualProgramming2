#ifndef TIMEHELPER_H
#define TIMEHELPER_H

#include "Domain/session.h"
#include <QDateTime>
class TimeHelper
{
public:
    static int GetAllTimeInMinutes(Session session);
};

#endif
