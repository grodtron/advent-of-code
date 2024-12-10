from aocd import get_data

class Matrix:
    def __init__(self, data):
        self.data = data
        self.width = len(data[0])
        self.height = len(data)

    def findall(self, value):
        for j, row in enumerate(self.data):
            for i, val in enumerate(row):
                if val == value:
                    yield (i, j)

    def get(self, i, j):
        if 0 <= i < self.width and 0 <= j < self.height:
            return self.data[j][i]
        else:
            return None




def data():
    lines = get_data(day=4, year=2024).splitlines()

    return Matrix(lines)








