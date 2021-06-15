#include <iostream>
using namespace std;

class Exception
{
public:
    void report()
    {
        cerr << "Exception report" << endl;
    }
};

class ArrayException : public Exception
{
public:
    void report()
    {
        cerr << "Array exception" << endl;
    }
};

class MyArray
{
private:
    int m_data[5];

public:
    int &operator[](const int &index)
    {
        // if (index < 0 || index >= 5)
        //     throw -1;
        if (index < 0 || index >= 5)
            throw ArrayException();
        return m_data[index];
    }
};

void doSomething()
{
    MyArray my_array;

    try
    {
        my_array[100];
    }
    catch (const int &x)
    {
        std::cerr << "Exception" << x << '\n';
    }
    // catch (ArrayException &e)
    // {
    //     cout << "doSomething()" << endl;
    //     e.report();
    //     throw e;
    // }
    catch (Exception &e)
    {
        cout << "doSomething()" << endl;
        e.report();
        // throw e;
        throw; // 잘림현상 제거
    }
}

int main()
{
    try
    {
        doSomething();
    }
    catch (ArrayException &e)
    {
        std::cerr << "main()" << '\n';
        e.report();
    }
    catch (Exception &e)
    {
        cout << "main()" << endl;
        e.report();
    }

    return 0;
}