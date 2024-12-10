from aocd import get_data


def data():

    out = ([], [])

    for line in get_data(day=2, year=2024).splitlines():
        yield list(map(int, line.split()))







