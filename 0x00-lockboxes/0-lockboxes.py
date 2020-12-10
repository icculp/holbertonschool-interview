#!/usr/bin/python3
"""
    Task 0 Lockboxes
"""


def canUnlockAll(boxes):
    """ Determine if all the boxes can be opened """
    if type(boxes) is not list or len(boxes) == 0:
        return False
    if len(boxes) == 1:
        return True
    '''
    l = len(boxes)
    t = 1
    keys = [0]
    for key in keys:
        for n in boxes[key]:
            if n not in keys:
                if n != key and n < l:
                    t += 1
                    keys.append(n)
    if t == l:
        return True
    return False
    '''
    length = len(boxes)
    open = [0 for i in range(length)]
    open[0] = 1
    s = [0]
    while s:
        n = s.pop()
        for i in boxes[n]:
            if not open[i]:
                open[i] = 1
                s.append(i)
    os = sum(open)
    return True if os == length else False
