#include "rolemanager.h"

RoleManager& RoleManager::GetInstance(){
    static RoleManager instance;
    return instance;
}

void RoleManager::SetRole(Role newRole){

    if (role != newRole) {
        role = newRole;
        emit roleChanged(role);
    }
}

void RoleManager::SetRole(int roleId){

    switch (roleId)
    {

    case 1:
        SetRole(Role::AdminRole);
        break;

    case 2:
        SetRole(Role::UserRole);
        break;

    case 3:
        SetRole(Role::GuestRole);
        break;

    default:
        throw new std::runtime_error("missmatch with db role id");
    }
}

Role RoleManager::GetRole() const{
    return role;
}
