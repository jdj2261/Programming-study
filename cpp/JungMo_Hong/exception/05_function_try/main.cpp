#include <iostream>
using namespace std;

class A
{
private:
    int m_x;

public:
    A(int x) : m_x(x)
    {
        if (x <= 0)
            throw 1;
    }
};

class B : public A
{
public:
    // B(int x)
    //     : A(x)
    // {
    // }

    // function try
    // 생성자 호출할 때 에러 확인
    B(int x)
    try : A(x)
    {
    }
    catch (...)
    {
        cout << "Catch in B constructor " << endl;
        throw;
    }
};

void doSomething()
try
{
    throw -1;
}
catch (const std::exception &e)
{
    std::cerr << e.what() << '\n';
}

int main()
{
    try
    {
        // doSomething();
        B b(0);
    }
    catch (...)
    {
        std::cerr << "Catch in main()" << '\n';
    }
}