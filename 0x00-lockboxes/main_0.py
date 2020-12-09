#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes), True)

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes), True)

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes), False)

boxes = [[1,3],[3,0,1],[2],[0]]
print(canUnlockAll(boxes), False)

boxes = [[4],[3],[],[2,5,7],[1],[],[8,9],[],[],[6]]
print(canUnlockAll(boxes), False)

boxes = [[1,3],[1,4],[2,3,2,4,1],[],[4,3,2]]
print(canUnlockAll(boxes), True)
