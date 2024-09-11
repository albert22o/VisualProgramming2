#ifndef GEOMETRY_H
#define GEOMETRY_H
#include<iostream>

class Geometry
{
public:
    Geometry();
    virtual ~Geometry() = 0;
    virtual void GetArea() = 0;
    double first_par;
    double second_par;
    double third_par;
    double output;
};

#endif // GEOMETRY_H
