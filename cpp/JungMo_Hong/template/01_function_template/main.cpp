#include "Cents.h"
#include <iostream>

// template <class T>
template <typename T>
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << getMax(1, 2) << std::endl;
    std::cout << getMax(3.14, 1.592) << std::endl;
    std::cout << getMax(1.0f, 3.4f) << std::endl;
    std::cout << getMax('a', 'c') << std::endl;
    std::cout << getMax(Cents(10), Cents(7)) << std::endl;
    return 0;
}