#!/usr/bin/python3
import re
"""
validate utf8 module
"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    regex = '^(1)+'
    num_bytes = 0
    bytes_left = 0
    init = True
    for element in data:
        last_byte = format(element, '#010b')[-8:]
        if not (last_byte.startswith('10') or last_byte.startswith('0')):
            return False
    return True
