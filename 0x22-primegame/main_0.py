#!/usr/bin/python3

isWinner = __import__('0-prime_game').isWinner


print("Winner: {}".format(isWinner(5, [2, 5, 1, 4, 3])))
print('ben')
print('-------------------------')
print("Winner: {}".format(isWinner(3, [4, 5, 1])))
print('ben')
print('-------------------------')
print("Winner: {}".format(isWinner(10, [5, 5, 5, 5, 5, 2, 2, 2, 2, 2])))
print('maria')
print('-------------------------')
print("Winner: {}".format(isWinner(4, [11, 30, 1, 7])))
print('Ben')
print('-------------------------')
print("Winner: {}".format(isWinner(6, [1, 1, 0, 0, 1, 8])))
print('ben')
print('-------------------------')