/*
    This program is for the 3G/4G/GPRS cell phone module by Libelium and
    CookingHacks.
    It's basically a cell phone arduino shield will call/sms/4G/GPS/functionality
    like a cell phone.
    For simplicity/laziness this board is referred to as the module/board/shield
    through this file.
    At the end of this file after all the code is an example output of how this
    program works in it's current state. This program turned on the shield, sets
    it to GPS mode, then repeatedly queries the GPS location of the board and prints to the screen.
*/

//sample gps output
//lat, ns, log, ew, date, UTCtime, alt, speed, course(degrees)
//3325.624481,N,11214.179376,W,080117,121733.0,281.5,0,0

int powerPin = 2;    //pin is connected to a sort of power button type of pin
bool validAns;    //used for checking if the response from mobile shield is valid (it understood my commands)



void setup() {
    pinMode(powerPin, OUTPUT);    //set pin to output
    Serial.begin(115200);    //set hardware serial port speed to match the mobile board (arduino TX/RX)
    Serial.println(F("Starting up..."));    //indicate to foolish humans
    powerOn();    //run powerup sequence to startup the mobile shield
    delay(500);    //let the serial port rest a sec
    validAns = sendATcommand("AT+CGPS=1", "OK", 1000);    //send command to set mobile shield into GPS mode for reporting GPS
    if(validAns) Serial.println(F("GPS activated"));    //Indicate successful GPS configuration
    else Serial.println(F("Error initializing GPS"));    //report an error for human debugging
    Serial.println(F("Ready..."));    //indicate to humans the system is finished setting up
}



void loop() {
    validAns = sendATcommand("AT+CGPSINFO", "+CGPSINFO:", 1000);    //send command requesting GPS location
    if(validAns){//if answer from mobile board is valid
        char gpsRaw[100];    //initialize 100 sized char array to store GPS string
        readGPS(gpsRaw);    //after the valid response was seen, a GPS string output is incoming, this reads that, and stores into the gpsRaw variable
        if(gpsRaw[0] == ',') Serial.println(F("Searching..."));    //the gps string is ",,,,,,,," when the location isn't fixed. otherwise the first char is anumber in the longitude
        else {//if first char isn't a comma, then it contains the atitude and therefore aquired a position fix.
            Serial.println(F("Position fixed!"));    //indicate a position fix to humans
            Serial.println(gpsRaw);    //report position
            Serial.println("");    //add a blank line to make the serial monitor more visually divided and easier to read.
        }
    }
    else Serial.println(F("response is invalid"));    //indicate an invalid response from mobile board
    delay(1000);
}



/*
    Power function is used for toggling the power on the mobile board. This is
    basically the same as pushing the "on/off" button for some random generic
    device. This particular board uses something called "AT" commands, which are
    just preset commands it responds to and "AT" is the generic command it uses
    to just report that it's alive. The response it should provide if it's alive
    is "OK".
    This function doesn't assume a starting power state for the board. Meaning I
    don't know if the shield is already on or if it's off. So if I only pulse
    once, I could be actually turning the device off. So I try the "AT" commands
    a few times (20 times) and then try toggling the power pin again. This way,
    I always get to the proper behavior even if the arduino reset for some
    reason without the mobile board resetting power.
*/
void powerOn(){
    int count = 20;    //set the count to the value that toggles the power pin
    validAns = false;    //set default value for the valid answer indication
    while(!validAns){//while answer is not valid
        if(count >= 20){
            Serial.println(F("toggling powPin"));
            digitalWrite(powerPin, HIGH);
            delay(500);
            digitalWrite(powerPin, LOW);
            count = 0;    //reset count to 0 so this toggle won't happen until "AT" is sent 20 times
        }
        validAns = sendATcommand("AT", "OK", 1000);    //check if the mobile board is responding to commands yet
        count++;    //count up
    }
}



