#include "test.h"
#include "./Lab01/Lab_1.h"
#include "./Lab02/MyVector.h"
#include "./Lab03/Dice.h"

#include <iostream>
void testLab1()
{
    C c;
}

MyVector create_my_vector()
{
    std::cout << "create_my_vector()" << std::endl;
    MyVector v{ 10, 1 };
    return v;
}

void testLab2()
{
    MyVector v1(7, 1); // 7 elements initialized to 1
    v1.traceMyVector();
    MyVector v2(v1); // copying
    v2.traceMyVector();
    MyVector v3(100); // 100 elements initialized to 0
    v3.traceMyVector();
    v3 = v2;  // assignment
    v3.traceMyVector();

    MyVector v4{ create_my_vector() }; //verify by debugging that moving ctr runs
    v4 = create_my_vector();  //verify by debugging that moving assignment runs
    v4.traceMyVector();
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
