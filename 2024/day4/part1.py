from .data import data



def add_idx(a, b):
    x,y = a
    r,s = b

    return (x+r, y+s)


grid = data()



count = 0

for idx in grid.findall('X'):
    for i_off in [-1, 0, 1]:
        for j_off in [-1, 0, 1]:

            curr = idx

            for letter in 'MAS':
                curr = add_idx(curr, (i_off, j_off))

                v = grid.get(*curr)

                if v != letter:
                    break
            else:
                count += 1


print(count)
