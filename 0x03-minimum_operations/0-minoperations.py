#!/usr/bin/python3
"""
    Minimum operations of fib sequence
"""


def minOperations(n):
    ''' Min operations of fib (sum of previous 2) to add to n '''
    if n == 0 or n == 1:
        return 0
    '''if n < 5 and n > 1:
        return n'''
    try:
        '''s = math.sqrt(n)
        return int(s * 2) + 1'''
        count = 0
        while n % 2 == 0:
            count += 2
            n /= 2
        i = 3
        while i <= n:
            if n % i == 0:
                count += i
                n /= i
            i += 2
        return count
    except Exception as e:
        return 0
