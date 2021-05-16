# ���̽��� �Ϲ� ������ ����

<details>
  <summary>5-1. ��ųʸ�, ��, �ؽ� ���̺�</summary>

- ��ųʸ��� ������ ���� ��ü�� �����ϰ� ������ ������ Ű(key)�� �ĺ��ȴ�.

- ��(map), �ؽø�(hashmap), ��ȸ ���̺�(loockup table) �Ǵ� �����迭(associative array)��� �Ѵ�.

- �־��� Ű�� ������ ��� ��ü�� �˻�, ����, ������ ȿ�������� �����Ѵ�.

  <details>
    <summary>dict: �������� ��ųʸ�</summary>

  - ��ųʸ� ���� ����

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

  - �Ϲ����� ��� ��ȸ, ����, ���� �� ���� �۾��� �ð� ���⵵�� O(1)�̴�.

  </details>

  <details>
    <summary>collections.OrderedDict: Ű ���� ���� ���</summary>

  - Ű ������ �߿��ϸ� **OrderedDict** Ŭ������ ��������� ����� ��Ȯ�ϰ� ��������.

  - collections ��⿡�� �����;��Ѵ�.

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
    <summary>collections.defaultdict: ������ Ű�� �⺻�� ��ȯ</summary>

  - �����ڿ��� ȣ�� ������ �Լ��� �Է¹ް�, ��û�� Ű�� ã�� �� ���� ��� �� �Լ��� ��ȯ���� ��ȯ�Ѵ�.

  - get() �޼��带 ����ϰų� �Ϲ� ��ųʸ����� KeyError ���ܸ� ��Ƴ��� �Ͱ� ���Ͽ� Ÿ������ �ټ� ���̰� ���α׷����� �ǵ��� �� �� ��Ȯ�ϰ� ���� �� �ִ�.

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
    <summary>collections.ChainMap: ���� ��ųʸ��� ���� �������� �˻�</summary>

  - ���� ���� ��ųʸ��� �ϳ��� �������� �׷�ȭ�Ѵ�.

  - ��ȸ�� ��, Ű�� �߰ߵ� ������ ������ ��ųʸ����� �ϳ��� �˻��Ѵ�.

    ����, ����, ������ ü�ο� �߰��� ù ��° ��ųʸ����� ������ ��ģ��.

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
    <summary>types.MappingProxyType: �б� ���� ��ųʸ��� ����� ���� ����</summary>

  - ������ ��ųʸ��� �����Ϳ� ���� �б� ���� �������̽��� �����Ѵ�.

  - Ŭ������ ����� ���� ���¸� ������ ���� ������ ����� �����ϰ��� �� �� �����ϴ�.

  - ��ųʸ��� ��ü �纻�� ����  �ʿ� ���� �̷��� ������ ������ �� �ִ�.

    ~~~python
    from types import MappingProxyType
    writable = {'one': 1, 'two': 2}
    read_only = MappingProxyType(writable)
    >>> read_only['one']
    1
    >>> read_only['one'] = 32
    TypeError: 'mappingproxy' object does not support item assignment
    # ���� ������Ʈ�� �����ÿ� �ݿ�
    >>> writable['one'] = 42
    mappingproxy({'one': 42, 'two': 2})
    ~~~

  </details>

  <details>
    <summary>���̽��� ��ųʸ�: ���</summary>

  - ��ųʸ��� ���̽��� �߽� ������ ������.
  - ����� dict Ÿ���� ��κ��� ��Ȳ���� '����� ����'.
  - �б� �����̰ų� ���ĵ� ��ųʸ��� ���� Ư���� ������ ���̽� ǥ�� ���̺귯������ �̿밡���ϴ�.

  </details>

</details>

<details>
  <summary>5-2. �迭 ������ ����</summary>

- �ε����� ������� �� ��Ҹ� ȿ�������� ��ġ�� �� �ִ� ���� ũ�� ������ ���ڵ�� �����ȴ�.

