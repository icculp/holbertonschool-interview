#!/usr/bin/python3
"""
    Task 0 Lockboxes
"""


def canUnlockAll(boxes):
    """ Determine if all the boxes can be opened """
    b = set()
    if type(boxes) is not list:
        return False
    for box in boxes:
        for bo in box:
            b.add(bo)
    c = [i for i in range(1, len(boxes))]
    c = set(c)
    d = c.issubset(b)
    if d:
        for i in range(1, len(boxes)):
            temp = set()
            temp2 = set()
            for j in range(len(boxes)):
                if i == j:
                    continue
                for bo in boxes[j]:
                    temp.add(bo)
                if j in boxes[i]:
                    continue
                for bo in boxes[j]:
                    temp2.add(bo)
            if i not in temp2 or i not in temp:
                return False
            '''if i in boxes[boxes[i].first]:
                return False'''
        return True
    else:
        return False
