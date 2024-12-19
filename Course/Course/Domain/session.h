#ifndef SESSION_H
#define SESSION_H

#include "entity.h"

#include <QString>
#include <QDateTime>

class Session : public Entity
{
public:
    Session();
    Session(int id, QString startTime, QString endTime, QString status, int userId, int computerId);
    int GetTimeDiffrenceInMinuters();
    int GetTimeDiffrenceInSeconds(QDateTime startTime);
    int GetTimeDiffrenceInMinuters(QDateTime startTime);
    QString StartOfLease;
    QString EndOfLease;
    QString Status;
    int UserId;
    int ComputerId;
};

#endif // SESSION_H
