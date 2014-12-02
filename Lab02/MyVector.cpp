#include "MyVector.h"

#include <iostream>

MyVector::MyVector(int size, int defaultValue):
    mSize(size),
    mVector(new int[mSize])
{
    std::cout << "MyVector::MyVector(int size, int defaultValue)" << std::endl;
    for(int i = 0; i < mSize; i++)
    {
        mVector[i] = defaultValue;
    }
}

MyVector::~MyVector()
{
    std::cout << "MyVector::~MyVector()" << std::endl;
    delete []mVector;
}

MyVector::MyVector(const MyVector &orig):mSize(orig.size())
{
    std::cout << "MyVector::MyVector(const MyVector &orig)" << std::endl;
    mVector = new int[mSize];
    for(int i = 0; i < mSize; i++)
    {
        mVector[i] = orig.mVector[i];
    }
}

MyVector& MyVector::operator=(const MyVector& orig)
{
    std::cout << "MyVector::operator=()" << std::endl;
    if(this != &orig)
    {
        mSize = orig.size();
        mVector = new int[mSize];
        for(int i = 0; i < mSize; i++)
        {
            this->mVector[i] = orig.mVector[i];/*you dont necessarily use this->
            infront*/
            mVector[i] = orig.mVector[i];
        }
    }
    return *this;
}

bool MyVector::operator==(const MyVector& right)
{
    std::cout << "MyVector::operator==(const MyVector& right)" << std::endl;
    if(mSize != right.size())
        return false;
    for(int i = 0; i < mSize; i++)
    {
        if(mVector[i] != right.mVector[i])
            return false;
    }
    return true;
}

bool MyVector::operator!=(const MyVector& right)
{
    std::cout << "MyVector::operator!=(const MyVector& right)" << std::endl;
    return !(operator==(right));
}

int MyVector::size() const
{
    std::cout << "MyVector::size()" << std::endl;
    return mSize;
}

void MyVector::traceMyVector()
{
    std::cout << "MyVector::traceMyVector()" << std::endl;
    std::cout << "size of the array is: " << mSize << std::endl;
    std::cout << "value of elements are: " <<std::endl;
    for(int i = 0; i < mSize; i++)
    {
        std::cout << "myVector[" << i <<"]: " << mVector[i] << "\t";

    }
    std::cout << std::endl << std::endl;
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
}
