#ifndef USER_H
#define USER_H

#include "basetableshema.h"

class UserShema : public BaseTableShema
{
public:
    UserShema();

    virtual QString AsString() override;

};

#endif // USER_H
