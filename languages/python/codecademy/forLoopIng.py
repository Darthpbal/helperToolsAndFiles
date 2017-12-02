thing = "spam!"

for c in thing:
  print c

word = "eggs!"

# Your code here!
for i in range(len(word)):
  print word[i]

for letter in word:
  print letter







phrase = "A bird in the hand..."

# Add your for loop
for char in phrase:
  if char == "a" or char == "A":
    print "X",
  else:
    print char,




#Don't delete this print statement!
print













d = {'a': 'apple', 'b': 'berry', 'c': 'cherry'}

for key in d:
  # Your code here!
  print key + " " + d[key]








choices = ['pizza', 'pasta', 'salad', 'nachos']

print 'Your choices are:'
for index, item in enumerate(choices):
  print index + 1, item











list_a = [3, 9, 17, 15, 19]
list_b = [2, 4, 8, 10, 30, 40, 50, 60, 70, 80, 90]

for a, b in zip(list_a, list_b):
  # Add your code here!
  if a > b:
    print a
  elif b > a:
    print b
  else:
    print "err"









fruits = ['banana', 'apple', 'orange', 'tomato', 'pear', 'grape']

print 'You have...'
for f in fruits:
  if f == 'tomato':
    print 'A tomato is not a fruit!' # (It actually is.)
    break
  print 'A', f
else:
  print 'A fine selection of fruits!'








fruits = ['banana', 'apple', 'orange', 'tomato', 'pear', 'grape']

print 'You have...'
for f in fruits:
  print 'A', f
else:
  print 'A fine selection of fruits!'







for i in range(420):
  print i+1,
else:
  print
