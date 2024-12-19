#ifndef COMPUTERRATES_H
#define COMPUTERRATES_H

#include <QString>

enum ComputerRate{
    office = 0,
    standart = 1,
    gaming = 2
};

class ComputerRateConverter{
public:
    static int ToInt(ComputerRate computerRate);
    static ComputerRate FromInt(int computerRate);
    static QString ParseRate(int computerRate);
    static QString ParseRate(ComputerRate computerRate);
};


#endif // COMPUTERRATES_H
