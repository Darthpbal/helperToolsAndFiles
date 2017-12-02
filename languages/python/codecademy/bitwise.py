print 5 >> 4  # Right Shift
print 5 << 1  # Left Shift
print 8 & 5   # Bitwise AND
print 9 | 4   # Bitwise OR
print 12 ^ 42 # Bitwise XOR
print ~88     # Bitwise NOT









print 0b1,    #1
print 0b10,   #2
print 0b11,   #3
print 0b100,  #4
print 0b101,  #5
print 0b110,  #6
print 0b111   #7
print "******"
print 0b1 + 0b11
print 0b11 * 0b11







one = 0b1
two = 0b10
three = 0b11
four = 0b100
five = 0b101
six = 0b110
seven = 0b111
eight = 0b1000
nine = 0b1001
ten = 0b1010
eleven = 0b1011
twelve = 0b1100






for x in range(1, 6):
  print bin(x)












print int("1",2)
print int("10",2)
print int("111",2)
print int("0b100",2)
print int(bin(5),2)
# Print out the decimal equivalent of the binary 11001001.
print int("0b11001001", 2)











shift_right = 0b1100 >> 2
shift_left = 0b1 << 2

# Your code here!


print bin(shift_right)
print bin(shift_left)









print bin(0b1110 & 0b101)
print bin(0b1110 | 0b101)




print bin(0b1110 ^ 0b101)





print ~1
print ~2
print ~3
print ~42
print ~123






num  = 0b1100
mask = 0b0100
desired = num & mask
if desired > 0:
  print "Bit was on"






def check_bit4(input):
    if input & 0b1000 > 0 :
        return "on"
    else:
        return "off"



a = 0b10111011
print bin(a | 0b100)
a = 0b11101110
print bin(a ^ 0b1111111)







def flip_bit(number, n):
    mask = 0b1 << n - 1
    result = number ^ mask
    return bin(result)
