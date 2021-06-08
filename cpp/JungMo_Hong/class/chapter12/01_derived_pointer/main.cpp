#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string m_name;

public:
    Animal(string name)
        : m_name(name)
    {
    }

    string getName() { return m_name; }
    virtual void speak() const
    {
        cout << m_name << " ??? " << endl;
    }
};

class Cat : public Animal
{
public:
    Cat(string name)
        : Animal(name)
    {
    }

    void speak() const
    {
        cout << m_name << " Meow " << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string name) : Animal(name) {}

    void speak() const
    {
        cout << m_name << " Woof " << endl;
    }
};

int main()
{
    Cat cats[] = { Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
    Dog dogs[] = { Dog("dog1"), Dog("dog2") };

    for (int i = 0; i < 5; ++i)
        cats[i].speak();

    for (int i = 0; i < 5; ++i)
        dogs[i].speak();

    Animal *my_animals[] = {
        &cats[0],
        &cats[1],
        &cats[2],
        &cats[3],
        &cats[4],
        &dogs[0],
        &dogs[1],
    };

    // 다형성
    // virtual을 사용하면 부모 클래스의 함수인데 자식 클래스처럼 사용 할 수 있다.
    for (int i = 0; i < 7; ++i)
        my_animals[i]->speak();
}