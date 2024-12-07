from aocd import get_data


def data():

    out = ([], [])

    for line in get_data(day=1, year=2024).splitlines():
        a, b = line.split()

        out[0].append(int(a))
        out[1].append(int(b))

    return out







