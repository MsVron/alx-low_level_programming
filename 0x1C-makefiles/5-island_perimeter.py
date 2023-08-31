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

    # Helper function to determine if a cell is within grid bounds
    # and if it's water


    def is_out_of_bounds_or_water(row, col):
        if row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0]):
            return True
        return grid[row][col] == 0

    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                # Check each of the four sides
                # top


                perimeter += is_out_of_bounds_or_water(i-1, j)

                # bottom


                perimeter += is_out_of_bounds_or_water(i+1, j)

                # left


                perimeter += is_out_of_bounds_or_water(i, j-1)

                # right


                perimeter += is_out_of_bounds_or_water(i, j+1)

    return perimeter

#This solution iterates over the grid once, with a constant
# amount of work done for each cell, so the time complexity is
# O(m×n) where m and n are the dimensions of the grid.