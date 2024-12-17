#ifndef ROLEMANAGER_H
#define ROLEMANAGER_H

#include <QObject>

#include "RoleManagment/roles.h"

class RoleManager : public QObject
{
    Q_OBJECT
public:
    static RoleManager& GetInstance();

    void SetRole(Role newRole);
    void SetRole(int roleId);

    Role GetRole() const;

signals:
    void roleChanged(Role newRole);

private:
    RoleManager(QObject* parent = nullptr) : QObject(parent), role(GuestRole) {}
    RoleManager(const RoleManager&) = delete;
    RoleManager& operator=(const RoleManager&) = delete;

    Role role;
};

#endif // ROLEMANAGER_H
