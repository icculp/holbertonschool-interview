#!/usr/bin/python3
"""
    Utf-8 - 8 least significant bit encoding
"""


def validUTF8(data):
    """ Parses data in list for valid 1 byte utf8 encoding
        True if valid else False
    """
    '''last_byte_mask = 255'''
    '''data = [257, 525, 410]'''
    '''last_bytes = [d & last_byte_mask for d in data]'''
    '''print(last_bytes)'''
    '''if (type(data) is not list or
        not all(isinstance(d, int) for d in data) or
            not all(d >= 0 and d <= 192
                    for d in last_bytes)):
        return False'''
    if (type(data) is not list or
        not all(isinstance(d, int) for d in data)):
        return False
    if not all((d >= 0 and d <= 127) or
                (d >= 194 and d <= 244)
                for d in data):
        return False
    else:
        return True
