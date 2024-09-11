#include "trapezoid.h"

Trapezoid::Trapezoid()
{

}
void Trapezoid::GetArea()
{
    double a = this->first_par;
    double b = this->second_par;
    double h = this->third_par;
    this->output = h*(a+b)/2;
}
