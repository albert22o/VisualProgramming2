#ifndef ROLESSHEMA_H
#define ROLESSHEMA_H

#include "basetableshema.h"

class RolesShema : public BaseTableShema
{
public:
    RolesShema();

    virtual QString AsString() override;
};

#endif // ROLESSHEMA_H
