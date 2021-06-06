#include <iostream>
#include <string>

using namespace std;

class Friend
{
public:
    string m_name;
    string m_address;
    int age;
    double height;
    double weight;

    void print()
    {
        cout << m_name << " " << m_address << " " << age << " " << height << " " << weight << endl;
    }
};

int main()
{
    Friend jj{ "DaeJong", "Seoul", 27, 174, 77 };
    jj.print();

    return 0;
}