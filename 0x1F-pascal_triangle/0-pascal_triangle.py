#!/usr/bin/python3
"""  Module for function pascal_triangle  """


def pascal_triangle(n):
    """pascal_triangle: function that returns a list of integers representing
        the Pascal's triangle of n
    """
    if n <= 0:
        return []
    i = 1
    triangle = [[1]]
    while i < n:
        row = i
        col = 0
        aux = []
        while col <= i:
            value = 0
            sub = 1
            while sub >= 0:
                x, y = row - 1, col - sub
                if y < 0 or y >= i:
                    value += 0
                else:
                    value += triangle[x][y]
                sub -= 1
            aux.append(value)
            col += 1
        triangle.append(aux)
        i += 1
    return triangle
