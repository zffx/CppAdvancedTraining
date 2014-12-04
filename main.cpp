
#include "test.h"

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Input the number to run:" <<endl
         << "1. Lab1" << endl
         << "2. Lab2" << endl
         << "3. Lab3" << endl
         << "4. Lab4" << endl
         << "5. Lab5" << endl
         << "7. Lab7" << endl
         << "11. Lab11" << endl;
    unsigned int choice = 0;
    cin >> choice ;

    switch(choice)
    {
    case 1:
    {
        testLab1();
        break;
    }
    case 2:
    {
        testLab2();
        break;
    }
    case 3:
    {
        testLab3();
        break;
    }
    case 4:
    {
        testLab4();
        break;
    }
    case 5:
    {
        testLab5();
        break;
    }
    case 7:
    {
        testLab7();
        break;
    }
    case 11:
    {
        TestLab11();
        break;
    }
    default:
        break;
    }
}

