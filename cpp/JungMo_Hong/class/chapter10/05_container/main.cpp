#include "Array.h"
#include <array>
#include <iostream>
#include <vector>
int main()
{
    /*
    IntArray my_arr{1, 3, 5, 7, 9};
    my_arr.insertBefore(10, 1);     // 1, 10, 3, 5, 7, 9
    my_arr.remove(3);               // 1, 10, 3, 7, 9
    my_arr.push_back(13);           // 1, 10, 3, 7, 9, 13
    */
    // std::vector<int> int_vect;
    // std::array<int, 10> int_arr;

    int my_arr1[5] = { 1, 2, 3, 4, 5 };
    int *my_arry = new int[5]{ 1, 2, 3, 4, 5 };

    auto i1 = { 10, 20, 30 };

    for (const auto &ele : i1)
        std::cout << ele << " ";

    std::cout << std::endl;

    IntArray int_array{ 1, 2, 3, 4, 5 };
    IntArray int_array = { 1, 2, 3, 4, 5 };
    std::cout << int_array << std::endl;

    return 0;
}