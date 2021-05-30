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
  
  <details>
    <summary>23.2.8 익셉션 복제와 다시 던지기</summary> 
  
  ~~~c++
  #include <thread>
  #include <iostream>
  #include <exception>
  #include <stdexcept>
  
  using namespace std;
  
  void doSomeWork()
  {
  	for (int i = 0; i < 5; ++i) {
  		cout << i << endl;
  	}
  	cout << "Thread throwing a runtime_error exception..." << endl;
  	throw runtime_error("Exception from thread");
  }
  
  void threadFunc(exception_ptr& err)
  {
  	try {
  		doSomeWork();
  	} catch (...) {
  		cout << "Thread caught exception, returning exception..." << endl;
  		err = current_exception();
  	}
  }
  
  void doWorkInThread()
  {
  	exception_ptr error;
  	// Launch thread
  	thread t{ threadFunc, ref(error) };
  	// Wait for thread to finish
  	t.join();
  	// See if thread has thrown any exception
  	if (error) {
  		cout << "Main thread received exception, rethrowing it..." << endl;
  		rethrow_exception(error);
  	} else {
  		cout << "Main thread did not receive any exception." << endl;
  	}
  }
  
  int main()
  {
  	try {
  		doWorkInThread();
  	} catch (const exception& e) {
  		cout << "Main function caught: '" << e.what() << "'" << endl;
  	}
  	return 0;
  }
  ~~~
  
  ~~~
  0
  1
  2
  3
  4
  Thread throwing a runtime_error exception...
  Thread caught exception, returning exception...
  Main thread received exception, rethrowing it...
  Main function caught: 'Exception from thread'
  ~~~
  
  </details>

</details>

<details>
  <summary>23.3. 아토믹 연산 라이브러리</summary> 

- 아토믹 타입(atomic type)을 사용하면 동기화 기법을 적용하지 않고 읽기와 쓰기를 동시에 처리하는 아토믹 접근이 가능하다.

- mutex 객체와 같은 동기화 기법을 따로 사용하지 않고 스레드에 안전하게 만들 수 있다.

  ~~~c++
  atomic<int> counter(0); // 전역변수
  ++counter;				// 여러 스레드에서 실행한다.
  ~~~

- 특정 타입에 대해 아토믹 연산을 처리할 경우 뮤텍스와 같은 동기화 메커니즘을 내부적으로 사용하기도 한다.

  <details>
    <summary>23.3.1 아토믹 타입 사용예</summary> 

  - std::this_thread::sleep_for()로 루프를 한 바퀴 돌 때마다 일정한 시간을 지연시킨다.

    ~~~ c++
    void func(int& counter)
    {
    	for (int i = 0; i < 100; ++i) {
    		++counter;
    		cout << counter << endl;
    		this_thread::sleep_for(chrono::milliseconds(1ms));
    	}
    }
    ~~~

    

    ~~~c++
    int main()
    {
    	int counter = 0;
    	vector<thread> threads;
    	for (int i = 0; i < 10; ++i) {
    		threads.push_back(thread{ func, ref(counter) });
    	}
    	for (auto& t : threads) {
    		t.join();
    	}
    	cout << "Result = " << counter << endl;
    	return 0;
    }
    ~~~

  - 아토믹이나 스레드 동기화 메커니즘을 사용하지 않고 단순하게 구현하면 데이터 경쟁이 발생한다.

    ~~~
    Result = 982
    Result = 977
    Result = 984
    ~~~

  - 아래와 같이 수정하여 실행한다.

    ~~~C++
    void func(atomic<int>& counter)
    {
    	for (int i = 0; i < 100; ++i) {
    		++counter;
    		this_thread::sleep_for(chrono::milliseconds(1));
    	}
    }
    int main()
    {
    	atomic<int> counter(0);
    	vector<thread> threads;
    	for (int i = 0; i < 10; ++i) {
    		threads.push_back(thread{ func, ref(counter) });
    	}
    	for (auto& t : threads) {
    		t.join();
    	}
    	cout << "Result = " << counter << endl;
    	return 0;
    }
    ~~~

    ~~~
    Result = 1000
    Result = 1000
    Result = 1000
    ~~~

  - 동기화 메커니즘을 따로 추가하지 않고도 스레드에 안전하고 데이터 경쟁이 발생하지 않도록 만들 수 있다.

    그런데 이렇게 수정하면 성능 문제가 발생하기 때문에 이 부분을 처리하는데 걸리는 시간을 최소화하도록 구성해야 한다.

  </details>

