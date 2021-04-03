#!/usr/bin/python3
"""
validate utf8 module
"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    for element in data:
        last_byte = format(element, '#010b')[-8:]
        if not (last_byte.startswith('10') or last_byte.startswith('0')):
            return False
    return True
