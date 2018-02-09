"""

Todo:
    -Change reporting to be something nicer like an html file or something
    -Make a command that saves the current structure as a new timesheet source file, making finishing a week and starting a new week fast/simple by copying the current week to a new file and clearing the current one. Name the new file either the current date, or take a name from the user.
    -Make a way to view past weeks.
    -Add a "date" attribute to the entries structure.
    -Add a calculation to show how long a task was compared to the days work. % compared to total day hours
    -Make the program create a new timesheet if it doesn't exist.
    -implement an am/pm mode that can be swapped with 24 hour mode
    -make a week structure that contains two weeks (one pay period) to easily swap week view and support a full pay period
    -make an easy way to specify what category a clock action might be, and make adding new categories quick and easy. Make it so these categories can be viewed by their own sets of weeks. Basically sorting clocks into their own weeks like clocking in for math class, hobby, or clocking in for a job.
    -maybe name the report file after todays date and my name and timesheet or something.
    -I do a lot of core functions without dedicating them to their own functions to keep things clean and orthagonal. Abstract these features out to function definitions. Example would be a function specifically for finding the difference between two clock time strings.
"""




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
            entries.append( { "day": items[0], "time": items[1], "inOut": items[2], "summary": items[3] } )




def saveTimeSheet():
    timeSheet = open("timeSheet.csv", 'w')
    for entry in entries:
        timeSheet.write( entry['day'] + "," +  entry['time'] + "," +  entry['inOut'] + "," +  entry['summary'] + "\n" )






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
    entries.append( { "day": weekDay, "time": clockTime, "inOut": inOut, "summary": summary } )


def reportEntries():
    report = open("activity.txt", "w")
    for index, entry in enumerate(entries):
        report.write( "inOut: " + entry["inOut"] + "\n")
        report.write( "day: " + entry["day"] + "\n")
        report.write( "time: " + entry["time"] + "\n")
        report.write( "summary: " + entry["summary"] + "\n")

        if entry["inOut"] == "out":
            startHrs = int( entries[index - 1]["time"][:2] )
            endHrs = int( entry["time"][:2] )
            startMin = int( entries[index - 1]["time"][3:5] )
            endMin = int( entry["time"][3:5] )
            startSec = int( entries[index - 1]["time"][6:] )
            endSec = int( entry["time"][6:] )
            if endSec < startSec:
                endSec += 60
                endMin -= 1
            if endMin < startMin:
                endMin += 60
                endHrs -= 1
            if endHrs < startHrs:
                endHrs += 24
            report.write( "duration: %02d:%02d:%02d\n" % (endHrs - startHrs, endMin - startMin, endSec - startSec) )
            report.write("\n")


def reportHtml():
    report = open("activity.html", "w")

    report.write( "<!doctype html>\n<html lang=\"en\">\n<head>\n<!-- Required meta tags -->\n<meta charset=\"utf-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\n<!-- Bootstrap CSS -->\n" )
    report.write( "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css\" integrity=\"sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm\" crossorigin=\"anonymous\">\n" )
    report.write( "<title>Activity Report</title>" )
    report.write( "</head><body>" )
    report.write( "<table class=\"table table-striped table-hover\">" )
    report.write( "<thead class = \"thead-dark\"><tr>" )
    report.write( "<th scope=\"col\">Duration</th>" )
    report.write( "<th scope=\"col\">In_Out</th>" )
    report.write( "<th scope=\"col\">Day</th>" )
    report.write( "<th scope=\"col\">Time</th>" )
    report.write( "<th scope=\"col\">Description</th>" )
    report.write( "</tr></thead>" )
    report.write( "<tbody>" )

    for index, entry in enumerate(entries):
        # Duration
        if entry["inOut"] == "out":
            startHrs = int( entries[index - 1]["time"][:2] )
            endHrs = int( entry["time"][:2] )
            startMin = int( entries[index - 1]["time"][3:5] )
            endMin = int( entry["time"][3:5] )
            startSec = int( entries[index - 1]["time"][6:] )
            endSec = int( entry["time"][6:] )
            if endSec < startSec:
                endSec += 60
                endMin -= 1
            if endMin < startMin:
                endMin += 60
                endHrs -= 1
            if endHrs < startHrs:
                endHrs += 24

        report.write( "<tr>" )
        if entry["inOut"] == "out":
            report.write( "<td>%02d:%02d:%02d</td>" % (endHrs - startHrs, endMin - startMin, endSec - startSec) )
        else:
            report.write( "<td> </td>" )
        report.write( "<td>" + entry["inOut"] + "</td>" )
        report.write( "<td>" + entry["day"] + "</td>" )
        report.write( "<td>" + entry["time"] + "</td>" )
        report.write( "<td>" + entry["summary"] + "</td>" )
        report.write( "</tr>\n" )


    report.write( "</tbody></table>\n" )
    report.write( "<h1 style=\"bold\">Total: " + str( calcHours() ) + "</h1>\n" )
    report.write( "<!-- Optional JavaScript -->\n<!-- jQuery first, then Popper.js, then Bootstrap JS -->\n" )
    report.write( "<script src=\"https://code.jquery.com/jquery-3.2.1.slim.min.js\" integrity=\"sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN\" crossorigin=\"anonymous\"></script>\n" )
    report.write( "<script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js\" integrity=\"sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q\" crossorigin=\"anonymous\"></script>\n" )
    report.write( "<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js\" integrity=\"sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl\" crossorigin=\"anonymous\"></script>\n" )
    report.write( "</body></html>\n" )





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
                print weekFiltered[index][frameRow]["inOut"],
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


def printDay(day):
    for index, entry in enumerate( entries ):
        if entry["day"].lower() == day:
            print "inOut: " + entry["inOut"]
            print "time: " + entry["time"]
            print "summary: " + entry["summary"]
            if entry["inOut"] == "out":
                startHrs = int( entries[index - 1]["time"][:2] )
                endHrs = int( entry["time"][:2] )

                startMin = int( entries[index - 1]["time"][3:5] )
                endMin = int( entry["time"][3:5] )

                startSec = int( entries[index - 1]["time"][6:] )
                endSec = int( entry["time"][6:] )

                if endSec < startSec:
                    endSec += 60
                    endMin -= 1


                if endMin < startMin:
                    endMin += 60
                    endHrs -= 1



                if endHrs < startHrs:
                    endHrs += 24

                print "duration: %02d:%02d:%02d\n" % (endHrs - startHrs, endMin - startMin, endSec - startSec)
                print
    time.sleep(10)







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
print "show"
time.sleep(2)


userInput = ""
while userInput.lower() != "exit":
    printWeek()
    print "total time = " + str( calcHours() )
    if len(entries) > 0:
        print "last status: " + entries[len(entries) - 1]["inOut"]
    print
    userInput = raw_input("@")

    if userInput.lower() == "in":
        addEntry("in", raw_input("Context: "))

    elif userInput.lower() == "out":
        addEntry("out", raw_input("Context: "))
    elif userInput.lower() == "check":
        if len( entries ) > 0:
            check()
        else:
            print "no entries yet"
    elif userInput.lower() == "show":
        userInput = raw_input("What day? ")
        printDay(userInput)
else:
    saveTimeSheet()
    reportEntries()
    reportHtml()
    print "Exiting..."
