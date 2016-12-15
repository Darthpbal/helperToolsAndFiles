#single line comment

"""
multi line comment
"""

# data is interpretted, so no data type declaraction is necessary
myInt = 5
myString = "uuuuuuhhhh"
myFloat = 3.14
myBool = True    #first letter caps needed
myOtherBool = False

print "somestring, no semicolons needed"
print "a four space indentation indicates scope rather than braces."


# very simple function definition
def myFunc(ur, nana):
    stuff = 5
    return stuff


# maths are all normal, but exponents are with a double star **
squared = 5 ** 2


# formatted printing
meal = 44.50
tax = 0.0675
tip = 0.15
meal = meal + meal * tax
total = meal+meal*tip
print("%.2f" % total)   # print float num 2 dec places deep


# string operations
# strings are zero indexed for accesing character by character


someString = raw_input("what should I store into a variable?")

print len(someString)
print someString.lower()
print someString.upper()
print someString.isalpha()
print "this function converts other data types into strings. " + str(myInt) + str(myFloat)


print "stuff and thaaangs are %s, %s" % (someString, myString)
print ("stuff and thaaangs are %s, %s" % someString, myString)







# date and time stuff
from datetime import datetime

now = datetime.now()
print now
print "%s/%s/%s, %s:%s:%s" % (now.month, now.day, now.year, now.hour, now.minute, now.second)







# conditionals and ifs elses, and functions
def clinic():
    print "You've just entered the clinic!"
    print "Do you take the door on the left or the right?"
    answer = raw_input("Type left or right and hit 'Enter'.").lower()
    if answer == "left" or answer == "l":
        print "This is the Verbal Abuse Room, you heap of parrot droppings!"
    elif answer == "right" or answer == "r":
        print "Of course this is the Argument Room, I've told you that already!"
    else:
        print "You didn't pick left or right! Try again."
        clinic()

clinic()


def tax(bill):
    """Adds 8% tax to a restaurant bill."""
    bill *= 1.08
    print "With tax: %f" % bill
    return bill

def tip(bill):
    """Adds 15% tip to a restaurant bill."""
    bill *= 1.15
    print "With tip: %f" % bill
    return bill

meal_cost = 100
meal_with_tax = tax(meal_cost)
meal_with_tip = tip(meal_with_tax)





# boolean operations
bool_one = False or not True and True
bool_two = False and not True or True
bool_three = True and not (False or False)
bool_four = not not True or False and not True
bool_five = False or not (True and True)





# string manipulation for pig latin
pyg = 'ay'

original = raw_input('Enter a word:')

if len(original) > 0 and original.isalpha():
    print original
    word = original.lower()
    first = word[0]
    new_word = word[1:len(word)] + first + pyg
    print new_word
else:
    print 'empty'







#functions calling functions
def cube(member):
    return member ** 3

def by_three(number):
    if((number % 3) == 0):
        return cube(number)
    else:
        return False

by_three(9)





# importing shit

import math
print sqrt(25)

from math import sqrt
from math import *

import math            # Imports the math module
everything = dir(math) # Sets everything to a list of things from math
print everything       # Prints 'em all!




#function argument tricks
def biggest_number(*args):
    print max(args)
    return max(args)

def smallest_number(*args):
    print min(args)
    return min(args)

def distance_from_zero(arg):
    print abs(arg)
    return abs(arg)


biggest_number(-10, -5, 5, 10)
smallest_number(-10, -5, 5, 10)
distance_from_zero(-10)





start_list = [5, 3, 1, 2, 4]
square_list = []

# Your code here!


print square_list



zoo_animals = ["pangolin", "cassowary", "sloth", "tiger"]
# Last night our zoo's sloth brutally attacked
#the poor tiger and ate it whole.

# The ferocious sloth has been replaced by a friendly hyena.
zoo_animals[2] = "hyena"

# What shall fill the void left by our dear departed tiger?
# Your code here!
zoo_animals[3] = "fuuuuuuuuuuuuuuuu"








suitcase = []
suitcase.append("sunglasses")

# Your code here!

suitcase.append("acid")
suitcase.append("case uh booze")
suitcase.append("ether")


list_length = len(suitcase) # Set this to the length of suitcase

print "There are %d items in the suitcase." % (list_length)
print suitcase





animals = "catdogfrog"
cat  = animals[:3]   # The first three characters of animals
dog  = animals[3:6]              # The fourth through sixth characters
frog =  animals[6:]             # From the seventh character to the end






animals = ["aardvark", "badger", "duck", "emu", "fennec fox"]
# duck_index =  animals.index("duck")  # Use index() to find "duck"

# Your code here!

# animals.insert(duck_index, "cobra")
animals.insert(animals.index("duck"), "cobra")
print animals # Observe what prints after the insert operation




start_list = [5, 3, 1, 2, 4]
square_list = []

# Your code here!
for num in start_list:
    square_list.append(num ** 2)

square_list.sort()
print square_list





# Assigning a dictionary with three key-value pairs to residents:
residents = {'Puffin' : 104, 'Sloth' : 105, 'Burmese Python' : 106}

print residents['Puffin'] # Prints Puffin's room number

# Your code here!
print residents["Sloth"]
print residents["Burmese Python"]







menu = {} # Empty dictionary
menu['Chicken Alfredo'] = 14.50 # Adding new key-value pair
print menu['Chicken Alfredo']

# Your code here: Add some dish-price pairs to menu!
menu["chicken nuggets"] = 4.20
menu["eatadick.com.org"] = 42.00
menu["blahblahblahblahblahblah"] = 4.00



print "There are " + str(len(menu)) + " items on the menu."
print menu














