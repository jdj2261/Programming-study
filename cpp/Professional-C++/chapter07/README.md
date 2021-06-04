# Chapter-7. 메모리 관리

<details>
  <summary>7-1. 동적 메모리 다루기</summary> 


- 실력있는 프로그래머가 되기 위해 동적 메모리를 처리하는 과정을 확실히 이해하고 넘어가자.

  <details>
    <summary>7-1.1. 메모리의 작동 과정 살펴보기</summary> 

  ~~~c++
  int i = 7; // i는 자동 변수 (스코프를 벗어나면 할당된 메모리가 자동으로 해제)
  int* ptr = new int; // ptr 변수를 stack에 선언하고 동적으로 생성된 힙 메모리를 가리킴
  
  // handle은 스택에 *handle은 힙에 있도록 구성
  int** handle = nullptr;	// 정수 포인터에 대한 포인터를 handle이란 변수로 선언
  handle = new int*; 	// 정수 포인터를 담는 데 충분한 크기로 메모리 할당 후 handle에 저장
  *handle = new int;	// 메모리(*handle)에 정수를 담기 충분한 크기의 힙 메모리를 동적으로 할당
  ~~~

  </details>

  <details>
    <summary>7-1.2. 메모리 할당과 해제</summary> 

  1. new와 delete 사용법

     - new로 메모리를 할당했으면 반드시 delete 해준다.(메모리 누수 방지)

     ~~~c++
     int* ptr = new int;
     delete ptr;
     ptr = nullptr;
     ~~~

  2. 메모리 할당에 실패한 경우

     - new가 항상 제대로 처리될 것이란 생각은 금물!

       메모리가 부족할 경우 실패할 수 있다.

       14장 참고

  </details>

  <details>
    <summary>7-1.3. 배열</summary> 

  1. 기본 타입 배열

     ~~~c++
     int myArray[5]; // 스택에 5개의 배열 선언
     int* myArrayPtr = new int[5]; // 힙에 배열 선언, 
     // myArrayPtr 변수는 배열의 0번째 원소를 가리킨다.
     delete[] myArrayPtr;
     myArrayPtr = nullptr;
     ~~~

     - 배열을 힙에 할당하면 실행 시간에 크기를 정할 수 있다.

       ~~~c++
       Document* createDocArray()
       {
         size_t numDocs = askUserForNumberOfDocuments();
         Document* docArray = new Document[numDocs];
         return dockArray;
       }
       ~~~

  2. 객체 배열 및 삭제

     ~~~c++
     class Simple
     {
     public:
         Simple(){cout << "constructor called!" << endl;}
         ~Simple(){cout << "destructor called!" << endl;}
     };
     
     int main()
     {
         Simple *mySimpleArray = new Simple[4];
     
         delete[] mySimpleArray;
         mySimpleArray = nullptr;
     }
     ~~~

     - 포인터 배열에 대해 delete[]를 호출할 때는 각 원소가 가리키는 객체를 일일이 해제해야 한다.

       ~~~c++
       const size_t size = 4;
       Simple **mySimplePtrArray = new Simple *[size];
       
       for (size_t i = 0; i < size; i++)
       {
       mySimplePtrArray[i] = new Simple();
       }
       
       for (size_t i = 0; i < size; i++)
       {
       delete mySimplePtrArray[i];
       }
       
       delete[] mySimplePtrArray;
       mySimplePtrArray = nullptr;
       ~~~

  3. 다차원 배열

     ~~~c++
     char board[3][3] = {};
     board[0][0] = 'X';
     board[2][1] = '0';
     ~~~

     > 다차원 힙 배열

     ~~~c++
     char** board = new char[i][j]; // 버그!
     ~~~

     [다음](pratice_code/CharacterBoard.cpp)과 같이 사용한다.

  **C 스타일의 배열 대신 std::array나 std::vector와 같은 컨테이너를 사용하자.**

  </details>

  <details>
    <summary>7-1.4. 포인터 다루기</summary> 

  </details>

</details>