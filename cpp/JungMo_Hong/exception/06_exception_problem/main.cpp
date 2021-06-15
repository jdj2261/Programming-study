#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
    // 금지
    // 소멸자는 에러를 던질 수 없다.
    ~A()
    {
        // throw "error";
    }
};

int main()
{
    try
    {
        A a;

        int *i = new int[1000000];

        // smart pointer 사용 시 delete 불필요
        // memory 누수 문제 방지
        unique_ptr<int> up_i(i);

        // 메모리 누수 발생
        throw "error";
        // delete[] i;
    }
    catch (...)
    {
        std::cerr << "Catch" << '\n';
    }

    return 0;
}