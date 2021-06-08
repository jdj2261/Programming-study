#include <iostream>
using namespace std;

class A
{
public:
    void print() { cout << "A" << endl; }

    // covariant return Type
    virtual A *getThis()
    {
        cout << "A::getThis()" << endl;
        return this;
    }
};

class B : public A
{
public:
    // parameter가 다르면 overriding을 할 수가 없다.
    // override 키워드로 디버깅 시간을 줄인다.
    // void print(short x) { cout << "B" << endl; }
    void print() { cout << "B" << endl; }

    // 리턴타입이 다르지만 부모자식 관계 이므로 overriding이 가능함
    virtual B *getThis()
    {
        cout << "B::getThis()" << endl;
        return this;
    }

    // 자식 클래스에서 상속을 하지 못하게 막는다
    // void print(int x) final { cout << "B" << endl; }
};

class C : public B
{
public:
    virtual void print() { cout << "C" << endl; }
};

int main()
{
    A a;
    B b;

    A &ref = b;
    ref.print();

    b.getThis()->print();
    ref.getThis()->print();

    cout << typeid(b.getThis()).name() << endl;
    cout << typeid(ref.getThis()).name() << endl;

    return 0;
}