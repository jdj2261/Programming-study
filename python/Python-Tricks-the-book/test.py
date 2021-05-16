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
print(chain[])