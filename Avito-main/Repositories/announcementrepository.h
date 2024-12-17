#ifndef ANNOUNCEMENTREPOSITORY_H
#define ANNOUNCEMENTREPOSITORY_H

#include "baserepository.h"

#include <QSqlQuery>
#include <QSqlError>

#include "Domain/announcement.h"

class AnnouncementRepository : public BaseRepository<Announcement>
{
public:
    AnnouncementRepository();

    QList<Announcement> GetByCategoryId(int categoryId);

    virtual Announcement GetById(int id) override;
    virtual QList<Announcement> GetAll() override;
    virtual int AddRecord(Announcement record) override;
    virtual void UpdateRecord(Announcement record) override;
    virtual void AddRecords(QList<Announcement> records) override;
    virtual void DeleteById(int id) override;
    virtual void DeleteManyById(QList<int> idCollection) override;
};

#endif // ANNOUNCEMENTREPOSITORY_H
