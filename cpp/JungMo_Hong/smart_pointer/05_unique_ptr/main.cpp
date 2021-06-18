#include "AutoPtr.h"
#include "Resource.h"
#include "Timer.h"
#include <iostream>
using namespace std;

auto doSomething()
{
    auto res1 = std::make_unique<Resource>(5);
    return res1;
    // return std::unique_ptr<Resource>(new Resource(5));
    // return std::make_unique<Resource>(5);
}

// auto doSomething2(std::unique_ptr<Resource> &res)
// {
//     res->setAll(10);
//     res->print();
// }

// std::move 사용할 것!
auto doSomething2(std::unique_ptr<Resource> res)
{
    res->setAll(10);
    res->print();

    return res;
}

// 선호하지는 않음.
//auto doSomething2(Resource *res)
//{
//    res->setAll(10);
//    res->print();
//}

int main()
{
    // {
    //     // AutoPtr<Resource> res1(new Resource(1000000));
    //     std::unique_ptr<Resource> res(new Resource(10000000));

    //     // delete res1;
    // }

    // {
    //     std::unique_ptr<int> upi(new int);

    //     // std::unique_ptr<Resource> res1(new Resource(5));
    //     auto res1 = std::make_unique<Resource>(5);
    //     // auto res1 = doSomething();

    //     res1->setAll(5);
    //     res1->print();

    //     std::unique_ptr<Resource> res2;

    //     std::cout << std::boolalpha;
    //     std::cout << static_cast<bool>(res1) << std::endl;
    //     std::cout << static_cast<bool>(res2) << std::endl;

    //     // unique_ptr은 복사가 안됨!!
    //     // res2 = res1;
    //     res2 = std::move(res1);
    //     std::cout << std::boolalpha;
    //     std::cout << static_cast<bool>(res1) << std::endl;
    //     std::cout << static_cast<bool>(res2) << std::endl;

    //     if (res1 != nullptr)
    //         res1->print();
    //     if (res2 != nullptr)
    //         res2->print();
    // }

    {
        auto res1 = std::make_unique<Resource>(5);
        res1->setAll(1);
        res1->print();

        std::cout << std::boolalpha;
        std::cout << static_cast<bool>(res1) << std::endl;

        // 함수에 &를 꼭 써야 함
        // doSomething2(res1);

        // 함수에 &를 안 쓸 경우
        // doSomething2(std::move(res1));

        // res1을 사용하고 싶으면 반환하면 됨
        // res1 = doSomething2(std::move(res1));

        // void doSomething2 (Resource *res)
        // 이렇게 이용할 경우
        doSomething2(res1.get());
        std::cout << std::boolalpha;
        std::cout << static_cast<bool>(res1) << std::endl;

        res1->print();
    }

    {
        Resource *res = new Resource;
        std::unique_ptr<Resource> res1(res);

        // res2에 주면 안됨! 소유권은 한개만!!
        // std::unique_ptr<Resource> res2(res);

        // unique_ptr 사용 시 Delete 사용 하면 안됨
        // delete res;
    }
}
