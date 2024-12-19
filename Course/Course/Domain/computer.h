#ifndef COMPUTER_H
#define COMPUTER_H

#include "entity.h"
#include "Database/TableShemas/computerrates.h"

#include <QString>
#include <QMap>


class TariffCalculator{
private:

    QMap<ComputerRate, double> priceConverter
    {
        {ComputerRate::office, 1},
        {ComputerRate::standart, 1.5},
        {ComputerRate::gaming, 2}
    };

public:
    double CalcSessionPrice(ComputerRate computerRate, int rentalTimeInMinuters){

        return priceConverter[computerRate] * rentalTimeInMinuters;
    }
};

class Computer : public Entity
{
public:
    Computer();
    Computer(int id, QString name, QString status, ComputerRate rate);

    QString Name;
    QString Status;
    ComputerRate Rate;
};

#endif // COMPUTER_H
