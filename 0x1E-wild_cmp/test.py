#!/usr/bin/env bash
def printA(n):
    best = [0, 1, 2, 3, 4, 5, 6, 9, 12,
            16, 20, 27, 36, 48, 64, 81]
    q = int((n - 11) / 5) if n > 15 else 0
    return best[n - 5*q] * 4**q

for i in  [27, 36, 48, 64, 81]:
    print(printA(i))
