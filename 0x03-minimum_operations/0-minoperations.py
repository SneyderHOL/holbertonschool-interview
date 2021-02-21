#!/usr/bin/python3
"""
minOperations module
"""


def minOperations(n):
    """Given a number n, minOperationsis a method that calculates the fewest
       number of operations needed to result in exactly n H characters in
       the file."""
    aux = 2
    num_op = 0
    if (n <= 1):
        return num_op
    while aux <= n:
        if n % aux == 0:
            num_op += aux
            n = n // aux
            aux -= 1
        aux += 1
    return num_op
