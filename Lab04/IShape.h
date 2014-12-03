#ifndef ISHAPE_H
#define ISHAPE_H

#include <string>

#define interface class

interface IShape
{
    public:
    virtual void move(int, int) = 0;
    virtual double area() const = 0;
    virtual void resize(double) = 0;
    virtual std::string to_string() const = 0;
    virtual ~IShape() {}
};
#endif // ISHAPE_H
