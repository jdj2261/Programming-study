#include "Monster.h"
#include <iostream>

using namespace std;

int main()
{
    Monster mon1("Sanson", Position2D(0, 0));
    cout << mon1 << endl;

    Monster mon2("Parsival", Position2D(0, 0));
    // while(1)
    {
        mon1.moveTo(Position2D(1, 1));
        cout << mon1 << endl;
    }

    Monster mon3("Test", Position2D(0, 0));

    cout << mon1 << endl;
    cout << mon3 << endl;

    return 0;
}