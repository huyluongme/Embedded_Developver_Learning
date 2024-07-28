#include "circle.h"

Circle::Circle(double radius) : Shape(radius)
{
}

Circle::~Circle()
{
}

// Formula to calculate the area of circle: PI*r^2
double Circle::area() const
{
    return PI * m_size * m_size;
}