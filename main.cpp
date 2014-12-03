
#include "test.h"

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Input the number to run:" <<endl
         << "1.Lab1" << endl
         << "2.Lab2" << endl
         << "3.Lab3" << endl;
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
    default:
        break;
    }
}