# key - animal_name : value - location
zoo_animals = { 'Unicorn' : 'Cotton Candy House',
'Sloth' : 'Rainforest Exhibit',
'Bengal Tiger' : 'Jungle House',
'Atlantic Puffin' : 'Arctic Exhibit',
'Rockhopper Penguin' : 'Arctic Exhibit'}
# A dictionary (or list) declaration may break across multiple lines

# Removing the 'Unicorn' entry. (Unicorns are incredibly expensive.)
del zoo_animals['Unicorn']

# Your code here!

del zoo_animals['Sloth']
del zoo_animals['Bengal Tiger']
zoo_animals['Rockhopper Penguin'] = "something else"


print zoo_animals









backpack = ['xylophone', 'dagger', 'tent', 'bread loaf']
backpack.remove("dagger")









inventory = {
    'gold' : 500,
    'pouch' : ['flint', 'twine', 'gemstone'], # Assigned a new list to 'pouch' key
    'backpack' : ['xylophone','dagger', 'bedroll','bread loaf']
}
# Adding a key 'burlap bag' and assigning a list to it
inventory['burlap bag'] = ['apple', 'small ruby', 'three-toed sloth']
# Sorting the list found under the key 'pouch'
inventory['pouch'].sort()
# Your code here
inventory["pocket"] = ['seashell', 'strange berry', 'lint']
inventory['backpack'].sort()
inventory['backpack'].remove('dagger')
inventory['gold'] = inventory['gold'] + 50









webster = {
	"Aardvark" : "A star of a popular children's cartoon show.",
    "Baa" : "The sound a goat makes.",
    "Carpet": "Goes on the floor.",
    "Dab": "A small amount."
}

# Add your code below!
for word in webster:
    print webster[word]









def fizz_count(x):
    count = 0
    for item in x:
        if(item == "fizz"):
            count += 1

    return count


print fizz_count(["fizz","cat","fizz"])














prices = {
    "banana": 4,
    "apple": 2,
    "orange": 1.5,
    "pear": 3
}

stock = {
    "banana": 6,
    "apple": 0,
    "orange": 32,
    "pear": 15
}


for key in prices:
    print key
    print "price: %s" % prices[key]
    print "stock: %s\n" % stock[key]
s












# lists and ranges and stuff

def my_function(x):
    for i in range(0, len(x)):
        x[i] = x[i] * 2
    return x

print my_function(range(3)) # Add your range between the parentheses!
# range(stop)
# range(start, stop)
# range(start, stop, step)








n = [[1, 2, 3], [4, 5, 6, 7, 8, 9]]
# Add your function here
def flatten(lists):
    results = []
    for numbers in lists:
        for number in numbers:
            results.append(number)
    return results
print flatten(n)































from random import randint
board = []
for x in range(5):
    board.append(["O"] * 5)
def print_board(board):
    for row in board:
        print " ".join(row)
print "Let's play Battleship!"
print_board(board)
def random_row(board):
    return randint(0, len(board) - 1)
def random_col(board):
    return randint(0, len(board[0]) - 1)
ship_row = random_row(board)
ship_col = random_col(board)
print ship_row
print ship_col
for turn in range(4):
    print "Turn", turn + 1
    guess_row = int(raw_input("Guess Row:"))
    guess_col = int(raw_input("Guess Col:"))
    if guess_row == ship_row and guess_col == ship_col:
        print "Congratulations! You sunk my battleship!"
        break
    else:
        if (guess_row < 0 or guess_row > 4) or (guess_col < 0 or guess_col > 4):
            print "Oops, that's not even in the ocean."
        elif(board[guess_row][guess_col] == "X"):
            print "You guessed that one already."
        else:
            print "You missed my battleship!"
            board[guess_row][guess_col] = "X"
        if(turn == 3):
            print "Game Over"
        print_board(board)
# You can also add on to your Battleship! program to make it more complex and fun to play. Here are some ideas for enhancements—maybe you can think of some more!
# Make multiple battleships: you'll need to be careful because you need to make sure that you don’t place battleships on top of each other on the game board. You'll also want to make sure that you balance the size of the board with the number of ships so the game is still challenging and fun to play.
# Make battleships of different sizes: this is trickier than it sounds. All the parts of the battleship need to be vertically or horizontally touching and you’ll need to make sure you don’t accidentally place part of a ship off the side of the board.
# Make your game a two-player game.
# Use functions to allow your game to have more features like rematches, statistics and more!
# Some of these options will be easier after we cover loops in the next lesson. Think about coming back to Battleship! after a few more lessons and see what other changes you can make

































import random

print "Lucky Numbers! 3 numbers will be generated."
print "If one of them is a '5', you lose!"

count = 0
while count < 3:
    num = random.randint(1, 6)
    print num
    if num == 5:
        print "Sorry, you lose!"
        break
    count += 1
else:
    print "You win!"





























from random import randint

# Generates a number from 1 through 10 inclusive
random_number = randint(1, 10)
print random_number
guesses_left = 3
# Start your game!
while guesses_left > 0:
    guess = int(raw_input("Your guess:"))
    if(guess == random_number):
        print("You win!")
        break
    guesses_left -= 1
else:
    print("You lose.")





























print "Counting..."

for i in range(20):
    print i





























hobbies = []

# Add your code below!
for rep in range(3):
    # hobby = raw_input("Whats a hobby?")
    # hobbies.append(hobby)
    hobbies.append(raw_input("Whats a hobby?"))


print hobbies
for hobby in hobbies:
    print hobby


































phrase = "A bird in the hand..."

# Add your for loop
for char in phrase:
    if(char == "A") or (char == "a"):
        print "X",
    else:
        print char,




#Don't delete this print statement!
print
