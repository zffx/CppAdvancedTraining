#include "Dice.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

/*use the default constructor to initialize the
static member, use {} instead of () to initialize values for variables is a new
feature in C++11*/

Dice::InitRand Dice::sInit; //this works
//Dice::InitRand Dice::sInit(Dice::InitRand()); //this doesn't work!
//Dice::InitRand Dice::sInit{};

Dice::InitRand::InitRand()
{
    srand((unsigned)time(nullptr));
}

Dice::Dice()
{
    std::cout << "Dice::Dice()" << std::endl;
    roll();
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
