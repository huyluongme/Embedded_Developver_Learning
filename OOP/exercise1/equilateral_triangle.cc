#include "equilateral_triangle.h"
#include <cmath>

EquilateralTriangle::EquilateralTriangle(double side) : Shape(side)
{
}

EquilateralTriangle::~EquilateralTriangle()
{
}

// Formula to calculate the area of equilateral triangle: (√3/4)a^2
double EquilateralTriangle::area() const
{
    return (sqrt(3)/4) * m_size * m_size;
}
