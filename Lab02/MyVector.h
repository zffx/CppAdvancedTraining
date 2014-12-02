#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVector{

public:
    MyVector(int size, int defaultValue = 0);
    ~MyVector();
    MyVector(const MyVector& orig) ;
    MyVector& operator=(const MyVector& orig);
    bool operator==(const MyVector& right);
    bool operator!=(const MyVector& right);
    int size() const;
    void traceMyVector();
private:
    int mSize;
    int* mVector;
};

void testLab2();
#endif // MYVECTOR_H
