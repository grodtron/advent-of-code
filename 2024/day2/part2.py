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

def andd(pair):
    def _and(a, b):
        return a and b

    return _and(*pair)


def drop(n, arr):
    for v in arr:
        if n > 0:
            n -= 1
        else:
            yield v

def nott(x):
    return not x


def count(pred, arr):
    return sum(1 if pred(x) else 0 for x in arr)


def idx(pred, arr):
    for i, v in enumerate(arr):
        if pred(v):
            return i

    raise Exception("All values are true")


def delete(to_delete, arr):
    for i, v in enumerate(arr):
        if i != to_delete:
            yield v



def is_safe(row, can_recurse=True):

    row = list(row)

    deltas = list(map(diff, zip(row, drop(1, row))))

    signs = list(map(sign, deltas))

    expected_sign = sign(sum(signs))
    right_sign = list(map(lambda x: x == expected_sign, signs))

    small_abs =  list(map(lambda x: 1 <= abs(x) <= 3, deltas))

    good = list(map(andd, zip(right_sign, small_abs)))

    if all(good):
        #print(f"{row} -> {deltas} -> {good} => SAFE")
        return True
    #elif can_recurse and count(nott, good) == 1:
    #    i = idx(nott, good)
#
#        print(f"!!! {row} -> {deltas} -> {good} => bad @ {i}")
#
#        return is_safe(delete(i, row), False) or is_safe(delete(i+1, row), False)
    elif can_recurse:
        for i in range(len(row)):
            if is_safe(delete(i, row), False):
                return True

        return False
    else:
        return False


n = 0
for row in data():
    print(">>>>")
    if is_safe(row):
        n += 1


print(f"part2: {n}")
