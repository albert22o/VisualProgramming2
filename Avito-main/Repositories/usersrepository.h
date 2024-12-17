#ifndef USERSREPOSITORY_H
#define USERSREPOSITORY_H

#include "baserepository.h"

#include "Domain/user.h"

class UsersRepository : public BaseRepository<User>
{
public:
    UsersRepository();

    bool IsUserExists(const QString& name);
    User* AuthorizeUser(const QString& name, const QString& password);

    virtual User GetById(int id) override;
    virtual QList<User> GetAll() override;
    virtual int AddRecord(User record) override;
    virtual void UpdateRecord(User record) override;
    virtual void AddRecords(QList<User> records) override;
    virtual void DeleteById(int id) override;
    virtual void DeleteManyById(QList<int> idCollection) override;
};

#endif // USERSREPOSITORY_H
