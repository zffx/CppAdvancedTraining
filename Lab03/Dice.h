#ifndef DICE_H
#define DICE_H

class Dice{
public:
    Dice();
    void roll();
    unsigned int value() const;
private:
    unsigned int mValue;
};

#endif // DICE_H
