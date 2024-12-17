#ifndef USER_H
#define USER_H

#include "entity.h"

class User : public Entity
{
public:
    User();

    QString Name;
    QString Password;
    QString Phone;
    QString Login;

    int RoleId;
};

#endif // USER_H
