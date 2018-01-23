import serial
import keyboard
from visual import *
#  todo, add mouse control option.  https://github.com/boppreh/mouse

gamePadPort = serial.Serial("/dev/rfcomm0", 9600)

i = 0
while i < 50:
    rate(400)
    if gamePadPort.inWaiting() > 0:
        action = gamePadPort.readline()
        action = action.strip()

        if action == "jprs":
            keyboard.press('k')
        if action == "tprs":
            keyboard.press('t')
        if action == "sprs":
            keyboard.press('f')
        if action == "cprs":
            keyboard.press('y')
        if action == "xprs":
            keyboard.press('g')
        if action == "uprs":
            keyboard.press('w')
        if action == "dprs":
            keyboard.press('s')
        if action == "rprs":
            keyboard.press('d')
        if action == "lprs":
            keyboard.press('a')




        if action == "jrel":
            keyboard.release('k')
        if action == "trel":
            keyboard.release('t')
        if action == "srel":
            keyboard.release('f')
        if action == "crel":
            keyboard.release('y')
        if action == "xrel":
            keyboard.release('g')
        if action == "urel":
            keyboard.release('w')
        if action == "drel":
            keyboard.release('s')
        if action == "rrel":
            keyboard.release('d')
        if action == "lrel":
            keyboard.release('a')
else:
    print "Ending"
