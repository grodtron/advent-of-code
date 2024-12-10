from .data import data, Matrix


def add(a, b):
    x,y = a
    r,s = b

    return (x+r, y+s)


def minus(idx):
    a, b = idx

    return (-a, -b)

def rotate_90(idx):
    a, b = idx

    return (-b, a)


"""
Find all pairs of diagonal "MAS" strings in the input grid. For example

M M
 A
S S

first we find the location of all "A"s in the grid. Then we check for the
4 possible orientations of an X-MAS centered on that A.

We create the X-MAS template by basically reasoning about the offset from the
center as a vector, and adding, subtracting and rotating it to find the correct
positions.
"""


grid = data()

count = 0

for idx in grid.findall('A'):
    offset = (1,1)
    for i in range(4):
        offset = rotate_90(offset)

        center = idx

        if (grid.get(*add(center, offset)) == 'M' and
            grid.get(*add(center, rotate_90(offset))) == 'M' and
            grid.get(*add(center, minus(offset))) == 'S' and
            grid.get(*add(center, minus(rotate_90(offset)))) == 'S'):
            count += 1



print(count)
