from .data import data

def diff(a, b):
    return abs(a-b)

answer = sum(map(lambda x: diff(*x), zip(*map(sorted, data()))))

print(f"part 1: {answer}")
