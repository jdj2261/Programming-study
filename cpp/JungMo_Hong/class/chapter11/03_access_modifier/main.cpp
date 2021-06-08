#include <iostream>
using namespace std;

class Base
{
public:
    int m_public;

protected:
    int m_protected;

private:
    int m_private;
};

class Derived : public Base
{
public:
    Derived()
    {
        // public, private, protected으로 상속받으면 public, protected 사용 가능
        m_public = 123;
        m_protected = 123;

        // 접근 불가능
        // m_private = 123;
    }
};

class GrandChild : public Derived
{
public:
    GrandChild()
    {
        // Derived class가 private로 상속받으면 사용 불가능
        Derived::m_protected;
    }
};

int main()
{
    Base base;

    // protected로 상속받으면 사용 불가능
    base.m_public = 123;

    // 접근 불가능
    // base.m_protected = 123;
    // base.m_private = 123;

    return 0;
}