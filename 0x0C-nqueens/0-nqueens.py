#!/usr/bin/env python3
"""
    N queens puzzle
"""
import sys


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
N = sys.argv[1]
if not N.isdigit():
    print("N must be a number")
    exit(1)
N = int(N)
if N < 4:
    print("N must be at least 4")
    exit(1)


def solution(n):
    '''
        N Queens solver
    '''
    sol = [[i] for i in range(n)]
    for i in range(1, n):
        new_sol = []
        for x in sol:
            idx = [j for j in range(n) if j not in x]
            for k in range(len(x)):
                a, b = x[k] - i + k, x[k] + i - k
                if a in idx:
                    idx.remove(a)
                if b in idx:
                    idx.remove(b)
                if idx == []:
                    break
            new_sol.extend([x + [j] for j in idx])
        sol = new_sol
    for s in range(len(sol)):
        for i in range(n):
            sol[s][i] = [i, sol[s][i]]
    return sol


if __name__ == '__main__':
    for sol in solution(N):
        print(sol)
