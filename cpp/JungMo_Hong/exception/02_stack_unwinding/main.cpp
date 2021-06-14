#include <iostream>
using namespace std;

void last()
{
    cout << "last " << endl;
    cout << "Throws exception" << endl;

    throw -1;

    cout << "End last " << endl;
}

void third()
{
    cout << "Third" << endl;
    last();
    cout << "End third" << endl;
}

void second()
{
    cout << "Second" << endl;
    try
    {
        third();
    }
    catch (double)
    {
        std::cerr << "Second caught double exception" << '\n';
    }

    last();
    cout << "End third" << endl;
}

void first()
{
    cout << "First" << endl;
    try
    {
        second();
    }
    catch (int)
    {
        std::cerr << "First caught double exception" << '\n';
    }

    last();
    cout << "End third" << endl;
}

int main()
{
    cout << "Start" << endl;
    try
    {
        first();
    }
    catch (int)
    {
        std::cerr << "main caught double exception" << '\n';
    }
    catch (...) // catch all handler
    {
        cerr << "main caught ellpses exception" << endl;
    }

    cout << "End main" << endl;

    return 0;
}