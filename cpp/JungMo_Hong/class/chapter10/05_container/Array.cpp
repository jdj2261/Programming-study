#include "Array.h"

void IntArray::initialize(const unsigned &length)
{
    assert(length > 0);
    m_length = length;
    m_data = new int[m_length];
}

void IntArray::reset()
{
    if (m_data)
    {
        delete[] m_data;
        m_data = nullptr;
    }
    m_length = 0;
}

void IntArray::resize(const unsigned &length)
{
    if (length == 0)
        reset();
    if (m_length < length)
    {
        int *new_data = new int[length];
        for (size_t i = 0; i < length; ++i)
        {
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = nullptr;
    }
    m_length = length;
}

// void IntArray::insertBefore(const int &value, const int &ix)
// {
//     resize(m_length + 1);
//     for (int i = )
// }