#include "IShape.h"
#include "Shape.h"
#include "Point.h"

#include <sstream>
#include <iostream>

Shape::Shape(Point p, const char* name):
    IShape(),
    mPoint(p),
    mName(name)
{
    std::cout << "Shape::Shape(int x, int y, double size)";
}

void Shape::move(int x, int y)
{
    std::cout << "Shape::move() to: " << x << " , "  << y << std::endl;
    mPoint = Point(x,y);
}

void Shape::resize(double newArea)
{
    std::cout << "Shape::resize()";
    mArea = newArea;
}

std::string Shape::to_string() const
{
    std::stringstream ss;
    ss << "Rectangle::to_string() const" << std::endl;
    ss << "Shape is :" << mName << std::endl;
    ss << "Coordinate is: (" << mPoint.mX << "," << mPoint.mY
       << ")." << std::endl;
    return ss.str();
}
