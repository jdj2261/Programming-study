# Chapter-23. C++ 멀티스레드 프로그래밍

- 프로세스 유닛(CPU, CORE 등)이 여러 개 달린 프로세서를 **멀티코어  프로세서**라 부른다.

<details>
  <summary>23.1. 멀티스레드 프로그래밍 개념</summary> 

- 멀티스레드 프로그래밍을 사용하면 여러 연산을 병렬로 처리할 수 있다.

- 멀티스레드 프로그래밍이 필요한 이유는 크게 두 가지다.

  1. 주어진 연산 작업을 작은 문제들로 나눠서 병렬로 실행하면 전반적인 성능을 크게 높일 수 있다.

  2. 연산을 다른 관점에서 모듈화할 수 있다.

     예를 들어 연산을 UI 스레드에 종속적이지 않은 독립 스레드로 분리해서 구현하면 처리 시간이 긴 연산을 백그라운드로 실행시키는 방식으로 UI의 응답 속도를 높일 수 있다.

- 멀티스레드 관련 문제를 방지하려면 여러 스레드가 공유 메모리를 동시에 읽거나 쓰지 않도록 디자인해야 한다.

  아니면 동기화 기법이나 아토미 연산을 적용한다.

  <details>
    <summary>23.1.1. 경쟁 상태</summary> 

  - 여러 스레드가 공유 리소스를 동시에 접근할 때 **경쟁 상태**가 발생할 수 있다.
  - 공유 메모리에 대한 경쟁 상태를 흔히 **데이터 경쟁**이라 부른다.
  - 데이터 경쟁은 여러 스레드가 공유 메모리에 동시에 접근할 수 있는 상태에서 최소 하나의 스레드가 그 메모리에 데이터를 쓸 때 발생한다.

  </details>

  <details>
    <summary>23.1.2. 테어링</summary> 

  - 데이터 경쟁의 특수한 경우로서, 읽기 테어링과 쓰기 테어링 두 가지가 있다.
  - 어떤 스레드가 메모리에 데이터의 일부만 쓰고 나머지 부분을 미쳐 쓰지 못한 상태에서 다른 스레드가 이 데이터를 읽으면 두 스레드가 보는 값이 달라진다. (읽기 테어링)
  - 두 스레드가 데이터에 동시에 쓸 때 한 스레드는 그 데이터의 한쪽 부분을 쓰고, 다른 스레드는 그 데이터의 다른 부분을 썼다면 각자 수행한 결과가 달라진다. (쓰기 테어링)

  </details>

  <details>
    <summary>23.1.3. 데드락</summary> 

  - 경쟁 상태를 막기 위해 상호 배제와 같은 동기화 기법(mutex)을 적용하다 보면 **교착상태**(데드락)에 부딪히기 쉽다.

  - 여러 스레드가 서로 상대방 작업이 끝날 때까지 동시에 기다리는 상태를 말한다.

  - 이를 해결하기 위해 모든 스레드가 일정한 순서로 리소스를 획득하게 하거나, 데드락이 발생해도 빠져나올 수 있는  메커니즘도 함께 구현하면 좋다.

  - 한 가지 방법은 리소스 접근 권한을 요청하는 작업에 시간제한을 걸어두는 것이다.

  - 확실한 방법으로 std::lock()이나 std::try_lock()과 같은 함수를 활용하자.

    여러 리소스에 대한 권한을 한 번에 확보하거나 요청해준다.

  </details>

  <details>
    <summary>23.1.4. 잘못된 공유</summary> 

  - 캐시는 캐시 라인 단위로 처리된다. 최신 CPU는 흔히 64바이트 캐시 라인으로 구성된다. 

    캐시 라인에 데이터를 쓰려면 반드시 그 라인에 락을 걸어야 한다.

  - 데이터 구조를 잘 만들지 않으면 캐시 라인에 락을 거는 과정에서 성능이 크게 떨어질 수 있다.

  - 예를들어, 두 스레드가 두 가지 데이터 영역을 사용하는데, 데이터가 같은 캐시 라인에 걸쳐 있는 경우 한 스레드가 데이터를 업데이트하면 캐시 라인 전체에 락을 걸어버리기 때문에 다른 스레드는 기다려야 한다.

  - 캐시 라인에 걸치지 않도록 메모리 영역을 명시적으로 졍렬하자.

  - C++17 부터 hardware_destructive_interference_size란 상수가 추가 됐다.

  - 이 상수는 동시에 접근하는 두 객체가 캐시 라인을 공유하지 않도록 최소한의 오프셋을 제시해준다.

  - 이 값과 alignas 키워드로 데이터를 적절히 정렬하는데 활용하자.

  </details>

