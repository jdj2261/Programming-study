#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

function<int(void)> test(int x)
{
    return [x]{return 2 * x;};
}

int main()
{
    double data = 2.0;
    // 값으로 캡처
    auto capturingLambda = [data]()mutable{ 
        data *= 2;
        std::cout << "Data = " << data  << std::endl; };
    // 레퍼런스로 캡처
    auto Lambdafunc2 = [&data]{std::cout << data * 2 << std::endl;};

    capturingLambda();
    Lambdafunc2();

    vector<int> ints{ 11, 55, 101, 200 };
    vector<double> doubles{ 11.1, 55.5, 200.2 };
    // 100을 넘는 값을 찾는 제네릭 람다 표현식 정의
    auto isGreaterThan100 = [](auto i) {return i > 100; };
    auto iter = find_if(cbegin(ints), cend(ints), isGreaterThan100);
    if (iter != cend(ints))
        cout << "Found a value > 100 : " << *iter << endl;
    auto iter2 = find_if(cbegin(doubles), cend(doubles), isGreaterThan100);
    if (iter2 != cend(doubles))
        cout << "Found a value > 100 : " << *iter2 << endl;

    double pi = 3.1415;
    auto my = [myCapture = "Pi: ", pi]{ cout << myCapture << pi << endl;};
    my();

    auto myPtr = std::make_unique<double>(3.1415);
    auto myLambda = [p = std::move(myPtr)]{ cout << *p << endl;};
    myLambda();

    auto fn = test(5);
    cout << fn() << endl;

    return 0;
}
