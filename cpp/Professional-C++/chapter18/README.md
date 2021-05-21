# Chapter-18. 표준 라이브러리 알고리즘 마스터하기

<details>
  <summary>18.3. 람다 표현식</summary> 

- 람다 표현식이란 함수나 함수 객체를 별도로 정의하지 않고, 필요한 지점에서 곧바로 함수를 직접 만들어 쓸 수 있는 일종의 익명 함수이다.

  <details>
    <summary>18.3.1 문법</summary> 

  - 람다 선언자라 부르는 대괄호 []로 시작하고, 그 뒤에 본문을 담는 중괄호 {}가 나온다.

    람다 표현식은 auto 타입 변수인 basicLambda에 대입된다.

    ~~~c++
    auto basicLambda = []{ cout << "Hello from Lambda" << endl; };
    basicLambda();
    >>> Hello from Lambda
    ~~~

  - 매개변수를 받을 수 있다.

    ~~~c++
    auto parametersLambda =
        [](int value){cout << value << endl;};
    parametersLambda(42);
    ~~~

  - 람다 표현식은 값을 리턴한다. 이러한 리턴값의 타입은 화살표 뒤에 지정하지만 생략해도 된다.

    ~~~c++
    auto returningLambda = [](int a, int b) -> int { return a + b; };
    int sum = returningLambda(11, 22);
    
    auto returningLambda = [](int a, int b){ return a + b; };
    int sum = returningLambda(11, 22);
    ~~~

  - 어떤 변수를 대괄호 안에 지정해서 람다 표현식 본문 안에 그 변수를 사용하게 만들 수 있다.

    이를 **캡처**한다고 표현한다.

    ~~~c++
    double data = 1.23;
    auto capturingLambda = [data]{ cout << "Data = " << data << endl; };
    ~~~

  - 값으로 캡처한 변수를 복제한 데이터 멤버는 const 속성을 그대로 이어 받는다.

    mutable로 지정하면 호출 연산자를 non-const로 만들 수 있다. mutable을 지정할 때는 매개변수가 없더라도 소괄호를 반드시 적어야 한다.

    ~~~c++
    double data = 1.23;
    auto capturingLambda = [data]() mutable { 
        data *= 2;
        cout << "Data = " << data << endl; };
    ~~~

  - 변수 이름 앞에 &를 붙이면 레퍼런스로 캡처한다.

    ~~~
    double data = 1.23;
    auto capturingLambda = [&data]{ data *= 2; };
    ~~~

  - 람다 표현식이 속한 스코프의 변수를 모두 캡처할 수 있다.

    - [=] : 스코프에 있는 변수를 모두 값으로 캡처한다.
    - [&] : 스코프에 있는 변수를 모두 레퍼런스로 캡처한다.

  - 캡처 디폴트를 지정할 때는 실제로 쓸 것만 값 또는 레퍼런스로 캡처해야 한다.

    가능하면 캡처할 변수를 직접 지정하자.

    - [&x] : 변수 x만 레퍼런스로 캡처한다.
    - [ x ] : 변수 x만 값으로 캡처한다.
    - [ =, &x, &y ] : x와 y는 레퍼런스로 캡처하고 나머지는 값으로 캡처한다.
    - [ &, x ] : x만 값으로 캡처하고, 나머지는 레퍼런스로 캡처한다.
    - [ this ] : 현재 객체를 캡처한다. 람다 표현식 본문 안에서 이 객체에 접근할 때 this -> 를 붙이지 않아도 된다.   

  </details>

  <details>
    <summary>18.3.2 제네릭 람다 표현식</summary> 

  - 매개변수의 타입을 auto 타입 추론으로 적용할 수 있다.

    ~~~c++
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
    ~~~

  </details>

  <details>
    <summary>18.3.3 람다 캡처 표현식</summary> 

  - 스코프에 있는 변수 중에서 캡처하지 않았던 것을 람다 표현식에 사용할 수 있다.

    ~~~c++
    double pi = 3.1415;
    auto my = [myCapture = "Pi: ", pi]{ cout << myCapture << pi;};
    >>> Pi: 3.1415
    ~~~

  - std::move()를 비롯한 모든 종류의 표현식으로 초기화할 수 있다.

  - 기본적으로 값으로 캡처하면 복제 방식이 적용되기 때문에 unique_ptr를 람다 표현식에 값으로 캡처할 수 없다.

    하지만 람다 캡처 표현식을 사용하면 다음과 같이 이동 방식으로 복제할 수 있다.

    ~~~c++
    auto myPtr = std::make_unique<double>(3.1415);
    auto myLambda = [p = std::move(myPtr)]{ cout << *p ;};
    ~~~

  - 권장 방법은 아니지만 캡처 대상 변수 이름과 람다 표현식 안에서 사용할 변수 이름을 똑같이 정해도 된다.

    ~~~c++
    auto myPtr = std::make_unique<double>(3.1415);
    auto myLambda = [myPtr = std::move(myPtr)]{ cout << *p ;};
    ~~~

  </details>

  <details>
    <summary>18.3.4 람다 표현식을 리턴 타입으로 사용하기</summary> 

  - std::function을 이용하면 함수가 람다 표현식을 리턴하게 만들 수 있다.

    ~~~c++
    //function<int(void)> test(int x)
    auto test(int x)
    {
        return [x]{return 2 * x;};
        // 만약 &x로 캡쳐하면 문제가 생긴다.
        // 여기서 리턴한 람다 표현식은 이 함수가 끝난 뒤에 사용되므로 
        // x에 대한 레퍼런스는 이상한 값을 가리킨다.
    }
    
    // function<int(void)> fn = test(5);
    auto fn = test(5);
    cout << fn() << endl;
    >>> 10
    ~~~

  </details>

</details>