</details>

<details>
  <summary>23.2. 스레드</summary> 

- 전역 함수로 표현하거나, 함수 객체의 operator()로 표현하거나, 람다 표현식으로 지정하거나, 특정 클래스의 인스턴스에 있는 멤버 함수로 지정할 수 있다.

  <details>
    <summary>23.2.1 함수 포인터로 스레드 만들기</summary> 

  - std::thread 클래스에서 사용하는 함수는 매개변수를 원하는 개수만큼 받을 수 있다.

  ~~~c++
  void counter(int id, int numIterations)
  {
  	for (int i = 0; i < numIterations; ++i) 
      {
  		cout << "Counter " << id << " has value " << i << endl;
  	}
  }
  int main()
  {
  
  	thread t1(counter, 1, 6);
  	thread t2(counter, 2, 4);
  	t1.join();
  	t2.join();
  	return 0;
  }
  ~~~
  
  - thread 객체가 실행 가능한 상태에 있을 때 **조인 가능** 하다고 표현한다.
  - 조인 가능한 thread 객체를 제거하려면 먼저 객체의 join( )이나 detach( )부터 호출해야 한다.
  - join( )을 호출하면 그 스레드는 블록되며, 스레드가 작업을 끝날 때까지 기다린다.
  - detach( )를 호출하면 thread 객체를 OS 내부의 스레드와 분리한다.
  - 조인 가능 상태의 thread 객체를 제거하면 그 객체의 소멸자는 모든 스레드뿐만 아니라 애플리케이션마저 종료시킨다.
  
  ~~~
  Counter 1 has value 0		
  Counter 1 has value 1
  Counter 1 has value 2
  Counter 1 has value 3
  ...
  Counter 1 has value 2
  Counter 1 has value 3
  Counter 1 has value 4Counter 2 has value 0
  Counter 2 has value 1
  Counter 2 has value 2
  ...
  ~~~
  
  - 데이터 경쟁이 발생하지 않더라도 스레드마다 출력한 결과는 겹칠 수 있다.
  
    동기화 기법을 적용하여 뒤섞이지 않게 만들자.
  
  </details>
  
  <details>
    <summary>23.2.2 함수 객체로 스레드 만들기</summary> 
  
  - 클래스에 operator( )를 구현한 후 멤버 변수를 추가하여 함수 객체로 만든다.
  
  ~~~c++
  class Counter
  {
  public:
  	Counter(int id, int numIterations)
  		: mId(id), mNumIterations(numIterations)
  	{
  	}
  
  	void operator()() const
  	{
  		for (int i = 0; i < mNumIterations; ++i) {
  			cout << "Counter " << mId << " has value " << i << endl;
  		}
  	}
  
  private:
  	int mId;
  	int mNumIterations;
  };
  ~~~
  
  - 함수 객체로 만든 스레드를 초기화 하는 방법은 세 가지가 있다.
  
  ~~~c++
  int main()
  {
  	// Using uniform initialization syntax
  	thread t1{ Counter{ 1, 20 } };
  
  	// Using named variable
  	Counter c(2, 12);
  	thread t2(c);
  
  	// Using temporary
  	thread t3(Counter(3, 10));
  
  	// Wait for threads to finish
  	t1.join();
  	t2.join();
  	t3.join();
  
  	return 0;
  }
  ~~~
  
  - 매개변수 없이 객체를 리턴한다면 유니폼 초기화를 사용하는 것이 좋다.
  
  ~~~
  thread t1{ Couter{} };
  ~~~
  
  </details>
  
  <details>
    <summary>23.2.3 람다 표현식으로 스레드 만들기</summary> 
  
  ~~~c++
  int main()
  {
  	int id = 1;
  	int numIterations = 5;
  	thread t1([id, numIterations] {
  		for (int i = 0; i < numIterations; ++i) {
  			cout << "Counter " << id << " has value " << i << endl;
  		}
  	});
  	t1.join();
  
  	return 0;
  }
  ~~~
  
  </details>
  
  <details>
    <summary>23.2.4 멤버 함수로 스레드 만들기</summary> 
  
  ~~~c++
  class Request
  {
  public:
  	Request(int id) : mId(id) { }
  	void process()
  	{
  		cout << "Processing request " << mId << endl;
  	}
  private:
  	int mId;
  };
  int main()
  {
  	Request req(100);
  	thread t{ &Request::process, &req };
  
  	t.join();
  
  	return 0;
  }
  ~~~
  
  </details>

</details>

