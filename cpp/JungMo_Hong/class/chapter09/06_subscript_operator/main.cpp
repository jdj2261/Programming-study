#include <cassert>
#include <iostream>
using namespace std;

// class IntList
// {
// private:
//     int m_list[10];

// public:
//     void setItem(int index, int value)
//     {
//         m_list[index] = value;
//     }
//     int getItem(int index)
//     {
//         return m_list[index];
//     }

//     int *getList()
//     {
//         return m_list;
//     }
// };

class IntList
{
private:
    int m_list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

public:
    int &operator[](const int index)
    {
        assert(index >= 0);
        assert(index < 10);

        return m_list[index];
    }

    const int &operator[](const int index) const
    {
        return m_list[index];
    }
};

int main()
{
    IntList my_list;
    // const IntList my_list; // const를 쓸 경우 const member function을 만들자.
    // my_list[3] = 10;
    cout << my_list[3] << endl;

    IntList *list = new IntList;
    // list[3] = 20; // Not OK
    (*list)[3] = 10; // OK

    // IntList my_list;
    // my_list.setItem(3, 1);
    // cout << my_list.getItem(3) << endl;
    // my_list.getList()[3] = 10;
    // cout << my_list.getList()[3] << endl;

    return 0;
}