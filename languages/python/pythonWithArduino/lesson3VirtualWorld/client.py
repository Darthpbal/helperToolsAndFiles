"""
This was a little bit of a pain because the whitespace characters were screwing with my float conversion.
"""

import serial
from visual import *

arduinoSerialData = serial.Serial("/dev/ttyUSB0", 9600)


measuringRod = cylinder(length = 6, color = color.yellow, radius=0.5, pos = (-3, 0, 0) )


loopTimes = 0
rollingAverage = 0.0
while loopTimes < 50:
    rate(20)
    if arduinoSerialData.inWaiting() > 0:
        data = arduinoSerialData.readline()

        data = data.strip()

        if data.isalnum() == True and data.isspace() == False:
            print "Data cleaned :",
            strippedData = data.strip()
            data = int(data)
            print int(data) == 12
            print data
            if data > 0:
                measuringRod.length = data
            if data == 12:
                print "zero"
                measuringRod.length = 0.0
        else:
            print "num is not alphanumeric :",
            print data
        loopTimes += 1
else:
    print "Ending"
