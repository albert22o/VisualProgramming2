#ifndef ANNOUNCEMENT_H
#define ANNOUNCEMENT_H

#include "entity.h"

class Announcement : public Entity
{
public:
    Announcement();
    Announcement(int id, QString name, QString desc, QString image, double price, int userId, int categoryId);

    QString Name;
    QString Description;
    QString Image;
    double Price;
    int UserId;
    int CategoryId;
};

#endif // ANNOUNCEMENT_H
