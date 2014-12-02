#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVector{

public:
    explicit MyVector(int size, int defaultValue = 0);
    ~MyVector();
    MyVector(const MyVector& orig) ;
    MyVector& operator=(const MyVector& orig);
    bool operator==(const MyVector& right) const;
    bool operator!=(const MyVector& right) const;
    unsigned int size() const;
    void traceMyVector();
private:
    unsigned int mSize;
    int* mVector;
};

void testLab2();
#endif // MYVECTOR_H
