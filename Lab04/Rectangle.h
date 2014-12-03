#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

#include <string>

class Rectangle : public Shape
{
public:
    Rectangle(int x, int y, double size);
    virtual std::string to_string() const;
};

#endif // RECTANGLE_H
