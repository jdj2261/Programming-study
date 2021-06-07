#include "IntArray.h"

IntArray::IntArray(unsigned length)
    : m_length(length)
{
    m_data = new int[length];
}

IntArray::IntArray(const std::initializer_list<int> &list)
    : IntArray(list.size())
{
    int count = 0;
    for (auto &ele : list)
    {
        m_data[count] = ele;
        ++count;
    }
}

IntArray::IntArray(const IntArray &arr)
{
    m_length = arr.m_length;
    if (arr.m_data != nullptr)
    {
        m_data = new int[m_length];
        for (int i = 0; i < m_length; ++i)
            m_data[i] = arr.m_data[i];
    }
    else
        m_data = nullptr;
}

IntArray &IntArray::operator=(const IntArray &arr)
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

std::ostream &operator<<(std::ostream &out, const IntArray &arr)
{
    for (unsigned i = 0; i < arr.m_length; ++i)
        out << arr.m_data[i] << " ";
    return out;
}

void IntArray::reset()
{
    m_length = 0;
    if (m_data)
    {
        delete[] m_data;
        m_data = nullptr;
    }
}

void IntArray::resize(const unsigned &length)
{
    if (length == 0)
        reset();

    std::cout << "length : " << length << std::endl;

    if (m_length == length)
        return;
    else
    {
        int *tmp = new int[length]();
        for (int i = 0; i < m_length; ++i)
            tmp[i] = m_data[i];
        delete[] m_data;
        m_data = tmp;
    }
    m_length = length;
}

void IntArray::insertBefore(const unsigned &index, const int &data)
{
    assert(index >= 0);
    resize(m_length + 1);

    for (int i = m_length - 1; i > index; i--)
    {
        m_data[i] = m_data[i - 1];
    }

    m_data[index] = data;
}

void IntArray::remove(const unsigned &index)
{
    assert(index < m_length);
    for (int i = index; i < m_length - 1; ++i)
        m_data[i] = m_data[i + 1];
    resize(--m_length);
}

void IntArray::push_back(const int &data)
{
    resize(m_length + 1);
    m_data[m_length - 1] = data;
}

void IntArray::pop()

{
    assert(m_length > 0);
    resize(--m_length);
}

int main()
{
    using namespace std;
    IntArray int_array;

    int_array = { 1, 2, 3, 4, 5 };
    cout << int_array << endl;
    cout << int_array.size() << endl;

    // int_array.remove(0);
    // cout << int_array << endl;
    // cout << int_array.size() << endl;

    int_array.resize(3);
    cout << int_array << endl;
    cout << int_array.size() << endl;

    int_array.insertBefore(0, 1);
    cout << int_array << endl;
    cout << int_array.size() << endl;

    int_array.push_back(1);
    cout << int_array << endl;
    cout << int_array.size() << endl;

    // int_array.pop();
    // cout << int_array << endl;
    // // cout << "size : " << int_array.size();
    return 0;
}