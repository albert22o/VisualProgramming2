#ifndef CATEGORY_H
#define CATEGORY_H

#include "entity.h"

#include <QString>

class Category : public Entity
{
public:
    Category();
    Category(QString name);

    QString Name;
};

#endif // CATEGORY_H
