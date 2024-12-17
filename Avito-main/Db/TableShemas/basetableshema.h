#ifndef BASETABLESHEMA_H
#define BASETABLESHEMA_H

#include <QString>

class BaseTableShema
{
public:
    BaseTableShema();

    virtual QString AsString() = 0;
};

#endif // BASETABLESHEMA_H
