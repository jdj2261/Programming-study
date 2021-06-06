#include <iostream>
using namespace std;

class Something
{
public:
    static int s_value; // static 멤버는 초기화를 할 수 없다.
    // static const int s_value = 1; // const를 쓸 경우 값을 변경할 수 없다.
    // static constexpr int s_value = 1; // constexpr을 쓸 경우 컴파일 시간에 결정된다. (Singlton 디자인 패턴에 이용된다.)
};

int Something::s_value = 1; // define in cpp

int main()
{
    cout << &Something::s_value << " " << Something::s_value << endl;
    Something st1;
    Something st2;

    st1.s_value = 2;

    // 주소가 같다.
    cout << &st1.s_value << " " << st1.s_value << endl;
    cout << &st2.s_value << " " << st2.s_value << endl;

    Something::s_value = 1024;
    cout << &Something::s_value << " " << Something::s_value << endl;
    return 0;
}