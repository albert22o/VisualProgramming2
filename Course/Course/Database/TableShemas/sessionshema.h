#ifndef SESSION_H
#define SESSION_H

#include "basetableshema.h"

class SessionShema : public BaseTableShema
{
public:
    SessionShema();

    virtual QString AsString() override;
};

#endif // SESSION_H
