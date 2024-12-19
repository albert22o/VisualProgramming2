#ifndef COMPUTERSREPOSITORY_H
#define COMPUTERSREPOSITORY_H

#include "baserepository.h"
#include "Domain/computer.h"

class ComputersRepository : public BaseRepository<Computer>
{
public:
    ComputersRepository(QSqlDatabase& db);

    virtual Computer GetById(int id) override;
    virtual QList<Computer> GetAll() override;
    virtual int AddRecord(Computer record) override;
    virtual void UpdateRecord(Computer record) override;
    virtual void AddRecords(QList<Computer> records) override;
    virtual void DeleteById(int id) override;
    virtual void DeleteManyById(QList<int> idCollection) override;
};

#endif // COMPUTERSREPOSITORY_H
