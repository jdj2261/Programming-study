#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std;

void test()
{
}

int main()
{
    const int num_pro = std::thread::hardware_concurrency();

    cout << std::this_thread::get_id() << endl;

    vector<std::thread> mythread;
    mythread.resize(num_pro);

    for (auto &e : mythread)
    {
        e = std::thread([]()
                        {
                            cout << std::this_thread::get_id() << endl;
                            while (true)
                            {
                            }
                        });
    }

    for (auto &e : mythread)
        e.join();
}
