#!/usr/bin/python3
"""
    Utf-8 - 8 least significant bit encoding
"""


def validUTF8(data):
    """ Parses data in list for valid 1 byte utf8 encoding
        True if valid else False
    """
    if (type(data) is not list or
        not all(isinstance(d, int) for d in data) or
            not all(d >= 1 and d <= 127 for d in data)):
        return False
    else:
        return True
