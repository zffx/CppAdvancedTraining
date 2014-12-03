#include "IShape.h"
#include "Shape.h"
#include "Rectangle.h"
#include "ShapeNames.h"

#include <iostream>

Rectangle::Rectangle(int x, int y, double size):
    Shape(x, y, size, ShapeNames::RECTANGLE)
{
    std::cout << "Rectangle::Rectangle(int x, int y, double size)" << std::endl;
}

std::string Rectangle::to_string() const
{

    return Shape::to_string();
}
