#include "circle.h"
#include <cmath>

Circle::Circle()
{

}
void Circle::GetArea()
{
    double r = this->first_par;
    this->output = M_PI * r * r ;
}
