#include <iostream>
using namespace std;

class Base
{

protected:
    int m_value;

public:
    Base(int value)
        : m_value(value)
    {
    }

    void print()
    {
        cout << "Base" << endl;
    }

    friend std::ostream &operator<<(std::ostream &out, const Base &b)
    {
        out << "This is base output" << endl;
        return out;
    }
};

class Derived : public Base
{
public:
    Derived(int value)
        : Base(value)
    {
    }

    void print()
    {
        Base::print();
        cout << "Derived" << endl;
    }

    friend std::ostream &operator<<(std::ostream &out, const Derived &b)
    {
        // cast 가능
        cout << static_cast<Base>(b);
        out << "This is derived output" << endl;
        return out;
    }
};

int main()
{
    Base base(5);
    cout << base;

    Derived derived(7);
    cout << derived;

    return 0;
}