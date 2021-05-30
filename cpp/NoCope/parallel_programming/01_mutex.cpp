#include <thread>
#include <mutex>
#include <queue>

// int crntScore = 0;
std::queue<Job> jobQueue;
std::mutex gMutex;

void add(int num)
{
    // std::lock_guard<std::mutex> lock(gMutex);
    std::scoped_lock<std::mutex> lock(gMutex); // 이걸 추천
    jobQueue.emplace_back(job);
    // scope 밖으로 빠져나가면 자동으로 해제
    // gMutex.lock();
    crntScore += num;
    // gMutex.unlock();    // 실수로 까먹을 수 있음. RAII
}

job pop()
{
    jobQueue.pop
    return job
}

int main()
{
    std::thread t1(add, 5);
    std::thread t2(add, -10);

    return 0;
}
