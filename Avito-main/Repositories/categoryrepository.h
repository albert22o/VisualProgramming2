#ifndef CATEGORYREPOSITORY_H
#define CATEGORYREPOSITORY_H

#include "baserepository.h"

#include "Domain/category.h"

class CategoryRepository : public BaseRepository<Category>
{
public:
    CategoryRepository();

    virtual Category GetById(int id) override;
    virtual QList<Category> GetAll() override;
    virtual int AddRecord(Category record) override;
    virtual void UpdateRecord(Category record) override;
    virtual void AddRecords(QList<Category> records) override;
    virtual void DeleteById(int id) override;
    virtual void DeleteManyById(QList<int> idCollection) override;
};

#endif // CATEGORYREPOSITORY_H
