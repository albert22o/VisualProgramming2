#include "triangle.h"
#include <cmath>

Triangle::Triangle()
{

}

void Triangle::GetArea()
{
    double a = this->first_par;
    double b = this->second_par;
    double c = this->third_par;
    double p = (a+b+c)/2;
    this->output = std::sqrt(p*(p-a)*(p-b)*(p-c));
}
