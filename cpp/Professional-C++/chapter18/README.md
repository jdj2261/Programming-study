# Chapter-18. ǥ�� ���̺귯�� �˰��� �������ϱ�

<details>
  <summary>18.3. ���� ǥ����</summary> 

- ���� ǥ�����̶� �Լ��� �Լ� ��ü�� ������ �������� �ʰ�, �ʿ��� �������� ��ٷ� �Լ��� ���� ����� �� �� �ִ� ������ �͸� �Լ��̴�.

  <details>
    <summary>18.3.1 ����</summary> 

  - ���� �����ڶ� �θ��� ���ȣ []�� �����ϰ�, �� �ڿ� ������ ��� �߰�ȣ {}�� ���´�.

    ���� ǥ������ auto Ÿ�� ������ basicLambda�� ���Եȴ�.

    ~~~c++
    auto basicLambda = []{ cout << "Hello from Lambda" << endl; };
    basicLambda();
    >>> Hello from Lambda
    ~~~

  - �Ű������� ���� �� �ִ�.

    ~~~c++
    auto parametersLambda =
        [](int value){cout << value << endl;};
    parametersLambda(42);
    ~~~

  - ���� ǥ������ ���� �����Ѵ�. �̷��� ���ϰ��� Ÿ���� ȭ��ǥ �ڿ� ���������� �����ص� �ȴ�.

    ~~~c++
    auto returningLambda = [](int a, int b) -> int { return a + b; };
    int sum = returningLambda(11, 22);
    
    auto returningLambda = [](int a, int b){ return a + b; };
    int sum = returningLambda(11, 22);
    ~~~

  - � ������ ���ȣ �ȿ� �����ؼ� ���� ǥ���� ���� �ȿ� �� ������ ����ϰ� ���� �� �ִ�.

    �̸� **ĸó**�Ѵٰ� ǥ���Ѵ�.

    ~~~c++
    double data = 1.23;
    auto capturingLambda = [data]{ cout << "Data = " << data << endl; };
    ~~~

  - ������ ĸó�� ������ ������ ������ ����� const �Ӽ��� �״�� �̾� �޴´�.

    mutable�� �����ϸ� ȣ�� �����ڸ� non-const�� ���� �� �ִ�. mutable�� ������ ���� �Ű������� ������ �Ұ�ȣ�� �ݵ�� ����� �Ѵ�.

    ~~~c++
    double data = 1.23;
    auto capturingLambda = [data]() mutable { 
        data *= 2;
        cout << "Data = " << data << endl; };
    ~~~

  - ���� �̸� �տ� &�� ���̸� ���۷����� ĸó�Ѵ�.

    ~~~
    double data = 1.23;
    auto capturingLambda = [&data]{ data *= 2; };
    ~~~

  - ���� ǥ������ ���� �������� ������ ��� ĸó�� �� �ִ�.

    - [=] : �������� �ִ� ������ ��� ������ ĸó�Ѵ�.
    - [&] : �������� �ִ� ������ ��� ���۷����� ĸó�Ѵ�.

  - ĸó ����Ʈ�� ������ ���� ������ �� �͸� �� �Ǵ� ���۷����� ĸó�ؾ� �Ѵ�.

    �����ϸ� ĸó�� ������ ���� ��������.

    - [&x] : ���� x�� ���۷����� ĸó�Ѵ�.
    - [ x ] : ���� x�� ������ ĸó�Ѵ�.
    - [ =, &x, &y ] : x�� y�� ���۷����� ĸó�ϰ� �������� ������ ĸó�Ѵ�.
    - [ &, x ] : x�� ������ ĸó�ϰ�, �������� ���۷����� ĸó�Ѵ�.
    - [ this ] : ���� ��ü�� ĸó�Ѵ�. ���� ǥ���� ���� �ȿ��� �� ��ü�� ������ �� this -> �� ������ �ʾƵ� �ȴ�.   

  </details>

  <details>
    <summary>18.3.2 ���׸� ���� ǥ����</summary> 

  - �Ű������� Ÿ���� auto Ÿ�� �߷����� ������ �� �ִ�.

    ~~~c++
    vector<int> ints{ 11, 55, 101, 200 };
    vector<double> doubles{ 11.1, 55.5, 200.2 };
    // 100�� �Ѵ� ���� ã�� ���׸� ���� ǥ���� ����
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
    <summary>18.3.3 ���� ĸó ǥ����</summary> 

  - �������� �ִ� ���� �߿��� ĸó���� �ʾҴ� ���� ���� ǥ���Ŀ� ����� �� �ִ�.

    ~~~c++
    double pi = 3.1415;
    auto my = [myCapture = "Pi: ", pi]{ cout << myCapture << pi;};
    >>> Pi: 3.1415
    ~~~

  - std::move()�� ����� ��� ������ ǥ�������� �ʱ�ȭ�� �� �ִ�.

  - �⺻������ ������ ĸó�ϸ� ���� ����� ����Ǳ� ������ unique_ptr�� ���� ǥ���Ŀ� ������ ĸó�� �� ����.

    ������ ���� ĸó ǥ������ ����ϸ� ������ ���� �̵� ������� ������ �� �ִ�.

    ~~~c++
    auto myPtr = std::make_unique<double>(3.1415);
    auto myLambda = [p = std::move(myPtr)]{ cout << *p ;};
    ~~~

  - ���� ����� �ƴ����� ĸó ��� ���� �̸��� ���� ǥ���� �ȿ��� ����� ���� �̸��� �Ȱ��� ���ص� �ȴ�.

    ~~~c++
    auto myPtr = std::make_unique<double>(3.1415);
    auto myLambda = [myPtr = std::move(myPtr)]{ cout << *p ;};
    ~~~

  </details>

  <details>
    <summary>18.3.4 ���� ǥ������ ���� Ÿ������ ����ϱ�</summary> 

  - std::function�� �̿��ϸ� �Լ��� ���� ǥ������ �����ϰ� ���� �� �ִ�.

    ~~~c++
    //function<int(void)> test(int x)
    auto test(int x)
    {
        return [x]{return 2 * x;};
        // ���� &x�� ĸ���ϸ� ������ �����.
        // ���⼭ ������ ���� ǥ������ �� �Լ��� ���� �ڿ� ���ǹǷ� 
        // x�� ���� ���۷����� �̻��� ���� ����Ų��.
    }
    
    // function<int(void)> fn = test(5);
    auto fn = test(5);
    cout << fn() << endl;
    >>> 10
    ~~~

  </details>

</details>