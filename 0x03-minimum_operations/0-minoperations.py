#!/usr/bin/python3
"""
    Minimum operations of fib sequence
"""
import math


def minOperations(n):
    """ Min operations of fib (sum of previous 2) to add to n """
    if n == 0 or n == 1:
        return 0
    if n < 5 and n > 1:
        return n
    try:
        s = math.sqrt(n)
        return math.ceil(s * 2)
    except Exception:
        return 0
