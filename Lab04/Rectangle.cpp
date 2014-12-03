#include "IShape.h"
#include "Shape.h"
#include "Rectangle.h"
#include "ShapeNames.h"
#include "Point.h"

#include <iostream>
#include <sstream>

Rectangle::Rectangle(Point p, double length, double width):
    Shape{p, ShapeNames::RECTANGLE},
    mLength{length},
    mWidth(width)
{
    std::cout << "Rectangle::Rectangle(int x, int y, double size)" << std::endl;
}

double Rectangle::area() const
{
    return mLength * mWidth;
}

void Rectangle::resize(double times)
{
    mWidth*=times;
}

std::string Rectangle::to_string() const
{
    std::stringstream ss;
    ss << Shape::to_string();
    ss << "Area is: " << area() << std::endl;
    return ss.str();
}
