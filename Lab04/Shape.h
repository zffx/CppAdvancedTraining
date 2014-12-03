#ifndef SHAPE_H
#define SHAPE_H

#include "IShape.h"
#include "Point.h"

#include <string>

class Shape : public IShape
{
public:
    Shape(Point p, const char *name);
    virtual void move(int, int) override;
    virtual void resize(double) override;
    virtual ~Shape() {}

protected:
    virtual std::string to_string() const override;
    Point mPoint;
    double mArea;
    std::string mName;
};

#endif // SHAPE_H
