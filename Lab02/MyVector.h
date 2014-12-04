#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVector{

public:
    explicit MyVector(int size, int defaultValue = 0);
    ~MyVector();
    MyVector(const MyVector& orig);
    MyVector(MyVector&& orig); //move copy constructor
    MyVector& operator=(const MyVector& orig);
    MyVector& operator=(MyVector&& orig); //move assignment

    int& operator[](unsigned int index);
    const int& operator[](unsigned int index) const;

    unsigned int size() const;
    void traceMyVector();
private:
    unsigned int mSize;
    int* mVector;

    friend bool operator==(const MyVector& left, const MyVector& right);
    friend bool operator!=(const MyVector& left, const MyVector& right);
    friend bool operator<(const MyVector& left, const MyVector& right);
    friend bool operator<=(const MyVector& left, const MyVector& right);
    friend bool operator>(const MyVector& left, const MyVector& right);
    friend bool operator>=(const MyVector& left, const MyVector& right);
};

bool operator==(const MyVector& left, const MyVector& right);
bool operator!=(const MyVector& left, const MyVector& right);
bool operator<(const MyVector& left, const MyVector& right);
bool operator<=(const MyVector& left, const MyVector& right);
bool operator>(const MyVector& left, const MyVector& right);
bool operator>=(const MyVector& left, const MyVector& right);


#endif // MYVECTOR_H
