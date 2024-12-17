#ifndef COMPUTERSTATUSES_H
#define COMPUTERSTATUSES_H

#include <QString>

class ComputerStatuses
{
public:
    ComputerStatuses();

    static QString Free();
    static QString Busy();
};

#endif // COMPUTERSTATUSES_H
