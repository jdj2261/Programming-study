#pragma once
#include <iostream>

template <class T>
class Storage
{
private:
    T m_value;

public:
    Storage(T value)
    {
        m_value = value;
    }

    ~Storage()
    {
    }

    void print()
    {
        std::cout << m_value << std::endl;
    }
};

// 템플릿 특수화를 할 경우 헤더파일에 집어 넣는다.
template <>
void Storage<double>::print()
{
    std::cout << "Double Type ";
    std::cout << std::scientific << m_value << std::endl;
}