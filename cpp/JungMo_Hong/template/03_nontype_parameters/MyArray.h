#pragma once
#include <assert.h>
#include <iostream>

template <typename T, unsigned int T_SIZE>
class MyArray
{
private:
    // int m_length;
    T *m_data;

public:
    MyArray()
    {
        m_data = new T[T_SIZE];
    }

    ~MyArray()
    {
        reset();
    }

    void reset()
    {
        delete[] m_data;
        m_data = nullptr;
    }

    T &operator[](int index)
    {
        assert(index >= 0 && index < T_SIZE);
        return m_data[index];
    }

    int getLength() const { return T_SIZE; }

    // non type parameter를 넣을 경우에 cpp파일에 따로 빼지 않고 h파일에 넣는다.
    void print()
    {
        for (int i = 0; i < T_SIZE; ++i)
            std::cout << m_data[i] << " ";
        std::cout << std::endl;
    }
};
