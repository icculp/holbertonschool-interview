#!/usr/bin/python3
"""
    0-pascal_triangle.py
"""


def pascal_triangle(n):
    """  returns a list of lists of integers representing
            the Pascal’s triangle of n
    """
    ''' lame method '''
    triangle = []
    for i in range(1, n + 1):
        C = 1
        row = []
        for j in range(1, i + 1):
            row.append(C)
            C = C * (i - j) // j
        triangle.append(row)
    return triangle


''' cool method
if n <= 0:
    return []
triangle = []
for i in range(n):
    triangle.append([int(x) for x in str(11 ** i)])
return triangle'''
