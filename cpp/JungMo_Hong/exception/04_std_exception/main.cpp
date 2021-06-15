#include <exception>
#include <iostream>
#include <string>

class CustomException : public std::exception
{
public:
    // what() 오버라이드
    // noexcept : 이 안에서는 except를 던지지 않겠다.
    const char *what() const noexcept override
    {
        return "Custom exception";
    }
};

int main()
{
    try
    {
        // std::string s;
        // s.resize(-1);

        // throw std::runtime_error("Bad thing happened");
        throw CustomException();
    }
    catch (std::exception &exception)
    {
        std::cout << typeid(exception).name() << std::endl;
        std::cerr << exception.what() << std::endl;
    }

    return 0;
}