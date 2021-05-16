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

</details>

