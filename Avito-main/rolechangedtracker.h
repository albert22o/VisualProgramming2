#ifndef ROLECHANGEDTRACKER_H
#define ROLECHANGEDTRACKER_H

#include "RoleManagment/roles.h"
#include "Domain/user.h"
#include <QObject>

class RoleChangedTracker
{
public:
    RoleChangedTracker();

protected:
    virtual void ReactOnRoleChanged(Role newRole);

    virtual void AdaptAdminView();
    virtual void AdaptUserView(const User& user);
    virtual void AdaptGuestView();

    virtual void ConnectWithRoleManager() = 0;

};

#endif // ROLECHANGEDTRACKER_H
