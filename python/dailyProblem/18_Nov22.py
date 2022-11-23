#! /usr/bin/python 3
# dd_mmmyy.py - daily coding problem

import random

"""
You are presented with an 8 by 8 matrix representing the positions of pieces on a chess board. The only pieces on the board are the black king and various white pieces. Given this matrix, determine whether the king is in check.
"""

def solve(matrix: list) -> bool:
    """Solve problem"""
    check = False

    # find King
    for i in range(len(matrix)):
        for j in range(len(matrix)): 
            space = matrix[i][j]
            if space == 'K':
                print(f'Found King at ({i},{j})')

        
        def searchH(i, j, dir):
            """Search horizontally
            dir (str): r or l"""
            if dir == 'r':
                return (i, j + 1)
            else:
                return (i, j - 1)

        def searchV(i, j, dir):
            """Search vertically
            dir (str): u or d"""
            if dir == 'u':
                return (i, j + 1)
            else:
                return (i, j - 1)

        def searchD(dir):
            """Search diagonal
            dir(str): ur, ul, dr, dl
            """
            pass

        
    # search check paths, if eligible piece is in path, return True

    return check

sample_in = [
    ['.','.','.','K','.','.','.','.'],
    ['.','.','.','.','.','.','.','.'],
    ['.','B','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','P','.'],
    ['.','.','.','.','.','.','.','R'],
    ['.','.','N','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','Q','.','.'],
]
sample_out = True

sample_in2 = [
    ['.','.','.','K','.','.','.','.'],
    ['.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','.','P','.'],
    ['.','.','.','.','.','.','.','R'],
    ['.','.','N','.','.','.','.','.'],
    ['.','.','.','.','.','.','.','.'],
    ['.','.','.','.','.','Q','.','.'],
]
sample_out2 = False

# def test_solve1() -> None:
#     assert solve(sample_in) == sample_out
#     assert solve(sample_in2) == sample_out2

solution = solve(sample_in)
print(solution)