#include <chrono>
#include <vector>
#include <mutex>
#include <string>
#include <thread>
#include <iostream>

using namespace std;



int main()
{
    int shared_memory(0);
    auto count_func = [&](){
        for (int i = 0 ; i < 1000; ++i)
        {
            this_thread::sleep_for(std::chrono::milliseconds(1));
            shared_memory++;
        }
    };

    thread t1 = thread(count_func);
    thread t2 = thread(count_func);

    t1.join();
    t2.join();

    cout << "After" << endl;
    cout << shared_memory << endl;
}