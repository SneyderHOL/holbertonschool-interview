#!/usr/bin/python3
"""
minOperations module
"""


def copy_all(string, ret=False):
    """Method to copy a string"""
    if ret:
        aux = copy_all.counter
        copy_all.counter = 0
        return aux
    copy_all.counter += 1
    # print(copy_all.counter)
    return string + ''

copy_all.counter = 0


def paste(string, cp_string, ret=False):
    """Method to concatenate the same strings"""
    if ret:
        aux = paste.counter
        paste.counter = 0
        return aux
    paste.counter += 1
    # print(paste.counter)
    return string + cp_string

paste.counter = 0


def reset_counters(c=0, p=0):
    """Method to reset the counters method"""
    paste.counter = p
    copy_all.counter = c


def execution(char, n, limit, min_op):
    """Method that iterate to find the minimum opeations quantity"""
    copy = copy_all(char)
    for i in range(1, limit):
        char = paste(char, copy)
    copy = copy_all(char)
    while len(char) < n:
        char = paste(char, copy)
    if len(char) == n:
        return copy_all('', True) + paste('', '', True)
    return min_op


def minOperations(n):
    """Given a number n, minOperationsis a method that calculates the fewest
       number of operations needed to result in exactly n H characters in
       the file."""
    if (n <= 1):
        return 0
    char = 'H'
    min_op = n
    top_limit = n // 2
    bottom_limit = len(char)
    aux = bottom_limit
    limit = 2
    while (limit <= top_limit):
        operations = execution(char, n, limit, min_op)
        reset_counters()
        if operations < min_op:
            min_op = operations
        limit += 1
    reset_counters()
    return min_op