/*
    This function is used for sending commands to the mobile board. This is
    required because that's how this particular board is operated. It does
    nothing until preset commands are sent to it making requests. This function
    sends the command (first argument), and then takes a second argument which
    is what the board should respond with, and continually checks for whether or
    not the string coming from the shield is the expected string. And if this
    check fails for longer than the timeout provided (in millisec) then the
    function stops.
    The arguments have a star "*" symbol right after their data types to indicate
    that they are pointers. This means that the function is pointing to and
    modifying the input variables instead of making copies. This is convenient
    for working with character arrays and functions.
    Function returns true if the expected string is seen, and false if it isn't
    seen or if a timeout happens.
*/
bool sendATcommand(char* command, char* expectedAns, unsigned int timeout){
    int charPosition = 0;    //position in the response string.
    bool validAns = false;    //default value
    unsigned long timeAtTransmit;    //used to store the current time in milliseconds when the arduino started waiting for a response from the mobile board
    char responseString[100];    //char arracy to store the mobile board response
    memset(responseString, '\0', 100);    //sets the last character to null making this a c-string
    delay(100);    //let serial port stablize before transmitting
    while(Serial.available() > 0) Serial.read();    //clear incoming serial port buffer, so the only thing in the buffer will be the shield response
    Serial.println(command);    //send command to the mobile board
    timeAtTransmit = millis();    //millis returns how many milliseconds have passed since the program started. Basically current time.
    do{
        if(Serial.available() != 0){//only do something if there's serial data to read
            responseString[charPosition] = Serial.read();    //serial read stored one byte (eight bits is one char), and store it into the current char position in the response string
            charPosition++;    //move to next char position
            if(strstr(responseString, expectedAns) != NULL){//this function returns null if expectedAns can't be found when searching through responseString
                validAns = true;    //if the expectedAns was found inside responseString, then the answer is valid.
            }
        }
    }//while answer is valid and while (current time - time when command was sent) are less than the timeout
    while((validAns == false) && ((millis() - timeAtTransmit) < timeout));
    return validAns;    //output whether or not the answer was valid.
}



/*
    Intended to be used after the GPS request has already been sent and a valid
    response is seen. This function reads the incoming GPS string and stores it
    into the GPS variable. Since the argument is a pointer, this function is able to output to a char array and use it outside of the function like how it's used in the main loop
*/
void readGPS(char* gpsString){
    int gpsChar = 0;    //character position 0
    do{
        while(Serial.available() == 0);    //wait for incoming gps data
        gpsString[gpsChar] = Serial.read();    //store char into gps string
        gpsChar++;    //move to next position
    }
    while(gpsString[gpsChar - 1] != '\r');    //this board has a "cairraige return" and "line feed" and the end of each transmission. this "\r" is the cairraige return. This loops until that is seen and then the NULL character "\0" is set at the end to be a valid c-string that can be used with serial print.
    gpsString[gpsChar] = '\0';
}




/*    Serial monitor output from testing final version of program.

Starting up...
toggling powPin
AT
AT
AT
AT
AT
AT
AT
AT
AT+CGPS=1
GPS activated
Ready...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Searching...
AT+CGPSINFO
Position fixed!
3325.628957,N,11214.179401,W,080117,133552.9,279.0,0,0


AT+CGPSINFO
Position fixed!
3325.626395,N,11214.183505,W,080117,133554.0,270.0,0,0


AT+CGPSINFO
Position fixed!
3325.628062,N,11214.181392,W,080117,133555.0,275.0,0,0


AT+CGPSINFO
Position fixed!
3325.627220,N,11214.181382,W,080117,133556.0,273.0,0,0


AT+CGPSINFO
Position fixed!
3325.625402,N,11214.183444,W,080117,133558.0,268.5,0,0


AT+CGPSINFO
Position fixed!
3325.625880,N,11214.183002,W,080117,133559.0,270.5,0,0


AT+CGPSINFO
Position fixed!
3325.625925,N,11214.183037,W,080117,133600.0,270.5,0,0


AT+CGPSINFO
Position fixed!
3325.625975,N,11214.183022,W,080117,133601.0,271.0,0,0


AT+CGPSINFO
Position fixed!
3325.625993,N,11214.182956,W,080117,133602.0,271.0,0,0


AT+CGPSINFO
Position fixed!
3325.625995,N,11214.182946,W,080117,133603.0,271.0,0,0


AT+CGPSINFO
Position fixed!
3325.625998,N,11214.182941,W,080117,133604.0,271.0,0,0


AT+CGPSINFO
Position fixed!
3325.625998,N,11214.182951,W,080117,133605.0,271.0,0,0


AT+CGPSINFO
Position fixed!
3325.626005,N,11214.182946,W,080117,133606.0,271.0,0,0


AT+CGPSINFO
Position fixed!
3325.626010,N,11214.182946,W,080117,133608.0,271.0,0,0


AT+CGPSINFO
Position fixed!
3325.626015,N,11214.182946,W,080117,133609.0,271.0,0,0

*/

