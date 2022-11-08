word = 'frost'
guesses = 5

for i in range(5): # 5 guesses
    guess = input("Guess: ")
    if len(guess) != 5:
        guess = input('Invalid guess, try again: ')
    
    if guess == word: 
        print('Good job!')
    
    output = ''
    for i in range(guesses):
        if guess[i] == word[i]:
            output += guess[i]
        else:
            output += '_'

    print(output)     

print('Sorry, better luck next time')  
