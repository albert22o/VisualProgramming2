#ifndef CLOSEDSESSIONS_H
#define CLOSEDSESSIONS_H

#include "basetableshema.h"

class ClosedSessionsShema : public BaseTableShema
{
public:
    ClosedSessionsShema();

    virtual QString AsString() override;
};

#endif // CLOSEDSESSIONS_H