</details>

<details>
  <summary>23.4 상호 배제</summary> 

- 멀티스레드 프로그램을 작성할 때는 반드시 연산의 순서를 신중하게 결정해야 한다.

  복잡하게 구성된 데이터를 여러 스레드가 동시에 접근할 때는 동기화 메커니즘을 사용해야 한다.

  mutex와 lock 클래스를 활용하여 여러 스레드를 동기화하여 구현하자.

  <details>
    <summary>23.4.1 mutex</summary> 

  - mutex의 사용법은 다음과 같다.

    - 다른 스레드와 공유하는 메모리를 사용하려면 먼저 mutex 객체에 락을 걸어야 한다.

      다른 스레드가 먼저 락을 걸어놨다면 그 락이 해제되거나 타임아웃으로 지정된 시간이 경과해야 쓸 수 있다.

    - 스레드가 락을 걸었다면 공유 메모리를 마음껏 쓸 수 있고, 공유 데이터를 사용하려는 스레드마다 뮤텍스에 대한 락을 걸고 해제하는 동작을 정확히 구현해야 한다.

    - 두 개 이상의 스레드가 락을 기다리고 있다면 어느 스레드가 먼저 락을 걸어 작업을 진행할지 알 수 없다.

  - c++ 표준은 *시간 제약이 없는 뮤텍스*와 *시간 제약이 있는 뮤텍스* 클래스를 제공한다.

    1. 시간 제약이 없는 뮤텍스 클래스

       std::mutex, std::recursive_mutex, std::shared_mutex (c++17)

       - lock() : 호출하는 측의 스레드가 락을 완전히 걸 때까지 대기한다.
       - try_lock() : 호출하는 측의 스레드가 락을 걸도록 시도한다. 현재 다른 스레드가 락을 걸었다면 호출이 즉시 리턴된다. 락을 걸었다면 try_lock()은 true를 리턴하고, 그렇지 않으면 false를 리턴한다.
       - unlock() : 호출하는 측의 스레드가 현재 걸어둔 락을 해제한다.

       - std::mutex : 한 스레드만 가질 수 있으며 이 뮤텍스를 소유하려면 lock()을 호출하고 대기한다.

         try_lock()을 호출하면 락 걸기에 실패해 곧바로 리턴된다. 뮤텍스를 이미 확보한 스레드가 같은 뮤텍스에 대해 lock()이나 try_lock()을 또 호출하면 데드락이 발생하므로 조심해야 한다.

       - std::recursive_mutex: 이미 recursive_mutex를 확보한 스레드가 동일한 recursive_mutex에 대해 lock()이나 try_lock을 또 다시 호출할 수 있다.

       - std::shared_mutex: 이미 락을 건 스레드는 같은 뮤텍스에 대해 한 번 더 락을 걸 수 없다.

    2. 시간 제약이 있는 뮤텍스 클래스

       std::timed_mutex, std::recursive_time_mutex, std::shared_timed_mutex

  **앞에서 나온 뮤텍스 클래스에 대한 락/언락 메서드를 직접 호출하면 안된다. ** **RAII 원칙에 위배**

  **데드락을 방지하려면 반드시 락 클래스를 사용하자. 락 객체가 스코프를 벗어나면 자동으로 뮤텍스를 언락해주기 때문에 메서드를 일일이 정확한 시점에 호출하지 않아도 된다.**

  </details>

  <details>
    <summary>23.4.2 lock</summary> 

  - std::lock_guard, unique_lock, shared_lock, scoped_lock(c++17)
    1.  lock_guard
       - explicit lock_guard(muext_type& m);
       - lock_gaurd(mutex_type& m, adopt_lock_t);
    2. unique_lock
       - 락 선언 후 한참 뒤 실행될 때 락을 걸도록 지연시키는 고급 기능 제공
    3. shared_lock
       - unique_lock와 비슷하나 내부 공유 뮤텍스에 대해 공유 소유권 관련 메서드를 호출한다는 점이 다름
    4. scoped_lock
       - c++ 17 이상이라면 이걸쓰자.

</details>

