# 파이썬의 일반 데이터 구조

<details>
  <summary>5-1. 딕셔너리, 맵, 해시 테이블</summary>

- 딕셔너리는 임의의 수의 객체를 저장하고 각각은 고유의 키(key)로 식별된다.

- 맵(map), 해시맵(hashmap), 조회 테이블(loockup table) 또는 연관배열(associative array)라고 한다.

- 주어진 키와 연관된 모든 객체의 검색, 삽입, 삭제를 효율적으로 수행한다.

  <details>
    <summary>dict: 믿음직한 딕셔너리</summary>

  - 딕셔너리 정의 예시

    ~~~python
    phonebook = {
        'bob' : 7387,
        'jack': 7052,
    }
    squares = {x: x*x for x in range(6)}
    
    >>> phonebook['alice']
    3719
    >>> squares
    {0: 0, 1: 1, 2: 4, 3: 9, 4: 16, 5: 25}
    ~~~

  - 일반적인 경우 조회, 삽입, 갱신 및 삭제 작업의 시간 복잡도는 O(1)이다.

  </details>

  <details>
    <summary>collections.OrderedDict: 키 삽입 순서 기억</summary>

  - 키 순서가 중요하면 **OrderedDict** 클래스를 명시적으로 사용해 명확하게 전달하자.

  - collections 모듈에서 가져와야한다.

    ~~~python
    from collections import OrderedDict
    
    d = OrderedDict(one=1, two=2, three=3)
    >>> d
    OrderedDict([('one', 1), ('two', 2), ('three', 3)])
    
    d['four'] = 4
    >>> d
    OrderedDict([('one', 1), ('two', 2), ('three', 3), ('four', 4)])
    
    >>> d.keys()
    odict_keys(['one', 'two', 'three', 'four'])

  </details>

  <details>
    <summary>collections.defaultdict: 누락된 키의 기본값 반환</summary>

  - 생성자에서 호출 가능한 함수를 입력받고, 요청된 키를 찾을 수 없는 경우 이 함수의 반환값을 반환한다.

  - get() 메서드를 사용하거나 일반 딕셔너리에서 KeyError 예외를 잡아내는 것과 비교하여 타이핑을 다소 줄이고 프로그래머의 의도를 좀 더 명확하게 만들 수 있다.

    ~~~python
    from collections import defaultdict
    dd = defaultdict(list)
    
    dd['dogs'].append('Rufus')
    dd['dogs'].append('Kathrin')
    dd['dogs'].append('Mr Sniffels')
    >>> dd['dogs']
    ['Rufus', 'Kathrin', 'Mr Sniffels']
    ~~~

  </details>

  <details>
    <summary>collections.ChainMap: 여러 딕셔너리를 단일 매핑으로 검색</summary>

  - 여러 개의 딕셔너리를 하나의 매핑으로 그룹화한다.

  - 조회할 때, 키가 발견될 때까지 내부의 딕셔너리들을 하나씩 검사한다.

    삽입, 갱신, 삭제는 체인에 추가된 첫 번째 딕셔너리에만 영향을 미친다.

    ~~~python
    from collections import ChainMap
    dict1 = {'one': 1, 'two': 2}
    dict2 = {'three': 3, 'four': 4}
    chain = ChainMap(dict1, dict2)
    >>> chain
    ChainMap({'one': 1, 'two': 2}, {'three': 3, 'four': 4})
    >>> chain['three']
    3
    >>>chain['missing']
    keyError: 'missing'
    ~~~

  </details>

  <details>
    <summary>types.MappingProxyType: 읽기 전용 딕셔너리를 만들기 위한 래퍼</summary>

  - 감싸진 딕셔너리의 데이터에 대한 읽기 전용 인터페이스를 제공한다.

  - 클래스나 모듈의 내부 상태를 가져올 수는 있으나 쓰기는 제한하고자 할 때 유용하다.

  - 딕셔너리의 전체 사본을 만들  필요 없이 이러한 제약을 적용할 수 있다.

    ~~~python
    from types import MappingProxyType
    writable = {'one': 1, 'two': 2}
    read_only = MappingProxyType(writable)
    >>> read_only['one']
    1
    >>> read_only['one'] = 32
    TypeError: 'mappingproxy' object does not support item assignment
    # 원본 업데이트시 프락시에 반영
    >>> writable['one'] = 42
    mappingproxy({'one': 42, 'two': 2})
    ~~~

  </details>

  <details>
    <summary>파이썬의 딕셔너리: 결론</summary>

  - 딕셔너리는 파이썬의 중심 데이터 구조다.
  - 내장된 dict 타입은 대부분의 상황에서 '충분히 좋다'.
  - 읽기 전용이거나 정렬된 딕셔너리와 같은 특수한 구현도 파이썬 표준 라이브러리에서 이용가능하다.

  </details>

