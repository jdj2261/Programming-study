from collections import OrderedDict

d = OrderedDict(one = 1, two = 2, three = 3)
print(d)

d['four'] = 4
print(d)

print(d.keys())

from collections import defaultdict
dd = defaultdict(list)

dd['dogs'].append('Rufus')
dd['dogs'].append('Kathrin')
dd['dogs'].append('Mr Sniffels')
print(dd['dogs'])

from collections import ChainMap
dict1 = {'one': 1, 'two': 2}
dict2 = {'three': 3, 'four': 4}
chain = ChainMap(dict1, dict2)
print(chain)

from types import MappingProxyType
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