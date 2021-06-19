#include "AutoPtr.h"
#include "Resource.h"
#include "Timer.h"
#include <iostream>
using namespace std;

void doSomething(std::unique_ptr<Resource> res)
{
}

int main()
{

    // 함수 파라미터에 넣을 때 make_unique를 쓰자.
    // doSomething(std::make_unique<Resource>(100000));

    // Resource *res = new Resource(3);
    // res->setAll(1);

    {
        // make shared를 이용하는게 좋다.
        auto ptr1 = std::make_shared<Resource>(3);
        ptr1->setAll(1);
        // std::shared_ptr<Resource> ptr1(res);

        ptr1->print();

        {
            // std::shared_ptr<Resource> ptr2(ptr1);

            // ptr2가 res의 소유권을 가지고 있는 것을 모름.
            // 문제가 생김.
            // std::shared_ptr<Resource> ptr2(res);

            auto ptr2 = ptr1;

            ptr2->setAll(3);
            ptr2->print();

            std::cout << "Going out of the block" << std::endl;
        }

        // 마지막 쉐어드포인터가 소멸이 될때 리소스를 지운다.
        // 유니크포인터보다 자유롭기 때문에 편하게 사용할 수 있다.
        ptr1->print();
        std::cout << "Going out of the outer block" << std::endl;
    }

    std::getchar();
    return 0;
}
