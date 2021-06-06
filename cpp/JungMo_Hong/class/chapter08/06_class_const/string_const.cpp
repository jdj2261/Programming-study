#include <iostream>
#include <string>

using namespace std;

class Something
{

public:
    string m_value = "default";

    const string &getValue() const // const 가지고도 오버로딩을 다르게 할 수 있다.
    {
        cout << "const version" << endl;
        return m_value;
    }
    string &getValue()
    {
        cout << "non const version" << endl;
        return m_value;
    }
};

int main()
{
    Something something;
    something.getValue();

    const Something something2;
    something2.getValue(); // 값을 바꿀 수 없다.
    return 0;
}