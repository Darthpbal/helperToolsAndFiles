
import time
from datetime import timedelta



entries = []
weekDays = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]

def loadTimeSheet():
    timeSheet = open("timeSheet.csv", 'r')
    line = " "
    while len(line) > 0:
        line = timeSheet.readline()
        line = line.strip()
        if len(line) > 0:
            items = line.split(',')
            entries.append( { "day": items[0], "time": items[1], "in/_out": items[2], "summary": items[3] } )




def saveTimeSheet():
    timeSheet = open("timeSheet.csv", 'w')
    for entry in entries:
        timeSheet.write( entry['day'] + "," +  entry['time'] + "," +  entry['in/_out'] + "," +  entry['summary'] + "\n" )






def addEntry(inOut, summary):
    now = time.asctime( time.localtime( time.time() ) )
    weekDay = now[0:3]
    month   = now[4:7]
    date    = int(now[8:10])
    hour    = int(now[11:13])
    minute  = int(now[14:16])
    second  = int(now[17:19])
    year    = int(now[20:24])
    clockTime = now[11:19]
    entries.append( { "day": weekDay, "time": clockTime, "in/_out": inOut, "summary": summary } )


def printEntries():
    report = open("activity.txt", "w")
    for entry in entries:
        for key in entry:
            print key + ": " + entry[key]
            report.write( key + ": " + entry[key] + "\n")
        print
        report.write("\n")


def calcHours():
    delTime = timedelta(seconds = 0)
    for index, entry in enumerate(entries):
        if index % 2 == 0 and (index + 1) < len(entries):
            delSec = int(entries[index + 1]["time"][6:]) - int(entries[index]["time"][6:])
            delMin = int(entries[index + 1]["time"][3:5]) - int(entries[index]["time"][3:5])
            delHrs = int(entries[index + 1]["time"][0:2]) - int(entries[index]["time"][0:2])
            delTime += timedelta(hours = delHrs, minutes = delMin, seconds = delSec)
    return delTime

def calcDayHours(day):
    delTime = timedelta(seconds = 0)
    for index, entry in enumerate(entries):
        if index % 2 == 0 and (index + 1) < len(entries) and entry["day"] == day:
            delSec = int(entries[index + 1]["time"][6:]) - int(entries[index]["time"][6:])
            delMin = int(entries[index + 1]["time"][3:5]) - int(entries[index]["time"][3:5])
            delHrs = int(entries[index + 1]["time"][0:2]) - int(entries[index]["time"][0:2])
            delTime += timedelta(hours = delHrs, minutes = delMin, seconds = delSec)
    return delTime



def check():
    now = time.asctime( time.localtime( time.time() ) )
    nowhrs    = int(now[11:13])
    nowmins  = int(now[14:16])
    nowsec  = int(now[17:19])
    lasthrs = int( entries[len(entries) - 1]["time"][:2] )
    lastmins = int( entries[len(entries) - 1]["time"][3:5] )
    lastsec = int( entries[len(entries) - 1]["time"][6:] )
    print "Time since last clock: ",
    print timedelta(hours = nowhrs - lasthrs, minutes = nowmins - lastmins, seconds = nowsec - lastsec)
    time.sleep(5)


def printWeek():
    print "-" * 105
    weekFiltered = []
    weekFiltered.append([])
    for day in range(len(weekDays)):
        for entry in entries:
            if entry["day"][:4] == weekDays[day]:
                weekFiltered[day].append(entry)
        weekFiltered.append([])

    frameSize = 0
    for day in weekFiltered:
        if len(day) > 0:
            if len(day) > frameSize:
                frameSize = len(day)

    for weekDay in weekDays:
        print weekDay + "\t\t",
    print
    for frameRow in range(frameSize):
        for index, weekDay in enumerate(weekDays):
            if frameRow < len(weekFiltered[index]):
                print weekFiltered[index][frameRow]["in/_out"],
            else:
                print " ",
            print "\t\t",
        print
        for index, weekDay in enumerate(weekDays):
            if frameRow < len(weekFiltered[index]):
                print weekFiltered[index][frameRow]["time"][:5],
            else:
                print " ",
            print "\t\t",
        print

    for weekDay in weekDays:
        print str( calcDayHours(weekDay) ) + "\t\t",
    print
    print "-" * 105
    print









#    ######## START OF PROGRAM ##########

loadTimeSheet()

title = "Time Keeper"
print " " + "-" * len(title) + " "
print "|" + title + "|"
print " " + "-" * len(title) + " \n"

print "Options are:"
print "in"
print "out"
print "check"
time.sleep(5)


userInput = ""
while userInput.lower() != "exit":
    printWeek()
    print "total time = " + str( calcHours() )
    if len(entries) > 0:
        print "last status: " + entries[len(entries) - 1]["in/_out"]
    print
    userInput = raw_input("@")

    if userInput.lower() == "in":
        addEntry("in", raw_input("Context: "))

    elif userInput.lower() == "out":
        addEntry("out", raw_input("Context: "))
    elif userInput.lower() == "check":
        check()
else:
    saveTimeSheet()
    printEntries()
    print "Exiting..."
