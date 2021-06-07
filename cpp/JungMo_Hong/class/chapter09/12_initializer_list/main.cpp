#include <cassert>
#include <initializer_list>
#include <iostream>

using namespace std;

class IntArray
{
private:
    unsigned m_length;
    int *m_data = nullptr;

public:
    IntArray(unsigned length = 0)
        : m_length(length)
    {
        m_data = new int[length];
    }

    IntArray(const std::initializer_list<int> &list)
        : IntArray(list.size())
    {
        int count = 0;
        for (auto &ele : list)
        {
            m_data[count] = ele;
            ++count;
        }
        /*
        for (unsigned count = 0; count < list.size(); ++count)
            m_data[count] = list[count]; //error
        */
    }

    ~IntArray()
    {
        delete[] m_data;
    }

    friend std::ostream &operator<<(std::ostream &out, const IntArray &arr)
    {
        for (unsigned i = 0; i < arr.m_length; i++)
            out << arr.m_data[i] << " ";
        out << endl;
        return out;
    }

    IntArray &operator=(const IntArray &arr)
    {
        if (this == &arr)
            return *this;
        delete[] m_data;

        m_length = arr.m_length;

        if (arr.m_data != nullptr)
        {
            m_data = new int[m_length];
            for (int i = 0; i < m_length; ++i)
                m_data[i] = arr.m_data[i];
        }
        else
            m_data = nullptr;
        return *this;
    }
};

int main()
{
    int my_arr1[5] = { 1, 2, 3, 4, 5 };
    int *my_arr2 = new int[6]{ 1, 2, 3, 4, 5 };

    auto i1 = { 10, 20, 30 };

    // 아래처럼 쓰려면 initializer_list를 이용하자
    IntArray int_array{ 1, 2, 3, 4, 5 };
    // IntArray int_array = { 1, 2, 3, 4, 5 };
    IntArray int_array2;
    int_array2 = int_array;
    cout << int_array << endl;
    cout << int_array2 << endl;

    return 0;
}