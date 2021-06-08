#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived1 : public Base
{
public:
    int m_j = 1;

    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

class Derived2 : public Base
{
public:
    string m_name = "Dr. Two";

    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

int main()
{
    Derived1 d1;
    Base *base = &d1;
    // auto *base_to_d1 = dynamic_cast<Derived1 *>(base);
    // auto *base_to_d1 = static_cast<Derived1 *>(base);
    // if (base_to_d1 != nullptr)
    //     cout << base_to_d1->m_j << endl;
    // else
    //     cout << "Failed" << endl;

    // 강제 형변환
    // 문제가 될 경우 dynamic_cast는 nullptr로 반환하지만
    // static_cast는 값 그대로 보낸다.
    auto *base_to_d2 = dynamic_cast<Derived2 *>(base);
    auto *base_to_d2 = static_cast<Derived2 *>(base);

    if (base_to_d2 != nullptr)
        base_to_d2->print();
    else
        cout << "Failed" << endl;
    // base_to_d1->m_j = 256;
    // cout << d1.m_j << endl;

    return 0;
}