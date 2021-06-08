#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {
    }

    string getName() { return m_name; }

    // pure virtual function
    // 자식 클래스에서는 반드시 구현해라
    virtual void speak() const = 0;
};

// the body of the pure virtual function
// 쓸모가 없음
// void Animal::speak() const
// {
//     cout << m_name << " ??? " << endl;
// }

class Cat : public Animal
{
public:
    Cat(string name)
        : Animal(name)
    {
    }

    void speak() const
    {
        cout << m_name << " Meow" << endl;
    }
};

class Dob : public Animal
{
public:
    Dob(string name)
        : Animal(name)
    {
    }

    void speak() const
    {
        cout << m_name << " Woof" << endl;
    }
};

class Cow : public Animal
{
public:
    Cow(string name)
        : Animal(name)
    {
    }

    void speak() const
    {
        cout << m_name << " Mooo" << endl;
    }
};

int main()
{
    // 추상 클래스 함수는 만들 수 없음
    // Animal ani("hi"); // error

    // override를 하지 않으면 error
    Cow cow("hello"); // error
    cow.speak(  );
    return 0;
}