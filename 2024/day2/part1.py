from .data import data

def diff(pair):
    def minus(a, b):
        return a - b

    return minus(*pair)

def sign(x):
    return -1 if x < 0 else 1


def equal(pair):
    def _eq(a, b):
        return a == b

    return _eq(*pair)


def drop(n, arr):
    for v in arr:
        if n > 0:
            n -= 1
        else:
            yield v



count = 0
for row in data():
    deltas = list(map(diff, zip(row, drop(1, row))))

    signs = list(map(sign, deltas))

    all_same = all(map(equal, zip(signs, drop(1, signs))))

    all_small = all(map(lambda x: 1 <= abs(x) <= 3, deltas))

    if all_small and all_same:
        count += 1


print(f"part1: {count}")
