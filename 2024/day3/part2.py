from .data import data
import re

pattern = r'(mul|do|don\'t)\((([0-9]{1,3}),([0-9]{1,3}))?\)'

total = 0
enabled = True
for m in re.finditer(pattern, data()):
    if m:

        command = m.group(1)

        if command == 'mul' and enabled:
            total += int(m.group(3)) * int(m.group(4))
        elif command == 'do':
            enabled = True
        elif command == 'don\'t':
            enabled = False

print(total)
