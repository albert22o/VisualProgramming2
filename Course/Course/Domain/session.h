#ifndef SESSION_H
#define SESSION_H

#include "entity.h"

#include <QString>

class Session : public Entity
{
public:
    Session();

    QString StartOfLease;
    QString EndOfLease;
    int UserId;
    int ComputerId;
};

#endif // SESSION_H
