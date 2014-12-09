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
        MyBase() { std::cout << "MyBase::MyBase()" << std::endl; init(); }
        virtual ~MyBase() { std::cout << "MyBase::~MyBase()" << std::endl; }
        virtual void init() { std::cout << "MyBase::init()" << std::endl; } /*
        when init() gets called from MyBase::MyBase() when MyDerived is
        being constructed, since the construction is not complete, there will
        be no polymorphic behavior (i.e. the init() is MyBase will be called
        instead of the one in MyDerived)*/
    };

    class MyDerived : public MyBase {
    public:
        MyDerived() { std::cout << "MyDerived::MyDerived()" << std::endl;}
        ~MyDerived() { std::cout << "MyDerived::~MyDerived()" << std::endl; }
        virtual void init() { std::cout << "MyDerived::init()" << std::endl; }
    };

    MyBase *pM = new MyDerived();
    delete pM;
}

void testLab4()
{
    IShape* shapes[10];
    //shapes[0] = new Ellipse(Point{ 100, 100 }, 30, 40);
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
    try{
        v1[100] = "SB";
    } catch (std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << (v1 < v2) << std::endl;

    MyVector<double> v3{ 10, 0.5 };
    std::cout << v3[9] << std::endl;

    MyVector<Test> v4{ 5 }; // possible
    MyVector<Test> v5{ 5 };
    //if (v4 == v5) // error! Test has no op!=. Template methods are compiled only when called
    ;
}

/*  Lab 11   */
MyVector<std::string> f() { return MyVector<std::string>(100); }

void TestLab11()
{
    MyVector<std::string> v1{ 7, "Hello" };
    MyVector<std::string> v2{ 100 };
    v2 = v1; // test assignment
    v2 = f(); // test moving assignment

    // test Copy-And-Swap:
    try {
        using std::swap;
        MyVector<std::string> tmp{ v1 };
        for (unsigned int i{ 0 }; i < 7; i++)
            tmp[i] = "New string causing reallocations inside the string objects";
        swap(v1, tmp);
    }
    catch(...)
    {
        // v1 in a valid state
    }
    for (unsigned int i{ 0 }; i < 7; i++)
        std::cout << v1[i] << std::endl;
}

/*  Lab 12  */
template <typename T>
class SizeCompareFunctionClass
{
public:
    bool operator()(const T& left, const T& right)
    {
        return left.size() < right.size();
    }
};

template <typename T>
bool sizeCompareFunction(const T& left, const T& right)
{
    return left.size() > right.size();
}

auto lambdaExpr = [](const std::string& left, const std::string& right)
{
    return left.size() < right.size();
};

void TestLab12()
{
    MyVector<std::string> v{ 3 };
    v[0] = "Andersson"; v[1] = "Uggla"; v[2] = "Pettersson";

    std::cout << "Sort with ascending sequence of Name length" << std::endl;
    SizeCompareFunctionClass<std::string> cmpFunctionObject;
    v.sort(cmpFunctionObject);  /* or function pointer, or std::greater<>, or
    lambda expression...*/
    std::cout << v[0] << std::endl << v[1] << std::endl << v[2] << std::endl;

    std::cout << "Sort with descending sequence of Name length" << std::endl;
    v.sort(sizeCompareFunction<std::string>);  /* or function pointer,
    or std::greater<>, or lambda expression...*/
    std::cout << v[0] << std::endl << v[1] << std::endl << v[2] << std::endl;

    std::cout << "Sort with ascending sequence of Name length" << std::endl;
    v.sort(lambdaExpr);  /* or function pointer,
    or std::greater<>, or lambda expression...*/
    std::cout << v[0] << std::endl << v[1] << std::endl << v[2] << std::endl;

    std::cout << "Sort with descending sequence of Name length" << std::endl;
    bool (*compareFuncPtr)(const std::string&, const std::string&);
    compareFuncPtr = sizeCompareFunction<std::string>;
    v.sort(compareFuncPtr);  /* or function pointer, or std::greater<>, or
    lambda expression...*/
    std::cout << v[0] << std::endl << v[1] << std::endl << v[2] << std::endl;

}
