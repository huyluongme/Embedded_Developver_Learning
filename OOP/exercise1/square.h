#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape
{
public:
    Square(double side);
    
    double area() const override;
    
    ~Square();
};

#endif