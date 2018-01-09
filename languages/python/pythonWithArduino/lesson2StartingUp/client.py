import serial

arduinoSerialData = serial.Serial("/dev/ttyUSB0", 9600)

tot = 0
while True:
    if (arduinoSerialData.inWaiting() > 0):
        data = arduinoSerialData.readline()
        print len(data) ,
        if(len(data) > 10):
            print data
        tot += int( data[:len(data) - 2] )
        print "  Data: %2s\tRunning Tot: %d" % (data[:len(data) - 2], tot)
        if int( tot ) > 420:
            break
else:
    print "Ending"
