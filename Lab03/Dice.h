#ifndef DICE_H
#define DICE_H

class InitRand
{
public:
    InitRand();
};

class Dice{
public:
    Dice();
    void roll();
    unsigned int value() const;
private:
    /*
    note if you have a STATIC member variable inside class Dice, the constructor
    of this static member(InitRand) will be called even before main(), that
    gives you a trick to do some initialization work before the execution of
    main(). Here I use InitRand() to generate the random array for the dice to
    use. Because srand(time(nullptr)) will return the same random array if you
    call it multiple times within 1 sec. You can place it in the constructor of
    Dice, then it will work well if you instantiate only one dice within 1 sec.
    If you instantiate more than one dices within 1 sec, that solution will
    still give you 2 same dices with the same results of each roll(). The best
    solution here is to use this static member variable trick. An alternative
    that I used before I knew this trick is put this in the constructor of the
    dice: srand(time(nullptr) + rand())
    */
    static InitRand sInit;
    unsigned int mValue;
};

#endif // DICE_H
