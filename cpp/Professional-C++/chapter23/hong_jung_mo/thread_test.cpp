#include <chrono>
#include <vector>
#include <mutex>
#include <string>
#include <thread>
#include <iostream>

using namespace std;

int main()
{
    // cout << std::thread::hardware_concurrency() << endl;
    // cout << std::this_thread::get_id() << endl;
    const int num_pro = std::thread::hardware_concurrency();

    cout << std::this_thread::get_id() << endl;

    vector<std::thread> mythread;
    mythread.resize(num_pro);

    for (auto& e : mythread)
    {
        e = std::thread([](){
            cout << std::this_thread::get_id() << endl;
            while (true) {}});
    }

    for (auto& e : mythread)
        e.join();

}
