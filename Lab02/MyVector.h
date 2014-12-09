#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
class MyVector{

public:

    explicit MyVector(int size, T defaultValue = T{}):
        mSize(size),
        mVector(new T[mSize])
    {
        std::cout << "MyVector(int size, T defaultValue)" << std::endl;
        for(unsigned int i = 0; i < mSize; i++)
        {
            mVector[i] = defaultValue;
        }
    }

    ~MyVector()
    {
        std::cout << "~MyVector()" << std::endl;
        delete [] mVector;
    }

    MyVector(const MyVector &orig):mSize(orig.size())
    {
        std::cout << "MyVector(const MyVector &orig)" << std::endl;
        mVector = new T[mSize];
        for(unsigned int i = 0; i < mSize; i++)
        {
            mVector[i] = orig.mVector[i];
        }
    }

    MyVector(MyVector&& orig):mSize(0),mVector(nullptr)
    {
        std::cout << "MyVector(MyVector&& orig)" << std::endl;
        /*
        note if you do swap(*this, orig), swap the whole object will trigger
        the copy constructor again, and results in infinite loop of calling
        copy constructors, the right way is to swap each invidiual mamber
        variable

        it is important to rewind this object to a valid status(e.g. mSize = 0,
        and mVector = nulptr) before swapping it to the temp variable(orig),
        since sometime the customized destructor might depends on that state
        of the object
        */

        std::swap(mSize, orig.mSize);
        std::swap(mVector, orig.mVector);
    }

    MyVector& operator=(const MyVector<T>& orig)
    {
        std::cout << "operator=()" << std::endl;
        MyVector tmp(orig);/*copy-swap idiom*/
        using std::swap;
        swap(*this, tmp);
        return *this;
    }

    MyVector& operator=(MyVector&& orig)
    {
        std::cout << "operator=(MyVector&& orig)" << std::endl;
        /*
        note swap the whole object will trigger the copy constructor whose
        perform can be even worse than the ordinary version

        std::swap(mSize, orig.mSize);
        std::swap(mVector, orig.mVector);
        */
        using std::swap;
        swap(*this, orig);
        return *this;
    }

    T& operator[](unsigned int index)
    {
        /* You can use this to get the class name */
        //std::cout << typeid(*this).name() <<std::endl;
        if(index >= mSize)
        {
            std::cout << "Index out of boundary!" << std::endl;
            throw std::out_of_range("Index out of boundary!");
        }
        else
        {
            return mVector[index];
        }
    }

    const T& operator[](unsigned int index) const
    {
        std::cout << "operator[] const" << std::endl;
        return const_cast<const T&>((*this)[index]);
    }

    template <typename compareFunc>
    void sort(compareFunc compare)
    {
        if (mSize < 2)
            return;
        bool swapped;
        do
        {
            swapped = false;
            for(unsigned int i{ 0 }; i < mSize - 1; i++)
            {
                if (compare(mVector[i+1],mVector[i])) // replace < for a callback
                {
                    using std::swap;
                    swap(mVector[i], mVector[i+1]);
                    swapped = true;
                }
            }
        } while (swapped);
    }

    unsigned int size() const
    {
        //std::cout << "size()" << std::endl;
        return mSize;
    }

    void traceMyVector()
    {
        std::cout << "traceMyVector()" << std::endl;
        std::cout << "size of the array is: " << mSize << std::endl;
        std::cout << "value of elements are: " <<std::endl;
        for(unsigned int i = 0; i < mSize; i++)
        {
            std::cout << "myVector[" << i <<"]: " << mVector[i] << "\t";

        }
        std::cout << std::endl << std::endl;
    }
private:
    unsigned int mSize;
    T* mVector;

    template <typename C>
    friend void swap(MyVector<C>& left, MyVector<C>& right);

    template <typename C>
    friend bool operator==(const MyVector<C>& left, const MyVector<C>& right);

    template <typename C>
    friend bool operator!=(const MyVector<C>& left, const MyVector<C>& right);

    template <typename C> friend
    bool operator<(const MyVector<C>& left, const MyVector<C>& right);

    template <typename C> friend
    bool operator<=(const MyVector<C>& left, const MyVector<C>& right);

    template <typename C> friend
    bool operator>(const MyVector<C>& left, const MyVector<C>& right);

    template <typename C> friend
    bool operator>=(const MyVector<C>& left, const MyVector<C>& right);
};

template <typename T>
void swap(MyVector<T>& left, MyVector<T>& right)
{
    std::cout << "void swap(MyVector& left, MyVector& right)" << std::endl;
    using std::swap;
    swap(left.mSize, right.mSize);
    swap(left.mVector, right.mVector);
}

template <typename T>
bool operator==(const MyVector<T>& left, const MyVector<T>& right)
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

template <typename T>
bool operator!=(const MyVector<T>& left, const MyVector<T>& right)
{
    std::cout << "operator!=(const MyVector& left, const MyVector& right)" <<
                 std::endl;
    return !(operator==(left, right));
}

template <typename T>
bool operator<(const MyVector<T>& left, const MyVector<T>& right)
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

template <typename T>
bool operator<=(const MyVector<T>& left, const MyVector<T>& right)
{
    std::cout << "operator<=(const MyVector& left, const MyVector& right)" <<
                 std::endl;
    return operator==(left, right) || operator <(left, right);
}

template <typename T>
bool operator>(const MyVector<T>& left, const MyVector<T>& right)
{
    std::cout << "operator>(const MyVector& left, const MyVector& right)" <<
                 std::endl;
    return !operator<=(left, right);
}

template <typename T>
bool operator>=(const MyVector<T>& left, const MyVector<T>& right)
{
    std::cout << "operator>=(const MyVector& left, const MyVector& right)" <<
                 std::endl;
    return ! operator<(left, right);
}


#endif // MYVECTOR_H
