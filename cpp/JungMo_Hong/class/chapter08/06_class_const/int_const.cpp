#include <iostream>

using namespace std;

class Something
{

public:
    int m_value = 0;

    Something(const Something &st_in)
    {
        m_value = st_in.m_value;

        cout << "Copy Constructor" << endl;
    }

    Something()
    {
        cout << "Constructor" << endl;
    }
    void setValue(int value) { m_value = value; }
    int getValue() const { return m_value; } // const는 많이 쓰도록 하자
};

// void print(Something st)
void print(const Something &st)
{
    // 위의 경우 주소가 다르고 복사 생성자가 호출이 된다.
    // 아래의 경우는 주소가 같고 복사 생성자가 호출되지 않는다.
    // const는 쓸  수 있으면 다 쓰자.
    cout << &st << endl;
    cout << st.getValue() << endl;
}
int main()
{
    Something something;

    cout << &something << endl;
    print(something);

    // const Something something;
    // something.setValue(3);   //error
    // cout << something.getValue() << endl; // getValue()함수에 const를 안 붙이면 error
    return 0;
}