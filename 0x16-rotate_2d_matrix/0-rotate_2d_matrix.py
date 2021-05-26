#!/usr/bin/env python3
"""
    Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """ rotates a 2d matrix in place """
    # matrix = list(zip(*matrix[::-1]))
    N = len(matrix)
    for x in range(0, int(N / 2)):
        for y in range(x, N - 1 - x):
            temp = matrix[y][x]
            matrix[y][x] = matrix[N - 1 - x][y]
            matrix[N - 1 - x][y] = matrix[N - 1 - y][N - 1 - x]
            matrix[N - 1 - y][N - 1 - x] = matrix[x][N - 1 - y]
            matrix[x][N - 1 - y] = temp
