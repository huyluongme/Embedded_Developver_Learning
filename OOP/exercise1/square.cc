#include "square.h"

Square::Square(double side) : Shape(side)
{
}

Square::~Square()
{
}

// Formula to calculate the area of square: side^2
double Square::area() const
{
    return m_size * m_size;
}