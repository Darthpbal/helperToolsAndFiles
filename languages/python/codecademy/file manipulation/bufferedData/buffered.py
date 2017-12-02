# We keep telling you that you always need to close your files after you're done writing to them. Here's why!
#
# During the I/O process, data is buffered: this means that it is held in a temporary location before being written to the file.
#
# Python doesn't flush the bufferthat is, write data to the fileuntil it's sure you're done writing. One way to do this is to close the file. If you write to a file without closing, the data won't make it to the target file.
# Instructions
# 1.
# Check out our extremely bad code in the editor. Click Runyou'll note that our read_file.read() didn't read any data back!
#
# Add a write_file.close() call after writing to the file but before reading it.
# Add a read_file.close() call after the print read_file.read() line
# Run the code again.
# This time, you'll see the data come through!




# Use a file handler to open a file for writing
write_file = open("text.txt", "w")

# Open the file for reading
read_file = open("text.txt", "r")

# Write to the file
write_file.write("Not closing files is VERY BAD.")

write_file.close()

# Try to read from the file
print read_file.read()
read_file.close()
