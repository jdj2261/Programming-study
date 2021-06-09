#include "Storage.h"
#include <iostream>

using namespace std;

template <typename T>
T getMax(T x, T y)
{
    return (x > y) ? x : y;
}

template <>
char getMax(char x, char y)
{
    cout << "Warning : char" << endl;
    return (x > y) ? x : y;
}

int main()
{
    cout << getMax(1, 2) << endl;
    cout << getMax('a', 'b') << endl;

    Storage<int> nValue(5);
    Storage<double> dValue(5.5);

    nValue.print();
    dValue.print();

    return 0;
}