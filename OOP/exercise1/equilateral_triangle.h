#ifndef EQUILATERAL_TRIANGLE_H
#define EQUILATERAL_TRIANGLE_H

#include "shape.h"

class EquilateralTriangle : public Shape
{
public:
    EquilateralTriangle(double side);
  
    double area() const override;

    ~EquilateralTriangle();
};

#endif