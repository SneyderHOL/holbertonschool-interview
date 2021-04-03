#!/usr/bin/python3
import re
"""
validate utf8 module
"""


def is_valid_integer(num):
    """checks if the integer is 1 byte long"""
    if num > 255 or num < 0:
        return False
    return True


def valid_init_character_byte(num):
    """checks if the number is a valid initial character byte"""
    regex = re.compile('^(1)+')
    str_byte = format(num, '#010b')[-8:]
    match = regex.match(str_byte)
    switcher = {
        '11': 2,
        '111': 3,
        '1111': 4
    }
    if match:
        return switcher.get(match, 1)
    return False


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    num_bytes = 0
    bytes_left = 0
    init = True
    for byte in data:
        if (not init) and bytes_left == 0:
            init = True
        if not is_valid_integer(byte):
            return False
        num_bytes = valid_init_character_byte(byte)
        if num_bytes is False or (init and num_bytes == 0):
            return False
        if init:
            bytes_left = num_bytes
        else:
            if num_bytes != 0:
                return False
        init = False
        bytes_left -= 1
    if bytes_left != 0:
        return False
    return True
