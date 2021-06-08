#include <iostream>

using namespace std;

class Mother
{
public:
    int m_i;

    Mother(const int &i_in = 0)
        : m_i(i_in)
    {
        cout << "Mother construction" << endl;
    }
};

class Child : public Mother
{
public:
    double m_d;

    Child()
        : Mother(1024), m_d(1.0)
    {
        cout << "Child construction" << endl;
    }
};

int main()
{
    // Mother constructor 생성 후 Child constructor 생성
    Child c1;
    return 0;
}