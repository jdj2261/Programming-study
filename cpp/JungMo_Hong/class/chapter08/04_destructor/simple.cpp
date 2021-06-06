#include <iostream>
using namespace std;

class Simple
{
private:
    int m_id;

public:
    Simple(const int &id_in)
    {
        this->setID(id_in);
        // (*this).setID(id_in);
        cout << this << endl;
    }

    // ~Simple()
    // {
    //     cout << "Destructor" << m_id << endl;
    // }

    void setID(const int &id_in)
    {
        m_id = id_in;
    }

    int getID() const
    {
        return m_id;
    }
};

int main()
{
    Simple s1(1), s2(2);
    s1.setID(2);
    s2.setID(4);

    cout << &s1 << " " << &s2 << endl;
    // Simple s1(0);
    // Simple *s1 = new Simple(0);
    // Simple s2(1);
    // delete s1;

    return 0;
}