# C++의 까다롭고 유별난 부분

<details>
  <summary>11-1. 레퍼런스</summary>
- 레퍼런스(참조)란 일종의 변수에 대한 alias(별칭)이다.

- 레퍼런스를 이용해서 수정한 내용은 그 레퍼런스가 가리키는 변수 값에 그대로 반영된다.

- 변수에 대한 다른 이름이라 생각하자!

- 변수를 레퍼런스로 만들 수 있고, 클래스의 데이터 멤버를 레퍼런스로 만들 수 있고, 함수나 메서드가 레퍼런스를 매개변수로 받거나 레퍼런스를 리턴할 수 있다.

  <details>
    <summary>11.1.1 레퍼런스 변수</summary>


  - 레퍼런스 변수는 반드시 생성하자마자 초기화해야 한다.

  - xRef는 x에 대한 또 다른 이름이다.

    ~~~c++
    int x = 3;
    int& xRef = x;
    ~~~
    
  - 이름없는 값에 대해서는 레퍼런스를 생성할 수 없지만 **const** 값에 대해서는 레퍼런스를 생성할 수 있다.

    ~~~c++
    int& unnamedRef1 = 5;		// 컴파일 에러
    const int& unnamedRef2 = 5;	// 정상 작동
    ~~~

  - 임시 객체도 마찬가지이다. 

    ~~~c++
    std::string getString() {return "Hello world!";}
    std::string& string1 = getString();			// 컴파일 에러
    const std::string& string2 = getString();	// 정상 작동
    ~~~

  1. 레퍼런스 대상 변경하기

     - 레퍼런스에 다른 변수를 대입하면 레퍼런스가 가리키는 대상이 바뀌는게 아니라 원래 가리키던 변수의 값이 바뀌는 것이다.

       ~~~c++
       int x = 3, y = 4;
       int& xRef = x;
       xRef = y;		// xRef가 y를 가리키는 것이 아니라 x의 값을 4로 변경한다.
       xRef = &y;		// 컴파일 에러 발생 (y의 주소는 포인터지만 xRef는 int에 대한 레퍼런스 이니까)
       ~~~

  2. 포인터에 대한 레퍼런스와 레퍼런스에 대한 포인터

     - 레퍼런스는 모든 타입에 대해 만들 수 있다.

       ~~~c++
       int* intP;				// int에 대한 포인터
       int*& ptrRef = intP;	// intP에 대한 레퍼런스
       ptrRef = new int;
       *ptrRef = 5;
       ~~~

     - 레퍼런스가 가져온 주소는 그 레퍼런스가 가리키는 변수의 주소와 같다.

       ~~~c++
       int x = 3;
       int& xRef = x;
       int* xPtr = &xRef;	// 레퍼런스의 주소는 값에 대한 포인터와 같다.	
       *xPtr = 100;		// x의 값이 100으로 바뀐다.
       ~~~

       *xPtr == xRef 라는 비교 연산을 수행하면 서로 타입이 다르다는 컴파일 에러가 발생한다.*

       *xPtr는 int에 대한 포인터 타입이고, xRef는 int에 대한 레퍼런스 타입이기 때문이다.*

       *xPtr == &xRef나 xPtr==&x와 같이 작성해야 한다.*

  </details>

  <details>
    <summary>11.1.2 레퍼런스 데이터 멤버</summary>

  - 레퍼런스의 데이터 멤버는 반드시 생성자의 본문이 아닌 생성자 이니셜라이저에서 초기화해야 한다.

    ~~~c++
    class MyClass
    {
        public:
        	MyClass(int& ref) : mRef(ref) {}
        private:
        	int& mRef
    }
    ~~~

  </details>

  <details>
    <summary>11.1.3 레퍼런스 매개변수</summary>

  - 레퍼런스는 주로 함수나 메서드의 매개변수로 많이 사용된다.

  - 매개변수 타입이 레퍼런스로 선언된 함수에 인수를 지정하면 그 인수의 레퍼런스가 함수로 전달된다.

    따라서, 전달된 값을 수정하면 인수로 지정한 원본 변수의 값도 바뀐다.

    ~~~c++
    void swap(int& first, int& second)
    {
        int temp = first;
        first = second;
        second = temp;
    }
    
    int x = 5, y = 6;
    swap(x, y);		// x = 6, y = 5 로 바뀐다.
    ~~~

  1. 포인터를 레퍼런스로 전달하기

     - 포인터를 역참조해서 전달하면 포인터를 레퍼런스로 변환할 수 있다.

       ~~~c++
       int x = 5, y = 6;
       int *xp = &x, *yp = &y;
       swap(*xp, *yp);		// x = 6, y = 5 로 바뀐다.
       ~~~

  2. 레퍼런스 전달 방식과 값 전달 방식

     - 레퍼런스를 쓰는 이유 2가지에 대해 알아보자
       - 효율성 : 크기가 큰 객체나 struct는 복제 오버헤드가 크다. 레퍼런스 전달 방식을 사용하면 객체나 struct에 대해 레퍼런스만 함수에 전달된다.
       - 정확성 : 값 전달 방식을 지원하지 않는 객체가 있다. 지원하더라도 깊언 복제가 적용되자 않을 수 있다. 동적 할당 메모리를 사용하는 객체에 대해서는 반드시 커스텀 복제 생성자와 복제 대입 연산자를 정의해서 깊은 복제를 제공해야 한다.
     - 값 전달 방식은 인수가 int나 double과 같은 기본 타입이면서 함수 안에서 수정할 필요가 없을 때만 사용하고, 나머지 경우는 레퍼런스 전달 방식이나 const 레퍼런스 전달 방식을 사용하는 것이 좋다.

  </details>

  <details>
    <summary>11.1.4 레퍼런스 리턴값</summary>

  - 함수나 메서드의 리턴값을 레퍼런스 타입으로 지정하는 이유는 효율성 때문이다.
  - 객체 전체를 리턴하지 않고 객체에 대한 레퍼런스만 리턴하면 복제 연산을 줄일 수 있다.

  </details>

  <details>
    <summary>11.1.5 rvalue 레퍼런스</summary>

  - rvalue의 대표적인 예로 상숫값과 임시 객체가 있으며, 일반적으로 rvalue는 대입 연산자의 오른쪽에 나온다.

    ~~~c++
    // 매개변수를 lvalue 레퍼런스로 정의함
    void handleMessage(std::string& message)
    {
        cout << "handleMessage with lvalue reference: " << message << endl;
    }
    ~~~

  - handleMessage()는 매개변수를 lvalue 레퍼런스로 정의했기 때문에, 다음과 같이 호출할 수 없다.

    ~~~c++
    handleMessage("Hello World"); // 리터럴은 lvalue가 아니다.
    std::string a = "Hello";
    std::string b = "World";
    handleMessage(a + b);		// 임시값은 lvalue가 아니다.
    ~~~

  - 위와 같이 호출하려면 rvalue 레퍼런스를 받는 버전을 구현해야 한다.

    ~~~c++
    void handleMessage(std::string&& message)
    {
        cout << "handleMessage with lvalue reference: " << message << endl;
    }
    ~~~

  </details>

  <details>
    <summary>11.1.6 레퍼런스와 포인터의 선택 기준</summary>

  - 레퍼런스로 할 수 있는 일을 모두 포인터로 처리할 수 있으니 C++에서 굳이 레퍼런스를 제공할 이유가 없다고 생각할 수 있다.

    ~~~c++
    void swap(int* first, int* second)
    {
        int temp = *first;
        *first = *second;
        *second = temp;
    }
    ~~~

  - 레퍼런스로 작성하면 코드가 깔끔하고 읽기 쉽다. 게다가 훨씬 안전하다.

  - 레퍼런스의 값은 널이 될 수 없고, 레퍼런스를 명시적으로 역참조할 수도 없다.

  - 단, 포인터가 하나도 없을 때만 레퍼런스가 더 안전하다고 말할 수 있다.

    ~~~c++
    void refcall(int& t) {++t;}
    int* ptr = (int*)8;
    refcall(*ptr);	// 실행하자마자 프로그램이 뻗어버릴 수도 있다.
    ~~~

  - 포인터를 사용한 코드는 거의 대부분 레퍼런스로 표현할 수 있다. 심지어 객체에 대한 레퍼런스는 객체에 대한 포인터처럼 다형성도 지원한다.

  - 하지만 반드시 포인터를 사용해야 하는 경우가 있다.

    **가리키는 위치를 변경해야 할 때** -> 레퍼런스 타입 변수는 한 번 초기화되고 나면 그 변수가 가리키는 주소값을 바꿀 수 없다. 예를 들어, 동적할당 메모리의 주소는 레퍼런스가 아닌 포인터에 저장해야 한다. 

    **주솟값이 nullptr이 될 수 도 있는 optional 타입**

    **컨테이너에 다형성 타입을 저장할 때**

  - 매개변수나 리턴값을 포인터와 레퍼런스 중 어느 것으로 표현하는 것이 적합한지 판단하는 한 가지 방법은 메모리 **소유권**이 어디에 있는지 따져보는 것이다.

  - 소유권을 이전할 필요가 있다면 항상 **스마트포인터**를 사용하는 것이 좋고, 메모리 소유권이 변수를 받는 코드에 없어서 메모리를 해제할 일이 없다면 **레퍼런스**로 전달한다.

    *포인터보다 레퍼런스를 사용하는 것이 좋다. 레퍼런스를 사용할 수 없을 때만 포인터를 사용한다.*

  ~~~c++

  int unSplit[] = {1, 2, 3, 4, 5, 6}
  int* oddNums = nullptr;
  int* evenNums = nullptr;
  size_t numOdds = 0, numEvens = 0;
  
  // separateOddsAndEvens(unSplit, std::size(unSplit), &oddNums, &numOdds, &evenNums, &numEvens); // 이렇게 해도 되고
  separateOddsAndEvens(unSplit, std::size(unSplit), oddNums, numOdds, evenNums, numEvens);		// 깔끔하게 이렇게 
  
  delete[] oddNums; oddNums = nullptr;
  delete[] evenNums; evenNums = nullptr;
  ~~~

  ~~~c++

  separateOddsAndEvens(unSplit, std::size(unSplit), &oddNums, &numOdds, &evenNums, &numEvens)
  {
  	numOdds = numEvens = 0;
      for (size_t i = 0; i < size; ++i)
      {
          if (arr[i] % 2 == 1) ++numOdds;
          else ++numEvens;
      }
  
  
      odds = new int[numOdds];
      evens = new int[numEvens];
      size_t oddsPos = 0, evensPos = 0;
  
      for (size_t i = 0; i < size; i++)
      {
          if (arr[i] % 2 == 1) odds[oddsPos++] = arr[i];
          else evens[evensPos++] = arr[i];
      }
  }
  ~~~

  - 배열을 동적으로 할당하는 식으로 작성하지 않는 것이 좋다. 

    메모리 할당 및 해제 작업을 자동으로 해주는 vector 컨테이너를 사용하자.

  ~~~c++
  separateOddsAndEvens(const vector<int>& arr, vector<int>& odds, vector<int>& evens)
  {
      for (int i : arr)
      {
          if (i % 2 == 1) odds.push_back(i);
          else evens.push_back(i);
      }
  }
  vector<int> vecUnSplit = {1, 2, 3, 4, 5, 6};
  vector<int> odds, evens;
  separateOddsAndEvens(vecUnSplit, odds, evens);
  ~~~

  - 결과를 매개변수로 전달하는 방식은 가급적 사용하지 않는 것이 좋다.

    함수가 어떤 값을 리턴해야 한다면 출력 매개변수가 아닌 리턴문을 사용하자.

  - 구조적 바인딩을 사용하면 함수에서 여러 값을 리턴하는 과정을 간단하게 구현할 수 있다.

  ~~~c++
  pair<vector<int>, vector<int>> separateOddsAndEvens(const vector<int>& arr)
  {
      vector<int> odds, evens;
      for (int i : arr)
      {
          if (i % 2 == 1) odds.push_back(i);
          else evens.push_back(i);
      }
      return make_pair(odds, evens);
  }
  vector<int> vecUnSplit = {1, 2, 3, 4, 5, 6};
  auto[odds, evens] = separateOddsAndEvens(vecUnSplit);
  ~~~

  </details>

</details>