#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived : public Base
{
public:
    int m_j = 1;

    virtual void print() override
    {
        cout << "I'm derived" << endl;
    }
};

void doSomething(Base &b)
{
    b.print();
}

int main()
{
    // Derived d;
    // Base &b = d;

    // // 복사가 되면 다형성 구현이 안됨.
    // // Base b;
    // // b = d;

    // b.print();

    // // Derived d;
    // // doSomething(d);

    Base b;
    Derived d;

    /*
    //std::vector<Base &> my_vec;   //error, vector는 레퍼런스 대입 불가능
    std::vector<Base *> my_vec;
    my_vec.push_back(&b);
    my_vec.push_back(&d);

    for (auto &ele : my_vec)
        ele->print();
    */

    // object slicing 방지

    std::vector<std::reference_wrapper<Base>> my_vec;
    my_vec.push_back(b);
    my_vec.push_back(d);

    for (auto &ele : my_vec)
        ele.get().print();
    return 0;
}