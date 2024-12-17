#ifndef USER_H
#define USER_H

#include "entity.h"

#include <QString>

class User : public Entity
{
public:
    User();
    User(int id, QString login, QString password);

    QString Login;
    QString Password;
};

#endif // USER_H
