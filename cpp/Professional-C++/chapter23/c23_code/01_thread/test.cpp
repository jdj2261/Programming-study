#include <thread>
#include <future>
#include <iostream>

int simplefunc(std::string a)
{ 
    return a.size();
}

int main()
{
      auto future = std::async(simplefunc, "hello world");
      int simple = future.get();
      std::cout << simple << std::endl;
      return simple;
}