#include "sector.h"
#include <cmath>
Sector::Sector()
{

}
void Sector::GetArea()
{
    double r = this->first_par;
    double s = this->second_par;
    this->output = M_PI * r * r * s /360;
}
