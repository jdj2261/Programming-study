# C++�� ��ٷӰ� ������ �κ�

<details>
  <summary>11-1. ���۷���</summary>
- ���۷���(����)�� ������ ������ ���� alias(��Ī)�̴�.

- ���۷����� �̿��ؼ� ������ ������ �� ���۷����� ����Ű�� ���� ���� �״�� �ݿ��ȴ�.

- ������ ���� �ٸ� �̸��̶� ��������!

- ������ ���۷����� ���� �� �ְ�, Ŭ������ ������ ����� ���۷����� ���� �� �ְ�, �Լ��� �޼��尡 ���۷����� �Ű������� �ްų� ���۷����� ������ �� �ִ�.

  <details>
    <summary>11.1.1 ���۷��� ����</summary>


  - ���۷��� ������ �ݵ�� �������ڸ��� �ʱ�ȭ�ؾ� �Ѵ�.

  - xRef�� x�� ���� �� �ٸ� �̸��̴�.

    ~~~c++
    int x = 3;
    int& xRef = x;
    ~~~
    
  - �̸����� ���� ���ؼ��� ���۷����� ������ �� ������ **const** ���� ���ؼ��� ���۷����� ������ �� �ִ�.

    ~~~c++
    int& unnamedRef1 = 5;		// ������ ����
    const int& unnamedRef2 = 5;	// ���� �۵�
    ~~~

  - �ӽ� ��ü�� ���������̴�. 

    ~~~c++
    std::string getString() {return "Hello world!";}
    std::string& string1 = getString();			// ������ ����
    const std::string& string2 = getString();	// ���� �۵�
    ~~~

  1. ���۷��� ��� �����ϱ�

     - ���۷����� �ٸ� ������ �����ϸ� ���۷����� ����Ű�� ����� �ٲ�°� �ƴ϶� ���� ����Ű�� ������ ���� �ٲ�� ���̴�.

       ~~~c++
       int x = 3, y = 4;
       int& xRef = x;
       xRef = y;		// xRef�� y�� ����Ű�� ���� �ƴ϶� x�� ���� 4�� �����Ѵ�.
       xRef = &y;		// ������ ���� �߻� (y�� �ּҴ� ���������� xRef�� int�� ���� ���۷��� �̴ϱ�)
       ~~~

  2. �����Ϳ� ���� ���۷����� ���۷����� ���� ������

     - ���۷����� ��� Ÿ�Կ� ���� ���� �� �ִ�.

       ~~~c++
       int* intP;				// int�� ���� ������
       int*& ptrRef = intP;	// intP�� ���� ���۷���
       ptrRef = new int;
       *ptrRef = 5;
       ~~~

     - ���۷����� ������ �ּҴ� �� ���۷����� ����Ű�� ������ �ּҿ� ����.

       ~~~c++
       int x = 3;
       int& xRef = x;
       int* xPtr = &xRef;	// ���۷����� �ּҴ� ���� ���� �����Ϳ� ����.	
       *xPtr = 100;		// x�� ���� 100���� �ٲ��.
       ~~~

       *xPtr == xRef ��� �� ������ �����ϸ� ���� Ÿ���� �ٸ��ٴ� ������ ������ �߻��Ѵ�.*

       *xPtr�� int�� ���� ������ Ÿ���̰�, xRef�� int�� ���� ���۷��� Ÿ���̱� �����̴�.*

       *xPtr == &xRef�� xPtr==&x�� ���� �ۼ��ؾ� �Ѵ�.*

  </details>

  <details>
    <summary>11.1.2 ���۷��� ������ ���</summary>

  - ���۷����� ������ ����� �ݵ�� �������� ������ �ƴ� ������ �̴ϼȶ��������� �ʱ�ȭ�ؾ� �Ѵ�.

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
    <summary>11.1.3 ���۷��� �Ű�����</summary>

  - ���۷����� �ַ� �Լ��� �޼����� �Ű������� ���� ���ȴ�.

  - �Ű����� Ÿ���� ���۷����� ����� �Լ��� �μ��� �����ϸ� �� �μ��� ���۷����� �Լ��� ���޵ȴ�.

    ����, ���޵� ���� �����ϸ� �μ��� ������ ���� ������ ���� �ٲ��.

    ~~~c++
    void swap(int& first, int& second)
    {
        int temp = first;
        first = second;
        second = temp;
    }
    
    int x = 5, y = 6;
    swap(x, y);		// x = 6, y = 5 �� �ٲ��.
    ~~~

  1. �����͸� ���۷����� �����ϱ�

     - �����͸� �������ؼ� �����ϸ� �����͸� ���۷����� ��ȯ�� �� �ִ�.

       ~~~c++
       int x = 5, y = 6;
       int *xp = &x, *yp = &y;
       swap(*xp, *yp);		// x = 6, y = 5 �� �ٲ��.
       ~~~

  2. ���۷��� ���� ��İ� �� ���� ���

     - ���۷����� ���� ���� 2������ ���� �˾ƺ���
       - ȿ���� : ũ�Ⱑ ū ��ü�� struct�� ���� ������尡 ũ��. ���۷��� ���� ����� ����ϸ� ��ü�� struct�� ���� ���۷����� �Լ��� ���޵ȴ�.
       - ��Ȯ�� : �� ���� ����� �������� �ʴ� ��ü�� �ִ�. �����ϴ��� ��� ������ ������� ���� �� �ִ�. ���� �Ҵ� �޸𸮸� ����ϴ� ��ü�� ���ؼ��� �ݵ�� Ŀ���� ���� �����ڿ� ���� ���� �����ڸ� �����ؼ� ���� ������ �����ؾ� �Ѵ�.
     - �� ���� ����� �μ��� int�� double�� ���� �⺻ Ÿ���̸鼭 �Լ� �ȿ��� ������ �ʿ䰡 ���� ���� ����ϰ�, ������ ���� ���۷��� ���� ����̳� const ���۷��� ���� ����� ����ϴ� ���� ����.

  </details>

  <details>
    <summary>11.1.4 ���۷��� ���ϰ�</summary>

  - �Լ��� �޼����� ���ϰ��� ���۷��� Ÿ������ �����ϴ� ������ ȿ���� �����̴�.
  - ��ü ��ü�� �������� �ʰ� ��ü�� ���� ���۷����� �����ϸ� ���� ������ ���� �� �ִ�.

  </details>

  <details>
    <summary>11.1.5 rvalue ���۷���</summary>

  - rvalue�� ��ǥ���� ���� ������� �ӽ� ��ü�� ������, �Ϲ������� rvalue�� ���� �������� �����ʿ� ���´�.

    ~~~c++
    // �Ű������� lvalue ���۷����� ������
    void handleMessage(std::string& message)
    {
        cout << "handleMessage with lvalue reference: " << message << endl;
    }
    ~~~

  - handleMessage()�� �Ű������� lvalue ���۷����� �����߱� ������, ������ ���� ȣ���� �� ����.

    ~~~c++
    handleMessage("Hello World"); // ���ͷ��� lvalue�� �ƴϴ�.
    std::string a = "Hello";
    std::string b = "World";
    handleMessage(a + b);		// �ӽð��� lvalue�� �ƴϴ�.
    ~~~

  - ���� ���� ȣ���Ϸ��� rvalue ���۷����� �޴� ������ �����ؾ� �Ѵ�.

    ~~~c++
    void handleMessage(std::string&& message)
    {
        cout << "handleMessage with lvalue reference: " << message << endl;
    }
    ~~~

  </details>

  <details>
    <summary>11.1.6 ���۷����� �������� ���� ����</summary>

  - ���۷����� �� �� �ִ� ���� ��� �����ͷ� ó���� �� ������ C++���� ���� ���۷����� ������ ������ ���ٰ� ������ �� �ִ�.

    ~~~c++
    void swap(int* first, int* second)
    {
        int temp = *first;
        *first = *second;
        *second = temp;
    }
    ~~~

  - ���۷����� �ۼ��ϸ� �ڵ尡 ����ϰ� �б� ����. �Դٰ� �ξ� �����ϴ�.

  - ���۷����� ���� ���� �� �� ����, ���۷����� ��������� �������� ���� ����.

  - ��, �����Ͱ� �ϳ��� ���� ���� ���۷����� �� �����ϴٰ� ���� �� �ִ�.

    ~~~c++
    void refcall(int& t) {++t;}
    int* ptr = (int*)8;
    refcall(*ptr);	// �������ڸ��� ���α׷��� ������� ���� �ִ�.
    ~~~

  - �����͸� ����� �ڵ�� ���� ��κ� ���۷����� ǥ���� �� �ִ�. ������ ��ü�� ���� ���۷����� ��ü�� ���� ������ó�� �������� �����Ѵ�.

  - ������ �ݵ�� �����͸� ����ؾ� �ϴ� ��찡 �ִ�.

    **����Ű�� ��ġ�� �����ؾ� �� ��** -> ���۷��� Ÿ�� ������ �� �� �ʱ�ȭ�ǰ� ���� �� ������ ����Ű�� �ּҰ��� �ٲ� �� ����. ���� ���, �����Ҵ� �޸��� �ּҴ� ���۷����� �ƴ� �����Ϳ� �����ؾ� �Ѵ�. 

    **�ּڰ��� nullptr�� �� �� �� �ִ� optional Ÿ��**

    **�����̳ʿ� ������ Ÿ���� ������ ��**

  - �Ű������� ���ϰ��� �����Ϳ� ���۷��� �� ��� ������ ǥ���ϴ� ���� �������� �Ǵ��ϴ� �� ���� ����� �޸� **������**�� ��� �ִ��� �������� ���̴�.

  - �������� ������ �ʿ䰡 �ִٸ� �׻� **����Ʈ������**�� ����ϴ� ���� ����, �޸� �������� ������ �޴� �ڵ忡 ��� �޸𸮸� ������ ���� ���ٸ� **���۷���**�� �����Ѵ�.

    *�����ͺ��� ���۷����� ����ϴ� ���� ����. ���۷����� ����� �� ���� ���� �����͸� ����Ѵ�.*

  ~~~c++

  int unSplit[] = {1, 2, 3, 4, 5, 6}
  int* oddNums = nullptr;
  int* evenNums = nullptr;
  size_t numOdds = 0, numEvens = 0;
  
  // separateOddsAndEvens(unSplit, std::size(unSplit), &oddNums, &numOdds, &evenNums, &numEvens); // �̷��� �ص� �ǰ�
  separateOddsAndEvens(unSplit, std::size(unSplit), oddNums, numOdds, evenNums, numEvens);		// ����ϰ� �̷��� 
  
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

  - �迭�� �������� �Ҵ��ϴ� ������ �ۼ����� �ʴ� ���� ����. 

    �޸� �Ҵ� �� ���� �۾��� �ڵ����� ���ִ� vector �����̳ʸ� �������.

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

  - ����� �Ű������� �����ϴ� ����� ������ ������� �ʴ� ���� ����.

    �Լ��� � ���� �����ؾ� �Ѵٸ� ��� �Ű������� �ƴ� ���Ϲ��� �������.

  - ������ ���ε��� ����ϸ� �Լ����� ���� ���� �����ϴ� ������ �����ϰ� ������ �� �ִ�.

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