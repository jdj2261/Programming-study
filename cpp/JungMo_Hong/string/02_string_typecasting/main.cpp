#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
std::string ToString(T x)
{
    std::ostringstream osstream;
    osstream << x;
    return osstream.str();
}

template <typename T>
bool FromString(const std::string &str, T &x)
{
    std::istringstream isstream(str);
    return (isstream >> x) ? true : false;
}

int main()
{
    {
        std::string my_string("my string");
        // const char *my_string = "mystring";

        std::string second_string(my_string, 3, 2);
        std::cout << my_string << std::endl;
        std::cout << second_string << std::endl;
    }

    {
        std::vector<char> vec;
        for (auto e : "Today is a good day.")
            vec.push_back(e);

        std::string second_string(vec.begin(), vec.end());
        // std::string second_string(vec.begin(), std::find(vec.begin(), vec.end(), 'g'));
        std::cout << second_string << std::endl;
    }

    {
        // std::string my_str(std::to_string(4));
        std::string my_str("Hello");

        // float f = std::stof(my_str);
        // std::cout << my_str << std::endl;
        // std::cout << f << std::endl;

        double d;

        if (FromString(my_str, d))
            std::cout << d << std::endl;
        else
            std::cout << "Cannot convert string to double" << std::endl;
    }

    return 0;
}