#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int &getCents() { return m_cents; }

    Cents operator+(const Cents &c2)
    {
        return Cents(this->m_cents + c2.getCents());
    }

    Cents operator-() const
    {
        return Cents(-m_cents);
    }

    bool operator!() const
    {
        return (m_cents == 0) ? true : false;
    }

    friend bool operator==(const Cents &c1, const Cents &c2)
    {
        return c1.m_cents == c2.m_cents;
    }

    // < 연산자를 써야 한다!!
    friend bool operator<(const Cents &c1, const Cents &c2)
    {
        return c1.m_cents < c2.m_cents;
    }

    friend std::ostream &operator<<(std::ostream &out, const Cents &cents)
    {
        out << cents.m_cents;
        return out;
    }
};

int main()
{
    std::random_device rd;
    std::mt19937 g(rd());

    vector<Cents> arr(20);
    for (unsigned i = 0; i < 20; i++)
    {
        arr[i].getCents() = i;
    }

    std::shuffle(arr.begin(), arr.end(), g);

    for (auto &e : arr)
        cout << e << " ";
    cout << endl;

    std::sort(begin(arr), end(arr));
    // 크기 비교하는 연산자 오버로딩 해야함.
    for (auto &e : arr)
        cout << e << " ";
    cout << endl;

    // Cents cents1(6);
    // Cents cents2(6);

    // if (cents1 == cents2)
    // {
    //     cout << "Equal" << endl;
    // }

    return 0;
}