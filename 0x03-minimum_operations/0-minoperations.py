#!/usr/bin/python3
"""
    Minimum operations of fib sequence
"""
import math


def minOperations(n):
    """ Min operations of fib (sum of previous 2) to add to n """
    try:
        s = math.sqrt(n)
        return math.ceil(s * 2)
    except Exception:
        return 0
