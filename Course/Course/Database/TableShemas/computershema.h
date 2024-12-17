#ifndef COMPUTER_H
#define COMPUTER_H

#include "basetableshema.h"

class ComputerShema : public BaseTableShema
{
public:
    ComputerShema();

    virtual QString AsString() override;
};

#endif // COMPUTER_H
