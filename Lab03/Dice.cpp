#include "Dice.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

Dice::Dice():mValue(0)
{
    std::cout << "Dice::Dice()" << std::endl;
}

void Dice::roll()
{
    //std::cout << "Dice::roll()" << std::endl;
    srand(time(nullptr)+ rand());
    mValue = rand()%6+1;
}

unsigned int Dice::value() const
{
    //std::cout << "Dice::value() const" << std::endl;
    return mValue;
}
