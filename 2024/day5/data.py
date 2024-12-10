from aocd import get_data

import re
from collections import defaultdict, namedtuple

Data = namedtuple('Data', ['sequences', 'dependencies'])


def data():

    dependencies = defaultdict(set)
    sequences = []

    for line in get_data(day=5, year=2024).splitlines():
        m = re.match(r'^([0-9]+)\|([0-9]+)$', line)

        if m:
            before = int(m.group(1))
            after  = int(m.group(2))

            dependencies[after].add(before)

        elif ',' in line:
            sequences.append(list(map(int, line.split(','))))

    return Data(sequences=sequences, dependencies=dependencies)









