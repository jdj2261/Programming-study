#include <iostream>

using namespace std;

// class B; //전방 선언
class A;

class B
{
private:
    int m_value = 2;

public:
    void doSomething(A &a);

    // friend void doSomething(A &a, B &b);
};

class A
{
private:
    int m_value = 1;
    // friend class B;
    friend void B::doSomething(A &a);

    // friend void doSomething(A &a, B &b);
};

void B::doSomething(A &a)
{
    cout << a.m_value << endl;
}

// void doSomething(A &a, B &b)
// {
//     // 특정 클래스의 private 변수를 가져올 수 있다.
//     cout << a.m_value << " " << b.m_value << endl;
// }

int main()
{
    A a;
    B b;
    b.doSomething(a);

    // doSomething(a, b);
    return 0;
}