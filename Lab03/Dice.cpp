#include "Dice.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

InitRand Dice::sInit{}; /*use the default constructor to initialize the static
member, use {} instead of () to initialize values variables is a new feature
in C++11*/

InitRand::InitRand()
{
    srand(time(nullptr));
}

Dice::Dice():mValue(0)
{
    std::cout << "Dice::Dice()" << std::endl;
}

void Dice::roll()
{
    //std::cout << "Dice::roll()" << std::endl;
    mValue = rand()%6+1;
}

unsigned int Dice::value() const
{
    //std::cout << "Dice::value() const" << std::endl;
    return mValue;
}