</details>

<details>
  <summary>5-2. 배열 데이터 구조</summary>

- 인덱스를 기반으로 각 요소를 효율적으로 배치할 수 있는 고정 크기 데이터 레코드로 구성된다.

- 연속적인 데이터 구조로 간주되며, 요소 찾는데 매우 빠르다.

  <details>
    <summary>list: 가변 동적 배열 (예시는 생략)</summary>

  - 동적 배열로 구현되므로, 요소를 추가하거나 제거할수 있으며, 메모리를 할당하거나 해제함으로써 요소를 담는 저장소 크기를 자동으로 조정한다.
  - 임의의 요소를 가질 수 있다. 함수를 비롯하여 '모든 것'이 객체다.
  - 여러 데이터 타입을 지원한다는 것은 전체 구조에 더 많은 공간이 소비될 수 있다는 단점이 되기도 하다.

  </details>

  <details>
    <summary>tuple: 불변 컨테이너 (예시는 생략)</summary>

  - 리스트와 달리 객체 변경이 불가능하다.
  - 요소를 동적으로 추가하거나 제거할 수 없으며 생성할 때 튜플의 모든 요소를 정의해야 한다.

  </details>

  <details>
    <summary>array.array: 기본적인 타입 지정 배열</summary>

  - 바이트, 32비트 정수, 부동소수점 숫자 등과 같은 기본 C 스타일 데이터 타입을 담을 수 있는 메모리 효율적인 저장 공간을 제공한다.

  - 리스트와 비슷하지만 단일 데이터 타입으로 제한된 **타입 지정 배열**이라는 차이가 있다.

  - 리스트, 튜플보다 공간에 대해서는 효율적이므로 같은 타입의 요소를 메모리에 빽빽하게 채워 많이 저장할 때 유용하다. 

    ~~~python
    from array import array
    arr = array('f', [1.0, 1.5, 2.0, 2.5])
    >>> arr
    array('f', [1.0, 1.5, 2.0, 2.5])
    arr[1] = 2.5
    >>> arr
    array('f', [1.0, 2.5, 2.0, 2.5])
    array[1] = 'hello'
    >>> arr
    TypeError: must be real number, not str
    ~~~

  </details>

  <details>
    <summary>str: 유니코드 문자의 불변 배열</summary>

  - str 객체를 사용하여 텍스트 데이터를 유니코드 문자의 불변 연속적인 데이터로 저장한다.

    ~~~python
    arr = 'abcd'
    >>> arr[1] = 'e'
    TypeError: 'str' object does not support item assignment
    >>> del arr[1]
    TypeError: 'str' object doesn't support item deletion
    >>> list('abcd')
    ['a', 'b', 'c', 'd']
    >>> ''.join(list('abcd'))
    'abcd'
    # 문자열은 재귀적인 구조이다.
    >>> type('abc')
    <class 'str'>
    >>> type('abc'[0])
    <class 'str'>
    ~~~

  </details>

  <details>
    <summary>bytes: 단일 바이트의 불변 배열</summary>

  - 0에서 255 범위의 정수에서 불변이며 연속적인 데이터이다.

  - 바이트 객체는 불변이지만 문자열과 달리 bytearray라는 전용 **가변 바이트 배열** 데이터 타입이 있다.

    ~~~python
    arr = bytes((0, 1, 2, 3))
    >>> arr[1]
    1
    >>> arr
    b'\x00\x01\x02\x03'
    >>> bytes((0, 300))
    ValueError: bytes must be in range(0, 256)
    >>> arr[1] = 23
    TypeError: 'bytes' object does not support item assignment
    ~~~

  </details>

  <details>
    <summary>bytes: 단일 바이트의 불변 배열</summary>

  - 0에서 255 범위의 정수에서 가변이며 연속적인 데이터이다.

  - 요소를 덮어쓰거나 기존 요소를 제거하고 새로 추가할 수 있다.

  - 바이트 배열은 bytes 객체로 다시 변활될 수 있으나, 저장된 데이터를 전부 복사하므로 O(n) 시간이 걸린다.

    ~~~python
    arr = bytearray((0, 1, 2, 3))
    >>> arr[1]
    1
    >>> arr
    bytearray(b'\x00\x01\x02\x03')
    arr[1] = 23
    >>> arr
    bytearray(b'\x00\x17\x02\x03')
    >>> bytes(arr)
    b'\x00\x17\x02\x03'
    ~~~

  </details>

  <details>
    <summary>요점 정리</summary>

  - 잠재적으로 여러 가지 데이터 타입의 임의 객체를 저장해야 하는가?
    - 불변 데이터 구조를 원하는지 여부에 따라 **list** 또는 **tuple**을 사용하라.
  - 숫자 데이터가 있고 메모리 효율과 성능이 중요한가?
    - array.array를 사용해 보고 필요한 모든 작업을 수행하는지 확인하자.
    - Numpy 또는 Pandas와 같은 패키지를 사용해 보자.
  - 유니코드 문자로 표시된 텍스트 데이터가 있나?
    - 내장 str을 사용하자.
    - 가변 문자열이 필요하면 list를 사용하자.
  - 연속적인 바이트 블록을 저장하고 싶나?
    - 변경 불가능한 **bytes**를 사용하거나 변경 가능한 **bytearray**를 사용하자.

  *대부분의 경우 간단한 list로 시작하길 선호한다. 나중에 성능이나 메모리 효율이 문제가 되는 경우에만 다른 것으로 교체한다.*

  </details>

