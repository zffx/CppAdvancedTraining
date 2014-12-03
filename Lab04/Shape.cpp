#include "IShape.h"
#include "Shape.h"

#include <sstream>
#include <iostream>

Shape::Shape(int x, int y, double size, const char* name):
    IShape(),
    mCoordinateX(x),
    mCoordinateY(y),
    mArea(size),
    mName(name)
{
    std::cout << "Shape::Shape(int x, int y, double size, const char* name)";
}

Shape::Shape(int x, int y, double size):
    IShape(),
    mCoordinateX(x),
    mCoordinateY(y),
    mArea(size)
{
    std::cout << "Shape::Shape(int x, int y, double size)";
}

void Shape::move(int x, int y)
{
    std::cout << "Shape::move() to: " << x << " , "  << y << std::endl;
    mCoordinateX = x;
    mCoordinateY = y;
}

double Shape::area() const
{
    std::cout << "Shape::area() is: " << mArea << std::endl;
    return mArea;
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
    ss << "Coordinate is: (" << mCoordinateX << "," << mCoordinateY
       << ")." << std::endl;
    ss << "Area is: " << mArea << std::endl;
    return ss.str();
}
