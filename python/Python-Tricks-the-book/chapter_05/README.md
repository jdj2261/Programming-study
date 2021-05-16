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

</details>

