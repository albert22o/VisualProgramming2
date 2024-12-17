#ifndef COMPUTER_H
#define COMPUTER_H

#include "entity.h"

#include <QString>

class Computer : public Entity
{
public:
    Computer();

    QString Name;
    QString Status;
};

#endif // COMPUTER_H
