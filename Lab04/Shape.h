#ifndef SHAPE_H
#define SHAPE_H

#include "IShape.h"

#include <string>

class Shape : public IShape
{
public:
    Shape(int x, int y, double size);
    Shape(int x, int y, double size, const char *name);
    virtual void move(int, int);
    virtual double area() const;
    virtual void resize(double);
    virtual std::string to_string() const = 0;
    virtual ~Shape() {}
protected:
    int mCoordinateX;
    int mCoordinateY;
    double mArea;
    std::string mName;
};

#endif // SHAPE_H
