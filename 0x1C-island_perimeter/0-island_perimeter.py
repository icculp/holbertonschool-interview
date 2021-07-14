#!/usr/bin/python3
"""
    0-island_perimeter
"""


def island_perimeter(grid):
    """ returns the perimeter of the island described in grid """
    perimeter = 0
    if grid is None or len(grid) == 0 or len(grid[0]) == 0:
        return perimeter
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if i == 0 and grid[i][j] == 1:
                perimeter += 1
            if j == 0 and grid[i][j] == 1:
                perimeter += 1
            if j == len(grid[0]) - 1 and grid[i][j] == 1:
                perimeter += 1
            if i == len(grid) - 1 and grid[i][j] == 1:
                perimeter += 1

            if i != len(grid) - 1 and grid[i][j] == 1 and grid[i + 1][j] == 0:
                perimeter += 1
            if i != 0 and grid[i][j] == 1 and grid[i - 1][j] == 0:
                perimeter += 1
            if j != len(grid[i]) - 1 and grid[i][j] == 1\
               and grid[i][j + 1] == 0:
                perimeter += 1
            if j != 0 and grid[i][j] == 1 and grid[i][j - 1] == 0:
                perimeter += 1
            if j == 100:
                break
        if i == 100:
            break
    return perimeter
