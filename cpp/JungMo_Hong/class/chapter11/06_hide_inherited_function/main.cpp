#include <iostream>
using namespace std;

class Base
{
protected:
    int m_i;

public:
    Base(int value)
        : m_i(value)
    {
    }

    void print()
    {
        cout << "Base" << endl;
    }
};

class Derived : public Base
{
private:
    double m_d;

public:
    Derived(int value)
        : Base(value)
    {
    }

    //public이 되어버림
    using Base::m_i;

    // main에서 print() 사용 불가능
    void print() = delete;

    // main에서 print()사용 불가능
private:
    using Base::print; // do not add ()
    void print() = delete;
};

int main()
{
    Base base(5);
    base.print();

    Derived derived(7);

    // public이 되었으므로 접근 가능
    derived.m_i = 1024;

    // 사용 불가능
    // derived.print();

    return 0;
}