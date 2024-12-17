#include "rolechangedtracker.h"

#include "RoleManagment/rolemanager.h"
#include "Session/currentsession.h"

RoleChangedTracker::RoleChangedTracker() {

}

void RoleChangedTracker::AdaptAdminView(){

}

void RoleChangedTracker::AdaptUserView(const User& user){

}

void RoleChangedTracker::AdaptGuestView(){

}

void RoleChangedTracker::ReactOnRoleChanged(Role newRole){

    switch (newRole)
    {

    case Role::AdminRole:
        AdaptAdminView();
        break;

    case Role::UserRole:
        AdaptUserView(CurrentSession::GetInstance().GetUser());
        break;

    case Role::GuestRole:
        AdaptGuestView();
        break;

    }
}
