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
    if len(walls) < 3:
        return 0
    i = j = c = z = 0
    while 1:
        z = 0
        if walls[i] != 0:
            a = walls[i]
            j = i + 1
            while walls[j] == 0:
                z += 1
                j += 1
                if j >= len(walls):
                    return c
            i = j
            c += z * min(walls[i], walls[j])
        i += 1
        if i >= len(walls):
            return c
    ''' didn't work
    w = set([x for x in walls if x != 0])
    m = min(w)
    z = walls[1:-1].count(0)
    c = m * z
    '''
    ''' 3 missing checks
    w = set([x for x in walls if x != 0])
    while len(w) > 1:
        c += max(w) - min(w)
        w.remove(min(w))
    '''
    ''' 4 missing checks
    w = [x for x in walls if x != 0]
    for x in range(len(w) - 1):
        c += min(w[x], w[x + 1])
    '''
    return c
