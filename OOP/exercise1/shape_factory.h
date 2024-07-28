#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "shape.h"

enum ShapeType
{
    SQUARE,
    CIRCLE,
    EQUILATERAL_TRIANGLE,
};

class ShapeFactory
{
private:
public:
    ShapeFactory(/* args */);
    ~ShapeFactory();

    Shape* createShape(ShapeType type, double size);
};

#endif