</details>

<details>
  <summary>5-3. 레코드, 구조체, 데이터 전송 객체</summary>

- 레코드 데이터 구조는 고정된 수의 필드를 제공하며 각 필드는 이름을 가질 수 있고 서로 다른 타입을 담을 수 도 있다.

  <details>
    <summary>dict: 간단한 데이터 객체</summary>

  - 맵 또는 연관 배열이라고도 하며 주어진 키와 연관된 객체를 효율적으로 검색, 삽입, 삭제할 수 있다.
  - 객체 변경이 가능하며 필드는 언제든지 자유롭게 추가, 제거할 수 있기 때문에 철자가 틀린 필드명에 대한 보호 기능이 거의 없다.

  </details>

  <details>
    <summary>tuple: 불변 객체 그룹</summary>

  - 변경이 불가능하며 생성된 후에는 수정할 수 없다.
  - 리스트에서 튜플로 전환하여 프로그램에서 추가 성능을 쥐어짜려는 시도는 잘못된 접근일 수 있다.
  - 튜플에 저장된 개별 속성에 이름을 지정할 수 없으므로 코드 가독성에 영향을 준다.
  - 튜플에 저장된 필드 수를 가능한 한 적게 유지하는 것이 좋다.

  </details>

  <details>
    <summary>collections.namedtuple: 편리한 데이터 객체</summary>

  - 데이터를 더 잘 구조화하여 코드를 정돈하고 가독성이 좋게 만들 수 있는 간단한 방법이다.

  - 일반 튜플처럼 변경할 수 없다.

    ~~~python
    from collections import namedtuple
    Car = namedtuple('Car', 'color mileage automatic')
    >>> Car1 = Car('red', 3812.4, True)
    >>> Car1
    Car(color='red', mileage=3812.4, automatic=True)
    ~~~

  </details>

  <details>
    <summary>typing.NamedTuple: 개선된 네임드튜플</summary>

  - namedtuple과 매우 흡사하며 차이점은 새로운 레코드 타입을 정의하고 타입 힌트를 지원하도록 갱신된 구문이다.

    ~~~python
    class Car(NamedTuple):
      color: str
      mileage: float
      automatic: bool
    ~~~

  </details>

  <details>
    <summary>struct.Struct: 직렬화된 C 구조체</summary>

  - bytes 객체로 직렬화된 C 구조체와 파이썬 값 사이의 변환을 수행한다.
  - 파일에 저장되거나 네트워크로부터 들어오는 이진 데이터를 처리하는 데 사용할 수 있다.

  </details>

  <details>
    <summary>types.SimpleNamespace: 세련된 속성 접근</summary>

  - 딕셔너레이서 사용하는 obj['key'] 대괄호 인덱스 문법 대신 obj.key '점' 속성 접근을 사용할 수 있다.

    ~~~python
    from types import SimpleNamespace
    car1 = SimpleNamespace(color='red', mileage=3812.4, automatic=True)
    # 인스턴스는 속성 접근을 지원하고 변경할 수 있다.
    car.mileage = 12
    del car.automatic
    ~~~

  </details>

  <details>
    <summary>요점 정리</summary>

  - **몇 개(2~3)의 필드만 갖고 있다.** -> 일반 튜플 객체를 사용하자 (예를들어 삼차원 공간에서 (x, y , z) 점을 생각해 보자.)
  - **불변 필드가 필요하다.** -> 튜플, collections.namedtuple, typing.NamedTuple이 좋은 옵션이다.
  - **오타가 발생하지 않도록 필드 이름을 고정할 필요가 있다.** -> collections.namedtuple, typing.NamedTuple을 이용하자.
  - **간단하게 유지하기를 원한다** -> 딕셔너리 객체가 좋은 선택일 수 있다.
  - **데이터 구조를 완전히 제어할 필요가 있다.** -> @property의 세터와 게터를 사용하여 사용자 정의 클래스를 작성하자.
  - **객체에 메서드를 추가해야 한다.** -> collections.namedtuple, typing.NamedTuple을 확장하여 작성하자.
  - **데이터를 디스크에 저장하거나 네트워크로 전송해야 한다.** -> struct.Struct를 사용하자.

  </details>

