#ifndef USERSHEMA_H
#define USERSHEMA_H

#include "basetableshema.h"

class UserShema : public BaseTableShema
{
public:
    UserShema();

    virtual QString AsString() override;
};

#endif // USERSHEMA_H
