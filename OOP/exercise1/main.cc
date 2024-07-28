#include <iostream>

using namespace std;

#include "shape_factory.h"

int main()
{
    ShapeFactory* shapeFactory = new ShapeFactory();

    Shape* square = shapeFactory->createShape(ShapeType::SQUARE, 5);
    Shape* circle = shapeFactory->createShape(ShapeType::CIRCLE, 3);
    Shape* equiTriangle = shapeFactory->createShape(ShapeType::EQUILATERAL_TRIANGLE, 8);

    cout << "Area of Square with side length is 5: " << square->area() << "\n";
    cout << "Area of Circle with radius is 3: " << circle->area() << "\n";
    cout << "Area of Equilateral Triangle is 8: " << equiTriangle->area() << "\n";

    delete shapeFactory;
    delete square;
    delete circle;
    delete equiTriangle;
    return 0;
}