</details>

<details>
  <summary>5-4. 세트와 멀티세트</summary>

- **set**는 중복 요소를 허용하지 않는 정렬되지 않는 컬렉션

  <details>
    <summary>set: 나만의 믿음직한 세트</summary>

  ~~~8spython
  vowels = {'a', 'e', 'i', 'o', 'u'}
  >>> 'e' in vowels
  True
  
  letters = set('alice')
  >>> letters.intersection(vowels)
  {'a', 'e', 'i'}
  
  vowels.add('x')
  >>> vowels
  {'i', 'a', 'u', 'o', 'x', 'e'}
  ~~~

  </details>

  <details>
    <summary>frozenset: 불변 세트</summary>

  - set의 '불변' 버전으로 생성된 후에는 변경할 수 없다.(삽입이나 삭제는 허용되지 않는다.)

  - 요소에 대한 쿼리 작업만 허용한다

    ~~~python
    vowels = frozenset({'a', 'e', 'i', 'o', 'u'})
    vowels.add('p')
    >>> AttributeError: 'frozenset' object has no attribute 'add'
    d = {frozenset({1, 2, 3}): 'hello'}
    print(d[frozenset({1,2,3})])
    >>> 'hello'
    ~~~

  </details>
  
  <details>
    <summary>collections.Counter: 멀티세트</summary>
  
  - 요소가 두 번 이상 나타날 수 있는 멀티세트 타입을 구현한다.
  
  - 요소가 세트의 일부인지 아닌지뿐 아니라 세트에 포함된 '횟수'를 추적할 때 유용하다.
  
    ~~~python
    from collections import Counter
    inventory = Counter()
    loot = {'sword': 1, 'bread': 3}
    inventory.update(loot)
    print(inventory)
    >>> Counter({'bread': 3, 'sword': 1})
    
    more_loot = {'sword': 1, 'apple': 3}
    inventory.update(more_loot)
    print(inventory)
    >>> Counter({'bread': 3, 'apple': 3, 'sword': 2})
    ~~~
  
  - len()을 호출하면 멀티세트 고유 요소 수를 반환하고, sum() 함수를 사용하면 총 요소 수가 반한된다.
  
    ~~~python
    print(f"len() : {len(inventory)}")
    print(f"sum() : {sum(inventory.values())}")
    >>> len() : 3
    >>> sum() : 8
    ~~~
  
  </details>
  
  <details>
    <summary>요점 정리</summary>
  
  - 변경 가능한 세트가 필요하면 내장 set 타입을 사용하자.
  - frozenset 객체는 해시가 가능하며 딕셔너리 또는 세트의 키로 사용할 수 있다.
  - collections.Counter는 멀티세트 또는 bag 데이터 구조를 구현한다.

