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
};

class Derived : public Base
{
public:
    Derived(int value)
        : Base(value)
    {
    }

    void setValue(int value)
    {
        // 부모 클래스의 변수와 자식 클래스의 변수를 같이 사용해야 할 경우
        // protected로 접근할 수 있다.
        Base::m_value = value;
    }
};

int main()
{
    return 0;
}