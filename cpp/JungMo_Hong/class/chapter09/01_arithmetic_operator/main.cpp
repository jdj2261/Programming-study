#include <iostream>
using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int &getCents() { return m_cents; }

    // 방법 2
    // friend Cents operator+(const Cents &c1, const Cents &c2)
    // {
    //     return Cents(c1.getCents() + c2.getCents());
    // }

    // 방법 3( =, [], (), ->) 는 멤버 function 으로만 오버로딩 한다.
    Cents operator+(const Cents &c2)
    {
        return Cents(this->m_cents + c2.getCents());
    }
};

// 연산자 오버로딩을 배우지 않았으면 이렇게 작성함.
// void add(const Cents &c1, const Cents &c2, Cents &c_out)
// {
//     c_out.getCents() = c1.getCents() + c2.getCents();
// }

// 방법 1 연산자 오버로딩
// return 타입으로 받는 것을 선호
// Cents operator+(const Cents &c1, const Cents &c2)
// {
//     return Cents(c1.getCents() + c2.getCents());
// }

int main()
{
    Cents cents1(6);
    Cents cents2(8);

    // Cents sum;
    // add(cents1, cents2, sum);
    // cout << sum.getCents() << endl;

    cout << (cents1 + cents2 + Cents(6) + Cents(10)).getCents() << endl;

    // 삼항 연산자, sizeof, scope 연산자는 오버로딩이 안됨!!!
    // 가급적이면 직관적으로 우선순위가 높은 순서대로 오버로딩을 하자

    return 0;
}