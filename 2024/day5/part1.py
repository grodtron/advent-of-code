from .data import data

pages = data()

deps = pages.dependencies

def midpoint(arr):
    return arr[int(len(arr)/2)]

total = 0

for seq in pages.sequences:
    seen = set()

    vals = set(seq)

    for v in seq:
        d = deps[v]

        # If any dep has not been seen, we have a problem
        if (d - seen) & vals:
            break
        else:
            seen.add(v)
    else:
        # The sequence was ordered
        total += midpoint(seq)


print(total)


