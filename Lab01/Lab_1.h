// Lab 1

#include <iostream>

class X
{
public:
	X() { std::cout << "X constructor" << std::endl; }
	~X() { std::cout << "X destructor" << std::endl; }
};

class A
{
public:
	A() { std::cout << "A constructor" << std::endl; }
	~A() { std::cout << "A destructor" << std::endl; }
private:
	X x;
};

class Y
{
public:
	Y() { std::cout << "Y constructor" << std::endl; }
	~Y() { std::cout << "Y destructor" << std::endl; }
};

class Z
{
public:
	Z() { std::cout << "Z constructor" << std::endl; }
	~Z() { std::cout << "Z destructor" << std::endl; }
};

class B : public A
{
public:
	B() { std::cout << "B constructor" << std::endl; }
	~B() { std::cout << "B destructor" << std::endl; }
private:
	Y y;
	Z z;
};

class C : public B
{
public:
	C() { std::cout << "C constructor" << std::endl; }
	~C() { std::cout << "C destructor" << std::endl; }
};

/*
int main()
{
	C c;
}
*/
