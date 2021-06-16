#include <iostream>
using namespace std;

void doSomething(int &lref)
{
    cout << "L-value ref" << endl;
}

void doSomething(int &&rref)
{
    cout << "R-value ref" << endl;
}

int getResult()
{
    return 100 * 100;
}

int main()
{
    // l-value , r-value
    int x = 5;
    int y = getResult();
    const int cx = 6;
    const int cy = getResult();

    // L-value references
    int &lr1 = x; // Modifiable l-values
    // error
    // int &lr2 = cx; // Non-modifiable l-values
    // int &lr3 = 5;  // R-values

    const int &lr4 = x;
    const int &lr5 = cx;
    const int &lr6 = 5;

    // R-value references

    // error
    // int &&rr1 = x;
    // int &&rr2 = cx;

    int &&rr3 = 5; // R-values

    cout << rr3 << endl;
    rr3 = 10;
    cout << rr3 << endl;
    int &&rrr = getResult(); // R-values

    // error
    // const int &&rr4 = x;
    // const int &&rr5 = cx;

    const int &&rr6 = 5;

    // L-value reference parameters
    doSomething(x);

    // R-value reference parameters
    doSomething(5);
    doSomething(getResult());
}