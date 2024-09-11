#include "rhombus.h"

Rhombus::Rhombus()
{

}

void Rhombus::GetArea()
{
    double a = this->first_par;
    double h = this->second_par;
    this->output = a*h;
}
