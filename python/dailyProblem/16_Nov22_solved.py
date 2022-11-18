#! /usr/bin/python 3
# dd_mmmyy.py - daily coding problem

import random

"""
MegaCorp wants to give bonuses to its employees based on how many lines of codes they have written. 
They would like to give the smallest positive amount to each worker consistent with the constraint 
that if a developer has written more lines of code than their neighbor, they should receive more money.

Given an array representing a line of seats of employees at MegaCorp, 
determine how much each one should get paid.

For example, given [10, 40, 200, 1000, 60, 30], you should return [1, 2, 3, 4, 2, 1].
"""

def solve(li: list[int]) -> list[int]:
    """Solve problem"""
    minRaise = 1
    raises = [1 for l in li]
    for i in range(1, len(li) - 1):
        codeLines = li[i]
        leftN = li[i - 1]
        rightN = li[i + 1]
        if codeLines > leftN:
            raises[i] = raises[i - 1] + 1
        elif codeLines > rightN:
            raises[i] = raises[i + 1] + 1
            j = i
            while j > 0:
                if li[j] < li[j - 1] and raises[j] == raises[j - 1]:
                    raises[j - 1] = raises[j] + 1
                j -= 1
        else:
            raises[i + 1] = raises[i] + 1

        print(raises)

    return raises

sample_in = [10, 40, 200, 1000, 60, 30]
sample_out = [1, 2, 3, 4, 2, 1]

def test_solve1() -> None:
    solution = solve(sample_in)
    assert solution == sample_out

def test_solve2() -> None:
    solution = solve([10, 20, 30, 10, 30, 20, 30, 40, 10])
    assert solution == [1, 2, 3, 1, 2, 1, 2, 3, 1]

def test_solve3() -> None:
    solution = solve([100, 3, 14, 12, 77, 8, 0, 1])
    assert solution == [2, 1, 2, 1, 3, 2, 1 , 2]

# Big O thoughts: 
# Best case: O(n) if list grows incrementally
# Worst case: 