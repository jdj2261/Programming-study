#include <iostream>
using namespace std;

class Something
{
public:
    // 클래스 안에 static 멤버 변수의 값을 초기화 할 수 있다.
    // inner class 구현
    class _init
    {
    public:
        _init()
        {
            s_value = 9876;
        }
    };

private:
    static int s_value;
    int m_value;
    static _init s_initializer;

public:
    Something()
    // : m_value(123), s_value(1024) // static 생성자 초기화는 불가능
    {
    }
    static int getValue()
    {
        // return this->s_value; // 불가능
        // return this->m_value; // 불가능
        // this로 접근 아예 불가능
        return s_value;
    }

    int temp()
    {
        return this->s_value;
    }
};

int Something::s_value = 1024;
Something::_init Something::s_initializer;

int main()
{
    cout << Something::getValue() << endl;

    Something s1, s2;

    cout << s1.getValue() << endl;
    // cout << s1.s_value << endl;

    int (Something::*fptr1)() = &Something::temp;

    cout << (s2.*fptr1)() << endl;

    int (*fptr2)() = &Something::getValue;
    cout << fptr2() << endl;

    return 0;
}