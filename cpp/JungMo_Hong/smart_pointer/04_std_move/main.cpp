#include "AutoPtr.h"
#include "Resource.h"
#include "Timer.h"
#include <iostream>
using namespace std;

template <class T>
void MySwap(T &a, T &b)
{
    // T tmp = a;
    // a = b;
    // b = tmp;

    T tmp{ std::move(a) };
    a = std::move(b);
    b = std::move(tmp);
}

int main()
{
    {
        AutoPtr<Resource> res1(new Resource(1000000));

        cout << res1.m_ptr << endl;

        // R-value로 return
        // move semantics
        // 앞으로 res1를 못 쓰고 res2만 쓸 수 있음
        AutoPtr<Resource> res2 = std::move(res1);

        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
    }

    {
        AutoPtr<Resource> res1(new Resource(3));
        res1->setAll(3);

        AutoPtr<Resource> res2(new Resource(5));
        res2->setAll(5);

        res1->print();
        res2->print();

        // MySwap(res1, res2);

        // res1->print();
        // res2->print();
    }

    // {
    //     vector<string> v;
    //     string str = "Hello";

    //     v.push_back(str);

    //     cout << str << endl;
    //     cout << v[0] << endl;

    //     v.push_back(std::move(str));

    //     cout << str << endl;
    //     cout << v[0] << " " << v[1] << endl;
    // }

    // {
    //     std::string x{ "abc" };
    //     std::string y{ "de" };

    //     std::cout << "x: " << x << std::endl;
    //     std::cout << "y: " << y << std::endl;

    //     MySwap(x, y);

    //     std::cout << "x: " << x << std::endl;
    //     std::cout << "y: " << y << std::endl;
    // }
    return 0;
}