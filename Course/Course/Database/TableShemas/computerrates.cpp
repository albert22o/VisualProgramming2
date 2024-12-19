#include "computerrates.h"

int ComputerRateConverter::ToInt(ComputerRate computerRate){
    return int(computerRate);
}

ComputerRate ComputerRateConverter::FromInt(int computerRate){

    switch(computerRate){
    case 0:
        return ComputerRate::office;
    case 1:
        return ComputerRate::standart;
    case 2:
        return ComputerRate::gaming;
    }

    return ComputerRate::office;
}

QString ComputerRateConverter::ParseRate(int computerRate){
    switch(computerRate){
    case 0:
        return "Office";
    case 1:
        return "Standart";
    case 2:
        return "Gaming";
    }

    return "Office";
}

QString ComputerRateConverter::ParseRate(ComputerRate computerRate){
    return ParseRate(int(computerRate));
}
