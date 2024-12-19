#include "computer.h"

Computer::Computer() {}

Computer::Computer(int id,QString name, QString status, ComputerRate rate){

    Id = id;
    Name = name;
    Status = status;
    Rate = rate;
}
