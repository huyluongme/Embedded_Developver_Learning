#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
protected:
    double m_size;

public:
    Shape(double size);
    
    virtual double area() const = 0;
    
    ~Shape();
};

#endif