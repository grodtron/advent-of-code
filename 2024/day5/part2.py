from .data import data

pages = data()

deps = pages.dependencies

def midpoint(arr):
    return arr[int(len(arr)/2)]

total = 0

# We want to sort each sequence based on the dependencies between
# values. This code assumes that there is always only a single correct
# ordering.
for seq in pages.sequences:
    # The dependencies may include items that are not in our list.
    # We will always mask these out, as they're not relevant
    universe = set(seq)

    # A running collection of all of the unsorted values, and their
    # unsatisfied dependencies
    candidates = [(v, deps[v] & universe) for v in seq]

    out = []

    # As long as there are any unsorted values, we will keep iterating,
    # moving one value into the sorted output per iteration
    while candidates:
        # Here we make the assumption that there will only ever be one
        # unsorted value with all dependencies satisfied. We pull it out
        # of the candidates list
        nxt, = [v for v, deps in candidates if not deps]

        # Then, we update the candidates list, by filtering out the value
        # that has all dependencies satisfied, and removing the value from
        # the dependencies of all remaining values
        candidates = [(v, deps - {nxt}) for v, deps in candidates if v != nxt]

        out.append(nxt)

    # Finally the puzzle asks for the sum of the midpoint of all sequences
    # that were not originally sorted.
    if out != seq:
        total += midpoint(out)



print(total)


