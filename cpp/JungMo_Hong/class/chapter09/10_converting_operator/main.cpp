#include <cassert>
#include <iostream>
using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    // 이전 버전에 사용했지만 지금은 사용 안하려고 할 경우
    Fraction(char) = delete;

    explicit Fraction(int num = 0, int den = 1)
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

void doSomething(Fraction frac)
{
    cout << frac << endl;
}

int main()
{
    // Fraction frac('c'); // delete 때문에 사용 못함.
    Fraction frac(7);
    doSomething(frac);
    // doSomething(7); // explicit을 사용하면 정확하게 넣어야 함.

    return 0;
}