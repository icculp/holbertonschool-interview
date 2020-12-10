#!/usr/bin/python3
"""
    Task 0 Lockboxes
"""


def canUnlockAll(boxes):
    """ Determine if all the boxes can be opened """
    length = len(boxes)
    open = [0] * length

    def depth_first(i):
        """ recursive depth-first search """
        open[0] = 1
        for box in boxes[i]:
            if not open[box]:
                open[box] = 1
                depth_first(box)
        open[i] = 1
    depth_first(0)
    s = sum(open)
    if s == length:
        return True
    return False
