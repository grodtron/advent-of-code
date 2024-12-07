from .data import data

def rle(arr):

    out = []

    curr = None
    count = None

    for v in sorted(arr):
        if v == curr:
            count += 1
        else:
            if curr:
                out.append((curr, count))

            curr = v
            count = 1

    return out


def matching(arr1, arr2, keyfn = lambda x: x[0]):

    i1 = 0
    i2 = 0

    while i1 < len(arr1) and i2 < len(arr2):

        v1 = arr1[i1]
        v2 = arr2[i2]

        k1 = keyfn(v1)
        k2 = keyfn(v2)

        if k1 == k2:
            yield v1, v2
            i1 += 1
            i2 += 1
        elif k1 < k2:
            i1 += 1
        elif k2 < k1:
            i2 += 1
        else:
            raise Exception("Huh?!")


def mul(a):
    return a[0][0] * a[0][1] * a[1][1]


answer = sum(map(mul, matching(*map(rle, data()))))

print(f"part 2: {answer}")
