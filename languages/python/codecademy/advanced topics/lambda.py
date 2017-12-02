my_list = range(16)
filter(lambda x: x % 3 == 0, my_list)









languages = ["HTML", "JavaScript", "Python", "Ruby"]

# Add arguments to the filter()
print filter(lambda x: x == "Python", languages)










squares = [x ** 2 for x in range(1, 11)]


print filter(lambda x: x >= 30 and x <= 70, squares)















movies = {
  "Monty Python and the Holy Grail": "Great",
  "Monty Python's Life of Brian": "Good",
  "Monty Python's Meaning of Life": "Okay"
}


print movies.items()








threes_and_fives = [x for x in range(1, 16) if x % 3 == 0 or x % 5 == 0]

print threes_and_fives








garbled = "!XeXgXaXsXsXeXmX XtXeXrXcXeXsX XeXhXtX XmXaX XI"


message =  garbled[::-2]

print message










garbled = "IXXX aXXmX aXXXnXoXXXXXtXhXeXXXXrX sXXXXeXcXXXrXeXt mXXeXsXXXsXaXXXXXXgXeX!XX"


message =  filter(lambda x: x != "X", garbled)

print message
