#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main()
{
    {
        vector<int> container;
        for (int i = 0; i < 10; ++i)
            container.push_back(i);

        vector<int>::const_iterator itr;
        itr = container.begin();

        while (itr != container.end())
        {
            cout << *itr << " ";
            ++itr;
        }

        cout << endl;

        for (auto &e : container)
            cout << e << " ";
        cout << endl;

        for (auto itr = container.begin(); itr != container.end(); ++itr)
            cout << *itr << " ";

        cout << endl;
    }

    {
        list<int> container;
        for (int i = 0; i < 10; ++i)
            container.push_back(i);

        list<int>::const_iterator itr;
        itr = container.begin();

        while (itr != container.end())
        {
            cout << *itr << " ";
            ++itr;
        }

        cout << endl;

        for (auto &e : container)
            cout << e << " ";
        cout << endl;

        for (auto itr = container.begin(); itr != container.end(); ++itr)
            cout << *itr << " ";

        cout << endl;
    }

    {
        map<int, char> container;
        for (int i = 0; i < 10; ++i)
            container.insert(make_pair(i, char(i + 65)));

        for (auto itr = container.begin(); itr != container.end(); ++itr)
            cout << itr->first << " " << itr->second << endl;
        cout << endl;
    }
    return 0;
}