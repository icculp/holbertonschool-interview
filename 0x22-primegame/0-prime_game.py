#!/usr/bin/python3
"""
    Prime game
"""


def isWinner(x, nums):
    """
        where x is the number of rounds and nums is an array of n
        Return: name of the player that won the most rounds
    """
    # number of rounds
    if x > len(nums):
        return None
    players = {'Ben': 0, 'Maria': 0}
    for i in range(x):
        n = nums[i]
        if n == 1:
            players['Ben'] += 1
            continue
        round = set(j for j in range(2, n + 1))
        # print(round)
        # print(round[0])
        ro = 0
        # print('--while')
        while len(round) > 1:
            current_n = round.pop()
            # print('currentn', current_n)
            new_round = set()
            # ((print(j) and (j % current_n != 0)
            # and round.add(j)) for j in range(2, n + 1))
            for j in round:
                # print(j)
                if (j % current_n != 0):
                    new_round.add(j)
            # print(round)
            ro += 1
            round = new_round
        if ro % 2 == 0:
            players['Maria'] += 1
            # print('maria')
        else:
            players['Ben'] += 1
            # print('ben')
    if players['Ben'] > players['Maria']:
        return 'Ben'
    elif players['Ben'] < players['Maria']:
        return 'Maria'
    else:
        return None
