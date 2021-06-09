#include "MyArray.h"
// #include "MyArray.cpp"   // 이렇게 하면 링킹 에러가 해결 되지만 사용하지 말자!!
int main()
{
    MyArray<double> my_array(10);

    for (int i = 0; i < my_array.getLength(); ++i)
        my_array[i] = i + 65;

    my_array.print();

    return 0;
}