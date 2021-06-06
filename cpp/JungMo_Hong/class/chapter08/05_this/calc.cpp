#include <iostream>
using namespace std;

class Calc
{
private:
    int m_value;

public:
    Calc(const int &value)
        : m_value(value)
    {
    }

    Calc &add(int value)
    {
        m_value += value;
        return *this;
    }

    Calc &sub(int value)
    {
        m_value -= value;
        return *this;
    }

    Calc &mult(int value)
    {
        m_value *= value;
        return *this;
    }

    void print()
    {
        cout << m_value << endl;
    }
};

int main()
{
    Calc cal(10);

    // member function chaining
    // C++ 입장에서 이렇게 짜는 것은 불안하다. 유행이긴 함.
    cal.add(10).sub(1).mult(2).print();
    cal.print();

    return 0;
}