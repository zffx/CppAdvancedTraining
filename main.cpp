#include "./Lab01/Lab_1.h"
#include "./Lab02/MyVector.h"

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Input the number to run:" <<endl
         << "1.Lab1" << endl
         << "2.Lab2" << endl;
    unsigned int choice = 0;
    cin >> choice ;

    switch(choice)
    {
    case 1:
    {
        C c;
        break;
    }
    case 2:
    {
        testLab2();
    }
    default:
        break;
    }
}

