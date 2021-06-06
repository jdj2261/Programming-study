#include <iostream>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    // Fraction()
    // {
    //     m_numerator = 1;
    //     m_denominator = 1;
    //     cout << "default constructor init" << endl;
    // }

    // 주의 !!!!!!!
    // 모든 매개변수를 default로 정의할 경우
    // default 생성자로 생각 될 수 있으니 둘 중 하나를 써야한다.
    Fraction(const int &num_in = 1, const int &den_in = 1)
        : m_numerator(num_in),
          m_denominator(den_in)
    {
        cout << "Construct init" << endl;
    }

    void print()
    {
        cout << m_numerator << " / " << m_denominator << endl;
    }
};

int main()
{
    // 매개변수가 없을 경우 ()를 쓰지 않는다.
    // Fraction frac;
    Fraction frac(2, 3);

    // uniform 초기화는 타입 변환을 허용하지 않는다.
    Fraction frac2{ 3.2, 3 };
    frac.print();
    frac2.print();
    return 0;
}