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
    d = 0
    while d < len(data):
        '''if data[d] >= 240 and data[d] <= 247:
            for i in range(1, 4):
                if not (data[d + i] >= 128 and data[d + i] <= 191):
                    return False
            d + i
        elif data[d] >= 224 and data[d] <= 239:
            for i in range(1, 3):
                if not (data[d + i] >= 128 and data[d + i] <= 191):
                    return False
            d + i
        elif data[d] >= 192 and data[d] <= 223:
            for i in range(1, 2):
                if not (data[d + i] >= 128 and data[d + i] <= 191):
                    return False
            d + i
        elif data[d] >= 0 and data[d] <= 127:
            pass'''
        if data[d] >= 0 and data[d] <= 244:
            pass
        else:
            return False
        d += 1
    return True
