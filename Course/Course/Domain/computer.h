#ifndef COMPUTER_H
#define COMPUTER_H

#include "entity.h"

#include <QString>

class Computer : public Entity
{
public:
    Computer();
    Computer(int id, QString name, QString status);

    QString Name;
    QString Status;
};

#endif // COMPUTER_H
