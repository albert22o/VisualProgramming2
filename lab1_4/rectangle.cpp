#include "rectangle.h"

Rectangle::Rectangle()
{

}

void Rectangle::GetArea(){
    double a = this->first_par;
    double b = this->second_par;
    this->output = a*b;
}
