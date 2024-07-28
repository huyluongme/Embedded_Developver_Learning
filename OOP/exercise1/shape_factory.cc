#include "shape_factory.h"
#include "square.h"
#include "circle.h"
#include "equilateral_triangle.h"

ShapeFactory::ShapeFactory() {}

ShapeFactory::~ShapeFactory() {}

Shape* ShapeFactory::createShape(ShapeType type, double size)
{   
    if(type == ShapeType::SQUARE)
    {
        return new Square(size);
    }
    else if(type == ShapeType::CIRCLE)
    {
        return new Circle(size);
    }
    else
    {
        return new EquilateralTriangle(size);
    }
}