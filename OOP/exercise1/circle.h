#ifndef CIRCLE_H
#define CIRCLR_H

#include "shape.h"

const double PI =  3.14159265358979323846;

class Circle : public Shape
{
public:
    Circle(double radius);
    
    double area() const override;
    
    ~Circle();

};

#endif