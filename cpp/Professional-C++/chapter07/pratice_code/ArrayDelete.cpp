#include <iostream>

using namespace std;

class Simple
{
public:
    Simple()
    {
        cout << "constructor called!" << endl;
    }
    ~Simple()
    {
        cout << "destructor called!" << endl;
    }
};

int main()
{
    Simple *mySimpleArray = new Simple[4];

    delete[] mySimpleArray;
    mySimpleArray = nullptr;

    const size_t size = 4;
    Simple **mySimplePtrArray = new Simple *[size];

    for (size_t i = 0; i < size; i++)
    {
        mySimplePtrArray[i] = new Simple();
    }

    for (size_t i = 0; i < size; i++)
    {
        delete mySimplePtrArray[i];
    }

    delete[] mySimplePtrArray;
    mySimplePtrArray = nullptr;

    return 0;
}