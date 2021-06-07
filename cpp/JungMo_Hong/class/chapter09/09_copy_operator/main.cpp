#include <cassert>
#include <iostream>
using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int num = 0, int den = 1)
        : m_numerator(num), m_denominator(den)
    {
        assert(den != 0);
    }

    // copy constructor
    // 복사를 못 하게 막으려면 private로 옮기면 됨
    Fraction(const Fraction &fraction)
        : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        cout << "Copy constructor called" << endl;
    }

    friend std::ostream &operator<<(std::ostream &out, const Fraction &f)
    {
        out << f.m_numerator << " / " << f.m_denominator << endl;
        return out;
    }
};

Fraction doSomething()
{
    Fraction temp(1, 2);
    cout << &temp << endl;
    return temp;
}

int main()
{
    // 주소가 같다. (컴파일러가 최적화 해줌)
    Fraction result = doSomething();
    cout << &result << endl;
    cout << result << endl;

    // Fraction frac(3, 5);
    // // Fraction fr_copy(frac);
    // // Fraction fr_copy = frac;

    // // 아래의 경우 복사 생성자 호출 안됨.
    // Fraction fr_copy(Fraction(3, 10));

    // cout << frac << " " << fr_copy << endl;

    return 0;
}