</details>

<details>
  <summary>5-5. 스택(LIFO)</summary>

- 리스트나 배열과 달리 스택은 객체로의 임의 접근을 허용하지 않는다.

- 삽입 및 삭제 작업에 O(1) 시간이 걸린다.

- 언어 구문 분석 및 런타임 메모리 관리('호출 스택')에 쓰인다.

  트리 또는 그래프 구조에서 깊이 우선 탐색(DFS)은 스택을 활용한 알고리즘이다.

  <details>
    <summary>list: 간단한 내장 스택</summary>

  - 최적의 성능을 위해 리스트 기반 스택은 더 높은 인덱스 쪽으로 커지고 더 낮은 인덱스 쪽으로 줄어들어야 한다.
  - 앞쪽부터 추가, 제거하는 작업은 훨씬 느리고 O(n) 시간이 필요하다.

  </details>

  <details>
    <summary>collections.deque: 빠르고 강력한 스택</summary>

  - deque 클래스는 O(1) 시간에 어느 쪽에서든 요소를 추가, 삭제할 수 있는 양단 큐다.

    양쪽 끝에서 요소를 동일하게 추가, 제거해도 되기 때문에 큐와 스택으로 모두 사용할 수 있다.

  - 스택 중간의 임의 원소에 접긓나려 할 때는 나쁜 O(n) 성능을 갖는다.

  </details>

  <details>
    <summary>queue.LifoQueue: 병렬 컴퓨팅을 위한 잠금 체계</summary>

  - LifoQueue 스택 구현은 동기 방식이며 동시에 여러 생산자와 소비자를 지원하는 잠금 체계를 제공한다.

  - 용도에 따라 쓰는 걸 추천한다.

    ~~~python
    s = LifoQueue()
    s.put('eat')
    s.put('sleep')
    s.put('code')
    print(s)
    >>> <queue.LifoQueue object at 0x104295d30>
    
    print(s.get())
    >>> code
    print(s.get())
    >>> sleep
    print(s.get())
    >>> eat
    s.get_nowait() # queue.Empty (에러 발생)
    s.get() # 블록되어 영원히 기다린다.
    ~~~

  </details>

  <details>
    <summary>파이썬의 스택 구현 비교하기</summary>

  - collections.deque로 스택을 구현하자.

  </details>

