l = [i ** 2 for i in range(1, 11)]
# Should be [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
# [start:end:stride]
print l[2:9:2]






my_list = range(1, 11) # List of numbers 1 - 10
#Use list slicing to print out every odd element of my_list from start to finish.

#Omit the start and end index. You only need to specify a stride.
# Add your code below!
print my_list[::2]



my_list = range(1, 11)
"""
Create a variable called backwards and set it equal to the reversed version of my_list.

Make sure to reverse the list in the editor by passing your list slice a negative stride, like in the example above.
"""
# Add your code below!
backwards = my_list[::-1]



to_one_hundred = range(101)
# Add your code below!
"""
Create a variable, backwards_by_tens, and set it equal to the result of going backwards through to_one_hundred by tens. Go ahead and print backwards_by_tens to the console.
"""
backwards_by_tens = to_one_hundred[::-10]

print backwards_by_tens






"""
Anonymous Functions
One of the more powerful aspects of Python is that it allows for a style of programming called functional programming, which means that you're allowed to pass functions around just as if they were variables or values. Sometimes we take this for granted, but not all languages allow this!

Check out the code at the right. See the lambda bit? Typing

lambda x: x % 3 == 0
Is the same as

def by_three(x):
  return x % 3 == 0
Only we don't need to actually give the function a name; it does its work and returns a value without one. That's why the function the lambda creates is an anonymous function.

When we pass the lambda to filter, filter uses the lambda to determine what to filter, and the second argument (my_list, which is just the numbers 0 – 15) is the list it does the filtering on.
"""
my_list = range(16)
print filter(lambda x: x % 3 == 0, my_list)
