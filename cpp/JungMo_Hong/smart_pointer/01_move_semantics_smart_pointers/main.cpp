#include "AutoPtr.h"
#include "Resource.h"
#include <iostream>
using namespace std;

// RAII : resource acquisition is initialization
// void doSomething()
// {
//     try
//     {
//         // Resource *res = new Resource;
//         AutoPtr<Resource> res(new Resource);

//         return;

//         if (true)
//         {
//             // delete res;
//             return;
//         }

//         // delete res;
//     }
//     catch (...)
//     {
//     }

//     return;
// }

int main()
{
    // doSomething();
    {
        AutoPtr<Resource> res1(new Resource);
        AutoPtr<Resource> res2;

        cout << std::boolalpha;

        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;

        // 소유권 이전 (move semantics)
        res2 = res1;

        cout << res1.m_ptr << endl;
        cout << res2.m_ptr << endl;
    }

    // value semantics (copy semantics)
    // reference semantics (pointer)
    // move semantics (move)

    /*
    // syntax(문법적인 오류) vs semantics(내부적인 의미)
    int x = 1, y = 1;
    x + y;

    string str("Hello"), str2("World");
    str + str2; // append
    */

    return 0;
}