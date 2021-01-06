#!/usr/bin/python3
"""
    Minimum operations of fib sequence
"""


def minOperations(n):
    ''' Min operations of fib (sum of previous 2) to add to n '''
    if n == 0 or n == 1 or type(n) is not int:
        return 0
    if n < 6 and n > 1:
        return n
    '''s = math.sqrt(n)
    return int(s * 2) + 1'''
    count = 0
    while n % 2 == 0:
        count += 2
        n /= 2
    i = 3
    while i <= n:
        while n % i == 0:
            count += i
            n /= i
        i += 1
    return count