- �������� ������ ������ ���ֵǸ�, ��� ã�µ� �ſ� ������.

  <details>
    <summary>list: ���� ���� �迭 (���ô� ����)</summary>

  - ���� �迭�� �����ǹǷ�, ��Ҹ� �߰��ϰų� �����Ҽ� ������, �޸𸮸� �Ҵ��ϰų� ���������ν� ��Ҹ� ��� ����� ũ�⸦ �ڵ����� �����Ѵ�.
  - ������ ��Ҹ� ���� �� �ִ�. �Լ��� ����Ͽ� '��� ��'�� ��ü��.
  - ���� ������ Ÿ���� �����Ѵٴ� ���� ��ü ������ �� ���� ������ �Һ�� �� �ִٴ� ������ �Ǳ⵵ �ϴ�.

  </details>

  <details>
    <summary>tuple: �Һ� �����̳� (���ô� ����)</summary>

  - ����Ʈ�� �޸� ��ü ������ �Ұ����ϴ�.
  - ��Ҹ� �������� �߰��ϰų� ������ �� ������ ������ �� Ʃ���� ��� ��Ҹ� �����ؾ� �Ѵ�.

  </details>

  <details>
    <summary>array.array: �⺻���� Ÿ�� ���� �迭</summary>

  - ����Ʈ, 32��Ʈ ����, �ε��Ҽ��� ���� ��� ���� �⺻ C ��Ÿ�� ������ Ÿ���� ���� �� �ִ� �޸� ȿ������ ���� ������ �����Ѵ�.

  - ����Ʈ�� ��������� ���� ������ Ÿ������ ���ѵ� **Ÿ�� ���� �迭**�̶�� ���̰� �ִ�.

  - ����Ʈ, Ʃ�ú��� ������ ���ؼ��� ȿ�����̹Ƿ� ���� Ÿ���� ��Ҹ� �޸𸮿� �����ϰ� ä�� ���� ������ �� �����ϴ�. 

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
    <summary>str: �����ڵ� ������ �Һ� �迭</summary>

  - str ��ü�� ����Ͽ� �ؽ�Ʈ �����͸� �����ڵ� ������ �Һ� �������� �����ͷ� �����Ѵ�.

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
    # ���ڿ��� ������� �����̴�.
    >>> type('abc')
    <class 'str'>
    >>> type('abc'[0])
    <class 'str'>
    ~~~

  </details>

  <details>
    <summary>bytes: ���� ����Ʈ�� �Һ� �迭</summary>

  - 0���� 255 ������ �������� �Һ��̸� �������� �������̴�.

  - ����Ʈ ��ü�� �Һ������� ���ڿ��� �޸� bytearray��� ���� **���� ����Ʈ �迭** ������ Ÿ���� �ִ�.

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
    <summary>bytes: ���� ����Ʈ�� �Һ� �迭</summary>

  - 0���� 255 ������ �������� �����̸� �������� �������̴�.

  - ��Ҹ� ����ų� ���� ��Ҹ� �����ϰ� ���� �߰��� �� �ִ�.

  - ����Ʈ �迭�� bytes ��ü�� �ٽ� ��Ȱ�� �� ������, ����� �����͸� ���� �����ϹǷ� O(n) �ð��� �ɸ���.

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
    <summary>���� ����</summary>

  - ���������� ���� ���� ������ Ÿ���� ���� ��ü�� �����ؾ� �ϴ°�?
    - �Һ� ������ ������ ���ϴ��� ���ο� ���� **list** �Ǵ� **tuple**�� ����϶�.
  - ���� �����Ͱ� �ְ� �޸� ȿ���� ������ �߿��Ѱ�?
    - array.array�� ����� ���� �ʿ��� ��� �۾��� �����ϴ��� Ȯ������.
    - Numpy �Ǵ� Pandas�� ���� ��Ű���� ����� ����.
  - �����ڵ� ���ڷ� ǥ�õ� �ؽ�Ʈ �����Ͱ� �ֳ�?
    - ���� str�� �������.
    - ���� ���ڿ��� �ʿ��ϸ� list�� �������.
  - �������� ����Ʈ ����� �����ϰ� �ͳ�?
    - ���� �Ұ����� **bytes**�� ����ϰų� ���� ������ **bytearray**�� �������.

  *��κ��� ��� ������ list�� �����ϱ� ��ȣ�Ѵ�. ���߿� �����̳� �޸� ȿ���� ������ �Ǵ� ��쿡�� �ٸ� ������ ��ü�Ѵ�.*

  </details>

</details>

