#!/usr/bin/python3

"""
This module contains a function that calculates the perimeter of an island
represented by a 2D grid.
"""

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    :param list[list[int]] grid: A rectangular 2D list where:
        - 0 represents a water zone
        - 1 represents a land zone
    :return: Perimeter of the island.
    :rtype: int
    """

    # Helper function to determine if a cell is within grid bounds and if it's water
    def is_out_of_bounds_or_water(row, col):
        if row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0]):
            return True
        return grid[row][col] == 0

    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                # Check each of the four sides
                perimeter += is_out_of_bounds_or_water(i-1, j) # top
                perimeter += is_out_of_bounds_or_water(i+1, j) # bottom
                perimeter += is_out_of_bounds_or_water(i, j-1) # left
                perimeter += is_out_of_bounds_or_water(i, j+1) # right

    return perimeter