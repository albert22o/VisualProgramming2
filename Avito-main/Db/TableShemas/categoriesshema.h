#ifndef CATEGORIESSHEMA_H
#define CATEGORIESSHEMA_H

#include "basetableshema.h"

class CategoriesShema : public BaseTableShema
{
public:
    CategoriesShema();

    virtual QString AsString() override;
};

#endif // CATEGORIESSHEMA_H
