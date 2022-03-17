#!/usr/bin/python3
"""  Module for function island_perimeter  """


def island_perimeter(grid):
    """function that returns the perimeter of the island described in grid
    """
    count = 0
    row = len(grid)
    col = len(grid[0]) if row else 0

    for i in range(row):
        for j in range(len(grid[i])):
            idx = [(i - 1, j), (i, j - 1), (i, j + 1), (i + 1, j)]
            aux = [1 if pos[0] in range(row) and pos[1] in range(col) else 0
                   for pos in idx]
            if grid[i][j]:
                count += sum([1 if not r or not grid[pos[0]][pos[1]] else 0
                              for r, pos in zip(aux, idx)])
    return (count)
