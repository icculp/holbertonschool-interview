#!/usr/bin/python3
"""
    Rain Interview task
"""


def rain(walls):
    """ Given a list of non-negative integers representing walls of
            width 1, calculate how much water will be retained
            after it rains
        walls is a list of non-negative integers
        Returns: integer indicating total retained rainwater,
            or 0 if list is empty
    """
    if len(walls) < 2:
        return 0
    w = set([x for x in walls if x != 0])
    c = 0
    while len(w) > 1:
        c += max(w) - min(w)
        w.remove(min(w))
    #for x in range(len(w) - 1):
    #    c += min(w[x], w[x + 1])
    return c
