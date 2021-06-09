#pragma once
#include <assert.h>
#include <iostream>

template <typename T>
class MyArray
{
private:
    int m_length;
    T *m_data;

public:
    MyArray()
        : m_length(0),
          m_data(nullptr)
    {
    }

    MyArray(int length)
    {
        m_data = new T[length];
        m_length = length;
    }

    ~MyArray()
    {
        reset();
    }

    void reset()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    T &operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }

    void print();
};

// template <class T>
// void MyArray<T>::print()
// {
//     for (int i = 0; i < m_length; ++i)
//         std::cout << m_data[i] << " ";
//     std::cout << std::endl;
// }