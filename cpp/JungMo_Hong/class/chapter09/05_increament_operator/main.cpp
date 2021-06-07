#include <iostream>

using namespace std;

class Digit
{
private:
    int m_digit;

public:
    Digit(int digit = 0) : m_digit(digit) {}

    // prefix
    Digit &operator++()
    {
        ++m_digit;
        return *this;
    }

    // postfix, dumy로 int를 넣어줘야 함 (외우기!)
    Digit operator++(int)
    {
        Digit temp(m_digit);
        ++(*this);
        return temp;
    }

    friend std::ostream &
    operator<<(std::ostream &out, const Digit &digit)
    {
        out << digit.m_digit;
        return out;
    }
};

int main()
{
    Digit d(5);

    cout << ++d << endl;
    cout << d << endl;

    cout << d++ << endl;
    cout << d << endl;

    return 0;
}