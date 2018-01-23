
import time


# entries = [ {"day": "sunday", "time": "4:20pm", "in/_out": "out", "summary": "wrote some code" } , {"day": "sunday", "time": "4:20pm", "in/_out": "out", "summary": "wrote some code" } ];
entries = []




def printWeek():
    for weekDay in weekDays:
        print weekDay + "\t\t",
    print

    for entry in entries:
        for weekDay in weekDays:
            if entry["day"][:4] == weekDay:
                print entry["in/_out"],
            else:
                print " ",
            print "\t\t",
        print

        for weekDay in weekDays:
            if entry["day"][:4] == weekDay:
                print entry["time"],
            else:
                print " ",
            print "\t\t",
        print
        print '-' * 100



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
    for entry in entries:
        for key in entry:
            print key + ": " + entry[key]
            print











weekDays = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
title = "Time Keeper"
print " " + "-" * len(title) + " "
print "|" + title + "|"
print " " + "-" * len(title) + " \n"


print "\n"

print "Options are:\nIn\nOut\n"

userInput = ""

while userInput.lower() != "exit":
    userInput = raw_input("@")

    if userInput.lower() == "in":
        addEntry("in", raw_input("Context: "))

    elif userInput.lower() == "out":
        addEntry("out", raw_input("Context: "))




printWeek()

printEntries()
