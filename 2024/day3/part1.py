from .data import data
import re

pattern = r'mul\(([0-9]{1,3}),([0-9]{1,3})\)'

total = 0
for m in re.finditer(pattern, data()):
    if m:
        total += int(m.group(1)) * int(m.group(2))
        #print(f'{m.group(1)}, {m.group(2)}')

print(total)
