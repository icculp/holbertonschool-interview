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

    '''
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
                for ki in boxes[i]:
                    if i in boxes[ki]:
                        if i not in temp:
                            break
                if i in boxes[]:
                    continue
                for bo in boxes[j]:
                    temp2.add(bo)
            if i not in temp:
                print('false, i: {}'.format(i))
                if i in temp2:
                    print('true, i: {}'.format(i))
                    return True
                return False
            """if i in boxes[boxes[i].first]:
                return False"""
        return True
    else:
        return False
    '''
