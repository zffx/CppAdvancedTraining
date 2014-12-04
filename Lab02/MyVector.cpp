#include "MyVector.h"

#include <iostream>
#include <algorithm>
#include <stdexcept>

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

int& MyVector::operator[](unsigned int index)
{
    std::cout << "MyVector::operator[]" << std::endl;
    std::cout <<std::endl;
    std::cout << typeid(*this).name() <<std::endl;
    std::cout <<std::endl;
    if(index >= mSize)
    {
        std::cout << "Index out of boundary!" << std::endl;
        throw std::domain_error("Index out of boundary!");
    }
    else
    {
        return mVector[index];
    }
}

const int& MyVector::operator[](unsigned int index) const
{
    std::cout << "MyVector::operator[] const" << std::endl;
    return const_cast<const int&>((*this)[index]);
}

bool operator==(const MyVector& left, const MyVector& right)
{
    std::cout << "operator==(const MyVector& left, const MyVector& right)" <<
                 std::endl;
    if(left.mSize != right.size())
        return false;
    unsigned int size = std::min(left.mSize, right.mSize);
    for(unsigned int i = 0; i < size; i++)
    {
        if(left.mVector[i] != right.mVector[i])
            return false;
    }
    return true;
}

bool operator!=(const MyVector& left, const MyVector& right)
{
    std::cout << "operator!=(const MyVector& left, const MyVector& right)" <<
                 std::endl;
    return !(operator==(left, right));
}

bool operator<(const MyVector& left, const MyVector& right)
{
    std::cout << "operator<(const MyVector& left, const MyVector& right)" <<
                 std::endl;
    unsigned int size = std::min(left.mSize, right.mSize);
    for(unsigned int i = 0; i < size; i++)
    {
        if(left.mVector[i] > right.mVector[i])
            return false;
    }
    return left.mSize < right.mSize ? true : false;
}

bool operator<=(const MyVector& left, const MyVector& right)
{
    std::cout << "operator<=(const MyVector& left, const MyVector& right)" <<
                 std::endl;
    return operator==(left, right) || operator <(left, right);
}

bool operator>(const MyVector& left, const MyVector& right)
{
    std::cout << "operator>(const MyVector& left, const MyVector& right)" <<
                 std::endl;
    return !operator<=(left, right);
}

bool operator>=(const MyVector& left, const MyVector& right)
{
    std::cout << "operator>=(const MyVector& left, const MyVector& right)" <<
                 std::endl;
    return ! operator<(left, right);
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


