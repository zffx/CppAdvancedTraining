#include "MyVector.h"

#include <iostream>
#include <algorithm>

MyVector::MyVector(int size, int defaultValue /* =0 */):
    mSize(size),
    mVector(new int[mSize])
{
    std::cout << "MyVector::MyVector(int size, int defaultValue)" << std::endl;
    for(unsigned int i = 0; i < mSize; i++)
    {
        mVector[i] = defaultValue;
    }
}

MyVector::~MyVector()
{
    std::cout << "MyVector::~MyVector()" << std::endl;
    delete [] mVector;
}

MyVector::MyVector(const MyVector &orig):mSize(orig.size())
{
    std::cout << "MyVector::MyVector(const MyVector &orig)" << std::endl;
    mVector = new int[mSize];
    for(unsigned int i = 0; i < mSize; i++)
    {
        mVector[i] = orig.mVector[i];
    }
}

MyVector::MyVector(MyVector&& orig):mSize(0),mVector(nullptr)
{
    std::cout << "MyVector::MyVector(MyVector&& orig)" << std::endl;
    /*
    note if you do swap(*this, orig), swap the whole object will trigger
    the copy constructor again, and results in infinite loop of calling
    copy constructors, the right way is to swap each invidiual mamber
    variable

    it is important to rewind this object to a valid status(e.g. mSize = 0,
    and mVector = nulptr) before swapping it to the temp variable(orig), since
    sometime the customized destructor might depends on that state of the object
    */

    std::swap(mSize, orig.mSize);
    std::swap(mVector, orig.mVector);
}

MyVector& MyVector::operator=(const MyVector& orig)
{
    std::cout << "MyVector::operator=()" << std::endl;
    if(this != &orig)
    {
        delete [] mVector; //dont forget to release it!
        mSize = orig.size();
        mVector = new int[mSize];
        for(unsigned int i = 0; i < mSize; i++)
        {
            /*you dont necessarily use this->infront*/
            //this->mVector[i] = orig.mVector[i];
            mVector[i] = orig.mVector[i];
        }
    }
    return *this;
}

MyVector& MyVector::operator=(MyVector&& orig)
{
    std::cout << "MyVector::operator=(MyVector&& orig)" << std::endl;
    /*
    note swap the whole object will trigger the copy constructor whose
    perform can be even worse than the ordinary version
    */
    std::swap(mSize, orig.mSize);
    std::swap(mVector, orig.mVector);
    return *this;
}

bool MyVector::operator==(const MyVector& right) const
{
    std::cout << "MyVector::operator==(const MyVector& right)" << std::endl;
    if(mSize != right.size())
        return false;
    for(unsigned int i = 0; i < mSize; i++)
    {
        if(mVector[i] != right.mVector[i])
            return false;
    }
    return true;
}

bool MyVector::operator!=(const MyVector& right) const
{
    std::cout << "MyVector::operator!=(const MyVector& right)" << std::endl;
    return !(operator==(right));
}

unsigned int MyVector::size() const
{
    std::cout << "MyVector::size()" << std::endl;
    return mSize;
}

void MyVector::traceMyVector()
{
    std::cout << "MyVector::traceMyVector()" << std::endl;
    std::cout << "size of the array is: " << mSize << std::endl;
    std::cout << "value of elements are: " <<std::endl;
    for(unsigned int i = 0; i < mSize; i++)
    {
        std::cout << "myVector[" << i <<"]: " << mVector[i] << "\t";

    }
    std::cout << std::endl << std::endl;
}


