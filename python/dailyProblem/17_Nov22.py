#! /usr/bin/python 3
# yyyy_mm_dd.py - daily coding problem

import random
import enchant

"""
A step word is formed by taking a given word, adding a letter, and anagramming the result. 
For example, starting with the word "APPLE", you can add an "A" and anagram to get "APPEAL".

Given a dictionary of words and an input word, create a function that returns all valid step words.
"""

def solve(words: dict) -> list:
    stepWords = []
    # find all possible letter combinations and determin if they're real words
    # find all combinations
    possibleWords = []
    
    # determine if real, append 

    return stepWords

sample_in = {'word': 'apple', 'input': 'a'}
sample_out = ['appeal']

def test_solve1() -> None:
    solution = solve(sample_in)
    assert solution == sample_out

def test_solve2() -> None:
    solution = solve({'word': 'ear', 'input': 't'})
    assert solution == ['erat', 'rate', 'tare', 'tear']

def test_solve3() -> None:
    solution = solve({'word': 'dig', 'input': 'z'}})
    assert solution == []