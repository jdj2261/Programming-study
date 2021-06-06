#include <iostream>
using namespace std;

class A
{
public:
    int m_value;
    A(const int &input)
        : m_value(input)
    {
        cout << "Constructor" << endl;
    }
    ~A()
    {
        cout << "Destructor" << endl;
    }
    void print()
    {
        cout << m_value << endl;
    }
    void printDouble()
    {
        cout << m_value * 2 << endl;
    }
};

int main()
{
    A a(1);
    a.printDouble();
    // a.print();

    A(1).printDouble();
    // R-value 처럼 작동한다.
    // 재사용을 할 수 없다.
    // A().print();
    // A().print();

    return 0;
}