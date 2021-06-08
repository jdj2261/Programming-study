#include <iostream>
using namespace std;

class A
{
public:
    virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
    // overriding 한다는 것을 의미 ( 디버깅할 때 용이함. )
    virtual void print() { cout << "B" << endl; }
};

class C : public B
{
public:
    virtual void print() { cout << "C" << endl; }
};

class D : public C
{
public:
    virtual void print() { cout << "D" << endl; }
};

int main()
{
    A a;
    B b;
    C c;
    D d;

    B &ref = c;
    ref.print();
    return 0;
}