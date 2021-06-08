#pragma once

#include <cassert>
#include <initializer_list>
#include <iostream>
// TODO
// 1. initializer_list Constructor
// 2. assignment operator
// 3. << operator
// 4. Destructor
class IntArray
{
private:
    unsigned m_length;
    int *m_data = nullptr;

public:
    IntArray(unsigned length = 0);
    IntArray(const std::initializer_list<int> &list);
    IntArray(const IntArray &arr);
    IntArray &operator=(const IntArray &arr);
    ~IntArray()
    {
        delete[] m_data;
        m_data = nullptr;
    }

    friend std::ostream &operator<<(std::ostream &out, const IntArray &arr);

    int size() const { return m_length; }
    void deepCopy(const IntArray &arr);
    void reset();
    void resize(const unsigned &length);
    void insertBefore(const unsigned &index, const int &data);
    void remove(const unsigned &index);
    void push_back(const int &data);
    void pop();
};