</details>

<details>
  <summary>5.6 큐(FIFO)</summary>

- 병렬 프로그래밍과 스케줄링 문제를 해결하는 데 종종 도움이 된다.

  너비 우선 탐색(BFS)은 큐를 활용한 알고리즘이다.

- 스케쥴링 알고리즘은 종종 우선순위 큐를 내부적으로 사용한다.

  우선순위 큐는 언제 삽입되었느냐와 상관 없이 '우선순위가 가장 높은' 항목을 먼저 제거한다.

  <details>
    <summary>list: 끔찍하게 느린 큐</summary>

  - 리스트로 큐는 절대 사용하지 말자. 매우 느리다!

  </details>

  <details>
    <summary>collections.deque: 빠르고 강력한 큐</summary>

  - collections.deque가 가장 좋은 선택이다.

  </details>

  <details>
    <summary>queue.Queue: 병렬 컴퓨팅을 위한 잠금 체계</summary>

  - 동기 방식으로 구현되었으며 동시에 여러 생산자와 소비자에게 잠금 체계를 제공한다.
  - 잠금체계가 필요하지 않다면 queue.Queue 대신 collections.deque를 범용 큐로 사용하자.

  </details>

  <details>
    <summary>multiprocessing.Queue: 공유 작업 큐</summary>

  - 큐 안의 항목들을 여러 작업자가 동시에 처리할 수 있게 해 주는 공유 작업 큐 구현이다.
  - GIL 때문에 CPython에서는 프로세스 기반 병렬화가 널리 사용된다.
  - 프로세스 간에 데이터를 공유하기 위한 특별한 큐 구현인 multiprocessing.Queue를 사용하면 GIL 제한을 해결하고 여러 프로세스 간에 작업을 쉽게 배포 할 수 있다.

  </details>

</details>

<details>
  <summary>5.7 우선순위 큐</summary>

- 숫자 가중치가 있는 레코드 집합을 관리하는 컨테이너 데이터 구조이다.

  레코드 집합에서 '가장 작은' 키 또는 '가장 큰' 키를 사용하여 레코드에 빠르게 접근할 수 있다.

- 일반적으로 긴급성이 높은 작업에 우선순위를 부여하는 등 스케줄링 문제 처리에 사용된다.

  <details>
    <summary>list: 수동으로 정렬된 큐 유지하기</summary>

  - 정렬된 list를 사용하면 가장 작은 항목 또는 가장 큰 항목을 신속하게 찾아서 삭제할 수 있지만,

    단점은 새 항목을 삽입하는 데는 느린 O(n) 시간이 걸린다는 점이다.

  - 리스트에 항목을 추가한 후 다시 정렬해 순서를 유지하려면 적어도 O(nlogn) 시간이 걸린다.

  </details>

  <details>
    <summary>heapq: 리스트 기반 이진 힙</summary>

  - 우선순위 큐를 구현하기에 가장 좋은 선택이다.

  - 가장 작은 항목의 삽입과 추출을 O(logn) 시간에 해낸다.

    ~~~python
    q = []
    
    heapq.heappush(q, (2, 'code'))
    heapq.heappush(q, (1, 'eat'))
    heapq.heappush(q, (3, 'sleep'))
    
    while q:
        next_item = heapq.heappop(q)
        print(next_item)
    >>> (1, 'eat')
    		(2, 'code')
    		(3, 'sleep')
    ~~~

  </details>

  <details>
    <summary>queue.PriorityQueue: 아름다운 우선순위 큐</summary>

  - 내부적으로 heapq를 사용하고 동일한 시간과 공간 복잡성을 공유한다.

    다른 점은 동기 방식이며 동시에 여러 생산자와 소비자를 지원하는 잠금 체계를 제공한다는 것이다

  </details>

</details>
