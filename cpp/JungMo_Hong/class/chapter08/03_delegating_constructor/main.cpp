#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    int m_id;
    string m_name;

public:
    Student(const string &name_in)
        // : m_id(0), m_name(name_in)
        : Student(0, name_in) // 위임 생성자(c++ 17), 매개변수를 여러번 초기화하는 불필요를 없애기 위해 위임 생성자를 이용한다.
    //init() 함수로 초기화 하는 경우도 있다.
    {
    }

    Student(const int &id_in, const string &name_in)
        : m_id(id_in), m_name(name_in)
    {
    }

    void print()
    {
        cout << m_id << " " << m_name << endl;
    }
};

int main()
{
    Student st1(0, "TT");
    st1.print();

    Student st2("SS");
    st2.print();

    return 0;
}