#pragma once

#include <assert.h>
#include <initializer_list>
#include <iostream>

class IntArray
{
private:
    int m_length = 0;
    int *m_data = nullptr;

public:
    IntArray(unsigned length_in = 0)
        : m_length(length_in)
    {
        m_data = new int[m_length];
    }

    IntArray(const std::initializer_list<int> &list)
        : IntArray(list.size())
    {
        int count = 0;
        for (auto &element : list)
        {
            m_data[count] = element;
            ++count;
        }
    }

    ~IntArray()
    {
        delete[] m_data;
        m_data = nullptr;
    }

    friend std::ostream &operator<<(std::ostream &out, IntArray &arr)
    {
        for (unsigned i = 0; i < arr.m_length; i++)
            out << arr.m_data[i] << " ";
        out << std::endl;
        return out;
    }

    // friend std::ostream &operator=(std::ostream &out, IntArray &arr)
    // {
    // }

    void initialize(const unsigned &length);
    void reset();
    void resize(const unsigned &length);
    void insertBefore(const int &value, const int &ix);
    void remove(const int &ix);
    void push_back(const int &value);
};