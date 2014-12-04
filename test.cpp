#include "test.h"
#include "./Lab01/Lab_1.h"
#include "./Lab02/MyVector.h"
#include "./Lab03/Dice.h"
#include "./Lab04/IShape.h"
#include "./Lab04/Rectangle.h"
#include "./Lab04/Point.h"

#include <iostream>
void testLab1()
{
    C c;
}

/*
MyVector create_MyVector()
{
    std::cout << "create_MyVector()" << std::endl;
    MyVector v{ 10, 1 };
    return v;
}
*/
void testLab2()
{
    /*
    MyVector v1(7, 1); // 7 elements initialized to 1
    v1.traceMyVector();
    MyVector v2(v1); // copying
    v2.traceMyVector();
    MyVector v3(100); // 100 elements initialized to 0
    v3.traceMyVector();
    v3 = v2;  // assignment
    v3.traceMyVector();

    MyVector v4{ create_MyVector() }; //verify by debugging that moving ctr runs
    v4 = create_MyVector();  //verify by debugging that moving assignment runs
    v4.traceMyVector();
    */
}




void printDice(const Dice& d)
{
    std::cout << d.value() << " " ;
}

void testLab3()
{
    Dice d1{};
    for (int i{ 0 }; i < 20; i++)
    {
        d1.roll();
        printDice(d1);
    }
    std::cout << std::endl;

    Dice d2;
    for (int i{ 0 }; i < 20; i++)
    {
        d2.roll();
        printDice(d2);
    }
    std::cout << std::endl;
}

void testLabX()
{
    class MyBase {
    public:
        virtual void m() { std::cout << "MyBase::m()" << std::endl;}
        MyBase() { std::cout << "MyBase::MyBase()" << std::endl; this->m();}
        virtual ~MyBase()
        {}
    };

    class MyDerived : public MyBase {
    public:
        void m(){ std::cout << "MyDerived::m()" << std::endl;}
        MyDerived() { std::cout << "MyDerived::MyDerived()" << std::endl; m();}
        ~MyDerived() {}
    };

    MyBase *pM = new MyDerived();
    pM->m();
    delete pM;
}

void testLab4()
{
    IShape* shapes[10];
    //shapes[0] = new Ellipse(Point{ 100, 100 }, 30, 40);
    //shapes[1] = new Rectangle(Point{ 200, 200 }, 50, 80);
    shapes[1] = new Rectangle(Point{ 200, 200 }, 50, 80);
    /*
    std::cout << shapes[0]->to_string();
    shapes[0]->resize(2.5);
    std::cout << shapes[0]->to_string();
    */
    std::cout << shapes[1]->to_string();/* note the visibility of to_string() is
    the same as defined in the pointer but not the object, in this case it is
    the one in IShape but not Rectangle*/
    shapes[1]->move(50, 50);
    std::cout << shapes[1]->to_string();
    std::cout << "Area " << shapes[1]->area() << std::endl;

    //delete shapes[0];
    delete shapes[1];
}


void testLab5()
{
    /*
    MyVector v1{ 7, 0 };
    MyVector v2{ 8, 0 };
    std::cout << (v1 == v2) << std::endl;
    std::cout << (v1 < v2) << std::endl;
    v1[0] = 1;
    v1.traceMyVector();
    std::cout << (v1 < v2) << std::endl;
    */
}

void testLab7()
{

    class Test
    {
        // empty class
    };


    MyVector<std::string> v1{ 7, "Hej" };
    MyVector<std::string> v2{ 8, "H?" };
    std::cout << (v1 == v2) << std::endl;
    std::cout << (v1 < v2) << std::endl;
    v1[0] = "Paj";
    std::cout << (v1 < v2) << std::endl;

    MyVector<double> v3{ 10, 0.5 };
    std::cout << v3[9] << std::endl;

    MyVector<Test> v4{ 5 }; // possible
    MyVector<Test> v5{ 5 };
    //if (v4 == v5) // error! Test has no op!=. Template methods are compiled only when called
    ;
}
