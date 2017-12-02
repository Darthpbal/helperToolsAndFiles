my_file = open("output.txt", "r+")




"""
You can open files in any of the following modes:

write-only mode ("w")
read-only mode ("r")
read and write mode ("r+")
append mode ("a"), which adds any new data you write to the file to the end of the file.
"""





my_list = [i ** 2 for i in range(1, 11)]

my_file = open("output.txt", "w")

# Add your code below!
for num in my_list:
  my_file.write(str(num) + "\n")
my_file.close()
