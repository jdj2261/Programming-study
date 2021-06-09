# class RepeaterIterator:
#     def __init__(self, source):
#         self.source = source

#     def __next__(self):
#         return self.source.value


class Repeater:
    def __init__(self, value):
        self.value = value

    def __iter__(self):
        return self

    def __next__(self):
        return self.value


# repeater = Repeater('Hello')

# for item in repeater:
#     print(item)

# generator 함수


def bounded_repeater(value, max_repeats):
    for i in range(max_repeats):
        yield value


def test():
    pass


for x in bounded_repeater("Hi", 4):
    print(x)

# generator chain
def integers():
    for i in range(1, 9):
        yield i


def squared(seq):
    for i in seq:
        yield i * i


def negated(seq):
    for i in seq:
        yield -i


chane = negated(squared(integers()))
print(list(chane))


integers = range(8)
squared = (i * i for i in integers)
negated = (-i for i in squared)

print(list(negated))
