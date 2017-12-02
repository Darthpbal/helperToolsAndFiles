my_dict = {
  "name": "Wakawaka",
  "age": 26,
  "major": "Astrophysics",
  "eyeColor": "brown",
  "hairColor": "brown",
  "song": {"title": "Madness", "artist": "Muse"}
  ""
}


print my_dict.items()

print my_dict.keys()

print my_dict.values()



for key in my_dict:
    print key, my_dict[key]




####    Advanced list building

"""
Let's say you wanted to build a list of the numbers from 0 to 50 (inclusive). We could do this pretty easily:

my_list = range(51)
But what if we wanted to generate a list according to some logic—for example, a list of all the even numbers from 0 to 50?

Python's answer to this is the list comprehension. List comprehensions are a powerful way to generate lists using the for/in and if keywords we've learned.

"""

evens_to_50 = [i for i in range(51) if i % 2 == 0]
print evens_to_50





doubles_by_3 = [x * 2 for x in range(1, 6) if (x * 2) % 3 == 0]
"""
Use a list comprehension to build a list called even_squares in the editor.
Your even_squares list should include the squares of the even numbers between 1 to 11. Your list should start [4, 16, 36...] and go from there
"""
# Complete the following line. Use the line above for help.
even_squares = [x ** 2 for x in range(1, 11) if x % 2 == 0 ]

print even_squares








#The comprehension should consist of the cubes of the numbers 1 through 10 only if the cube is evenly divisible by four.

cubes_by_four = [ x ** 3 for x in range(1, 11) if ((x ** 3) % 4 == 0) ]

print cubes_by_four
