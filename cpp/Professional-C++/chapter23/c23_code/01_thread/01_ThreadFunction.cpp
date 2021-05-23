#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void counter(int id, int numIterations)
{
	mutex mtx;
	for (int i = 0; i < numIterations; ++i) 
	{
		mtx.lock();
		cout << "Counter " << id << " has value " << i << endl;
		mtx.unlock();
	}	
}


int main()
{

	thread t1(counter, 1, 6);
	thread t2(counter, 2, 4);
	t1.join();
	t2.join();
	return 0;
}