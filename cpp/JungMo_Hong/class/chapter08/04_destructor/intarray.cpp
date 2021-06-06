#include <iostream>
using namespace std;

class IntArray
{
private:
    int *m_arr = nullptr;
    int m_length = 0;

public:
    IntArray(const int &length_in)
    {
        m_length = length_in;
        m_arr = new int[m_length];

        cout << "Constructor " << endl;
    }

    // 동적할당 시 delete를 하기에 용이함.
    // vector 쓰는 것을 추천함.
    ~IntArray()
    {
        delete[] m_arr;
        m_arr = nullptr;
    }

    int size() { return m_length; }
};

int main()
{
    while (true)
    {
        IntArray my_int_arr(10000);
    }
    return 0;
}