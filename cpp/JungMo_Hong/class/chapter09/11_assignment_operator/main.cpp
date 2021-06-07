#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

// swallo, deep copy 사용이 헷갈리니 string 사용하면 된다.
class MyString
{
public:
    char *m_data = nullptr;
    int m_length = 0;

public:
    MyString(const char *source = "")
    {
        assert(source);

        m_length = std::strlen(source) + 1;
        m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
            m_data[i] = source[i];
        m_data[m_length - 1] = '\0';
    }

    // 임시로 복사생성자 사용을 막으려면 delete를 사용한다.
    // MyString(const MyString &source) = delete;
    // copy constructor
    MyString(const MyString &source)
    {
        cout << "Copy constructor " << endl;
        m_length = source.m_length;

        if (source.m_data != nullptr)
        {
            // 깊은 복사
            m_data = new char[m_length];
            for (int i = 0; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;
    }

    // assignment operator
    MyString &operator=(const MyString &source)
    {
        // shallow copy
        // *this->m_data = source.m_data;
        // this->m_length = source.m_length;

        cout << "Assignment operator " << endl;

        // prevent self-assignment
        if (this == &source)
            return *this;

        delete[] m_data;

        m_length = source.m_length;

        if (source.m_data != nullptr)
        {
            m_data = new char[m_length];
            for (int i = 0; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;

        return *this;
    }

    ~MyString()
    {
        delete[] m_data;
    }

    char *getString() { return m_data; }
    int getLength() { return m_length; }
};

int main()
{
    MyString hello("hello");

    // cout << (int *)hello.m_data << endl;
    // cout << hello.getString() << endl;

    // {
    //     // 복사 생성자 호출
    //     MyString copy = hello;
    //     cout << (int *)copy.m_data << endl;
    //     cout << copy.getString() << endl;
    // }

    // cout << hello.getString() << endl;

    MyString st1 = hello; // Copy constructor
    // MyString st1(hello);  // Copy constructor
    MyString str2; // Assignment operator
    str2 = hello;

    return 0;
}