suitcase = ["sunglasses", "hat", "passport", "laptop", "suit", "shoes"]

# The first and second items (index zero and one)
first = suitcase[0:2]

# Third and fourth items (index two and three)
middle =  suitcase[2:4]

# The last two items (index four and five)
last =  suitcase[4:6]

print first
print middle
print last



animals = "catdogfrog"

# The first three characters of animals
cat = animals[:3]

# The fourth through sixth characters
dog = animals[3:6]

# From the seventh character to the end
frog = animals[6:]




animals = ["aardvark", "badger", "duck", "emu", "fennec fox"]
duck_index = animals.index("duck")# Use index() to find "duck"

# Your code here!
animals.insert(duck_index, "cobra")

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
menu["Pineapple"] = 4.20
menu["Apple Pen"] = 3.14
menu["sgbk"] = 4.20



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
del zoo_animals["Sloth"]
del zoo_animals["Bengal Tiger"]
zoo_animals["Rockhopper Penguin"] = "Your nana's house"



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
inventory["pocket"] = ["seashell", "strange berry", "lint"]

inventory["backpack"].sort()
inventory["backpack"].remove("dagger")
inventory["gold"] += 50







webster = {
  "Aardvark" : "A star of a popular children's cartoon show.",
  "Baa" : "The sound a goat makes.",
  "Carpet": "Goes on the floor.",
  "Dab": "A small amount."
}

# Add your code below!
for word in webster:
  print webster[word]




def my_function(x):
  for i in range(0, len(x)):
    x[i] = x[i] * 2
  return x

print my_function(range(3)) # Add your range between the parentheses!





#Sort dictionary by values
mydict = {'carl':40,
          'alan':2,
          'bob':1,
          'danny':3}
for key, value in sorted(mydict.iteritems(), key=lambda (j,f): (f,j)):
    print "%s: %s" % (key, value)
