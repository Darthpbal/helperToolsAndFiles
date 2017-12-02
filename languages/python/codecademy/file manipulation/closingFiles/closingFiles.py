# Finally, we'll want a way to test whether a file we've opened is closed. Sometimes we'll have a lot of file objects open, and if we're not careful, they won't all be closed. How can we test this?

with open("text.txt", "w") as my_file:
  my_file.write("Hello World")

if not my_file.closed:
  my_file.close()

print my_file.closed
