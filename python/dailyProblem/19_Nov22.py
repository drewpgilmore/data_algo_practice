#! /usr/bin/python3
# dd_mmmyy.py - daily coding problem

'''
You are given an string representing the initial conditions of some dominoes. Each element can take one of three values:

L, meaning the domino has just been pushed to the left,
R, meaning the domino has just been pushed to the right, or
., meaning the domino is standing still.
Determine the orientation of each tile when the dominoes stop falling. 
Note that if a domino receives a force from the left and right side simultaneously, it will remain upright.

For example, given the string .L.R....L, you should return LL.RRRLLL

Given the string ..R...L.L, you should return ..RR.LLLL
'''

def solve(doms: str) -> str:
    i = 1
    
    while i < len(doms) - 1:
        d = doms[i]
        leftD = doms[i - 1]
        rightD = doms[i + 1]
        if d == 'R':
            if rightD == '.':
                doms[i + 1] == 'R'
            i += 1
        elif d == 'L':
            j = i
            while (doms[j - 1] != 'R') and (j > 0): 
                doms[j - 1] == 'L'
                j -= 1      
            i += 1
        else:
            i += 1
            
    return doms


# def test_dominoes() -> None: 
#     sample_in = '..R...L.L'
#     sample_out = '..RR.LLLL'
#     assert solve(sample_in) == sample_out

#     sample_in2 = '.L.R....L'
#     sample_out2 = 'LL.RRRLLL'
#     assert solve(sample_in2) == sample_out2

sample_in = '..R...L.L'
sample_out = '..RR.LLLL'

solution = solve(sample_in)
print(solution)
