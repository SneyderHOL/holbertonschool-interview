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
    for byte in data:
        if (not init) and bytes_left == 0:
            init = True
        num_bytes = 0
        str_byte = format(byte, '#010b')[-8:]
        match = re.match(regex, str_byte)
        if match:
            num_bytes = len(match.group())
        if num_bytes > 4:
            return False
        if init:
            bytes_left = num_bytes
        if init and bytes_left == 0:
            continue
        if (init and bytes_left == 1) or (not init) and num_bytes != 1:
            return False
        init = False
        bytes_left -= 1
    else:
        if bytes_left != 0:
            return False
    return True
