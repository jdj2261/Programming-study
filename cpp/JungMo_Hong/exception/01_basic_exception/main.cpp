#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    double x;
    cin >> x;

    try
    {
        if (x < 0.0)
            throw std::string("Negative input");
        cout << std::sqrt(x) << endl;
    }
    catch (int e)
    {
        cerr << e << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}