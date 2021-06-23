#!/usr/bin/python3
"""
    Making Change
"""


def makeChange(coins, total):
    """ dtermines fewest # of coins needed """
    if total <= 0:
        return 0
    if len(coins) < 1:
        return -1
    n = 0
    coins.sort(reverse=True)
    # print(coins)
    # print(total)
    for coin in coins:
        while coin <= total and\
                total - coin >= 0:
            total -= coin
            # print(total, n+1)
            n += 1
    if total != 0:
        return -1
    return n
