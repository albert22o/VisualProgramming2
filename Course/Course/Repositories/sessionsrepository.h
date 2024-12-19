#ifndef SESSIONSREPOSITORY_H
#define SESSIONSREPOSITORY_H

#include "baserepository.h"

#include "Domain/session.h"

enum SessionStatus{
    Active = 0,
    Closed
};

class SessionsRepository : public BaseRepository<Session>
{
public:
    SessionsRepository();

    Session GetSessionByComputerId(int id);
    QList<Session> GetAllSessionsByStatus(SessionStatus sessionStatus);

    virtual Session GetById(int id) override;
    virtual QList<Session> GetAll() override;
    virtual int AddRecord(Session record) override;
    virtual void UpdateRecord(Session record) override;
    virtual void AddRecords(QList<Session> records) override;
    virtual void DeleteById(int id) override;
    virtual void DeleteManyById(QList<int> idCollection) override;

    static QString ParseStatusFrom(SessionStatus status);
};

#endif // SESSIONSREPOSITORY_H
