import heapq
from queue import LifoQueue
from collections import Counter
from types import MappingProxyType
from collections import ChainMap
from collections import defaultdict
from collections import OrderedDict

d = OrderedDict(one=1, two=2, three=3)
print(d)

d['four'] = 4
print(d)

print(d.keys())

dd = defaultdict(list)

dd['dogs'].append('Rufus')
dd['dogs'].append('Kathrin')
dd['dogs'].append('Mr Sniffels')
print(dd['dogs'])

dict1 = {'one': 1, 'two': 2}
dict2 = {'three': 3, 'four': 4}
chain = ChainMap(dict1, dict2)
print(chain)

writable = {'one': 1, 'two': 2, 'three': 3}
read_only = MappingProxyType(writable)

# read_only['one'] = 32
# print(read_only)

# from array import array
# arr = array('f', [1.0, 1.5, 2.0, 2.5])
# print(arr)
# arr[1] = 2.5
# print(arr)
# arr[1] = 'hello'
# print(arr)

data = 'abcd'
print(type(data))
# data[1] = 'e'
# print(data[1])
# del data[1]

arr = bytes((0, 1, 2, 3))
print(arr[1])
print(arr)
# print(bytes((0, 300)))
# arr[1] = 23

arr = bytearray((0, 1, 2, 3))
arr[1] = 23
print(bytes(arr))

# vowels = frozenset({'a', 'e', 'i', 'o', 'u'})
# vowels.add('p')

d = {frozenset({1, 2, 3}): 'hello'}
print(d[frozenset({1, 2, 3})])

inventory = Counter()

loot = {'sword': 1, 'bread': 3}
inventory.update(loot)
print(inventory)

more_loot = {'sword': 1, 'apple': 3}
inventory.update(more_loot)
print(inventory)

print(f"len() : {len(inventory)}")
print(f"sum() : {sum(inventory.values())}")

s = LifoQueue()
s.put('eat')
s.put('sleep')
s.put('code')
print(s)

print(s.get())
print(s.get())
print(s.get())

# s.get_nowait()
# s.get()

q = []
q.append((2, 'code'))
q.append((1, 'eat'))
q.append((3, 'sleep'))
q.append((3, 'sleep'))
q.append((2, 'test'))
q.append((1, 'dd'))

# q.sort(reverse=True)
q.sort(key=lambda x: (x[0], x[1]), reverse=True)
print(q)

# while q:
#     next_item = q.pop()
#     print(next_item)


q = []

heapq.heappush(q, (2, 'code'))
heapq.heappush(q, (1, 'eat'))
heapq.heappush(q, (3, 'sleep'))

while q:
    next_item = heapq.heappop(q)
    print(next_item)
