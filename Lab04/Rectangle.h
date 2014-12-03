#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Point.h"

#include <string>

class Rectangle : public Shape
{
public:
    Rectangle(Point p, double length, double width);
    virtual double area() const;
    virtual void resize(double);
    virtual std::string to_string() const;

protected:
    double mLength;
    double mWidth;
};

#endif // RECTANGLE_H
