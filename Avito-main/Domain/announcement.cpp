#include "announcement.h"

Announcement::Announcement() {}

Announcement::Announcement(
    int id, QString name, QString desc, QString image, double price, int userId, int categoryId)
{
    Id = id;
    Name = name;
    Description = desc;
    Image = image;
    Price = price;
    UserId = userId;
    CategoryId = categoryId;
}
