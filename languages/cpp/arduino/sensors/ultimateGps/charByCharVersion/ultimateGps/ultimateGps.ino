/*
This program is meant to be a more or less proof of concept operating UART serial type devices like the adafruit ultimate GPS board

board operating minimum pinout
board   |   arduino
vin     |   3.3V or 5V supply
gnd     |   gnd
tx      |   rx (remember to unplug between uploading programs)

note on ultimate GPS output uart String:
    transmissions begin with a '$' character
    transmissions are encoded as NMEA sentences and directly following the '$' signal, the sentence type prefix is shown like GPGGA or GPGSV
    transmission end with a pair of \r\n carriage return and newline pair
    largest size line currently seen = 73 chars not counting endline characters
    input string line sizes vary depending on incoming sentence type and GPS fix status (gps fix yas/no)




using the current SIM5218 methods, this program compiles to 2044 bytes or 6% of program space and 226 bytes (11%) dynamic memory

a simple parsing example from the adafruit ultimate GPS library compiles to 11346 bytes (35%) program space and 932 bytes (45%) dynamic memory

that's a reduction in program space by 82% (9302 bytes) and a reduction in dynamic memory by 76% (706 bytes)
*/

void setup() {
    Serial.begin(9600);
    Serial.println("Finished startup");
}


void loop() {
    char tag[] = "$GPGGA,";
    char gpsRaw[100];
    bool validAns = detectGPSTag(tag, 5000);
    if(validAns){
        readGPS(gpsRaw);
        Serial.println(gpsRaw);
    }
    else {
        Serial.println("invalid answer");
    }
    delay(250);//error extra bits of lines show up without this.
}








void readGPS(char* gpsString){
    int gpsChar = 0;    //character position 0
    do{
        while(Serial.available() == 0);    //wait for incoming gps data
        gpsString[gpsChar] = Serial.read();    //store char into gps string
        gpsChar++;    //move to next position
    }
    while(gpsString[gpsChar - 1] != '\r');    //this board has a "cairraige return" and "line feed" and the end of each transmission. this "\r" is the cairraige return. This loops until that is seen and then the NULL character "\0" is set at the end to be a valid c-string that can be used with serial print.
    gpsString[gpsChar - 1] = '\0';
    gpsString[gpsChar] = '\0';
}








bool detectGPSTag(char* expectedAns, unsigned int timeout){
    int charPosition = 0;    //position in the response string.
    bool validAns = false;    //default value
    unsigned long timeAtTransmit;    //used to store the current time in milliseconds when the arduino started waiting for a response from the mobile board
    char responseString[100];    //char arracy to store the mobile board response
    memset(responseString, '\0', 100);    //sets the last character to null making this a c-string
    delay(100);    //let serial port stablize before transmitting
    while(Serial.available() > 0) Serial.read();    //clear incoming serial port buffer, so the only thing in the buffer will be the shield response
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
current program output performance example
it seems that the extra error line that happens
during a fix is unpredictable in contents, but predictable that some short extra line will be there.


114130.087,,,,,0,00,,,M,,M,,*71
114131.092,,,,,0,03,,,M,,M,,*77
114132.092,,,,,0,03,,,M,,M,,*74
114134.000,,,,,0,03,,,M,,M,,*79
114135.000,3325.6421,N,11214.1791,W,1,03,1.41,176.8,M,-26.8,M,,*5C
114136.000,3325.6416,N,11214.1788,W,1,03,1.41,176.8,M,-26.8,M,,*53
114136.208,3325.6413,N,11214.1788,W,1,03,1.41,176.8,M,-26.8,M,,*5C
3,090317,,,A*75
114138.000,3325.6403,N,11214.1787,W,1,03,1.41,176.8,M,-26.8,M,,*56
114139.000,3325.6382,N,11214.1787,W,1,03,1.41,176.8,M,-26.8,M,,*59
114140.000,3325.6378,N,11214.1786,W,1,03,1.41,176.8,M,-26.8,M,,*53
114141.000,3325.6376,N,11214.1787,W,1,03,1.41,176.8,M,-26.8,M,,*5D
114142.000,3325.6375,N,11214.1787,W,1,03,1.41,176.8,M,-26.8,M,,*5D
1,090317,,,A*73
1214.1788,W,0.11,157.60,090317,,,A*74
114144.000,3325.6371,N,11214.1789,W,1,03,1.40,176.8,M,-26.8,M,,*50
114145.000,3325.6368,N,11214.1788,W,1,03,1.41,176.8,M,-26.8,M,,*59
114146.000,3325.6368,N,11214.1787,W,1,03,1.41,176.8,M,-26.8,M,,*55
114147.000,3325.6368,N,11214.1786,W,1,03,1.41,176.8,M,-26.8,M,,*55
,W,0.26,35.24,090317,,,A*41
114148.000,3325.6367,N,11214.1787,W,1,03,1.41,176.8,M,-26.8,M,,*54
114148.209,3325.6366,N,11214.1787,W,1,03,21.70,176.8,M,-26.8,M,,*6E
114150.000,3325.6366,N,11214.1787,W,1,03,21.71,176.8,M,-26.8,M,,*6D
114151.000,3325.6363,N,11214.1784,W,1,03,1.41,176.8,M,-26.8,M,,*5B
114152.000,3325.6361,N,11214.1782,W,1,03,1.41,176.8,M,-26.8,M,,*5C
782,W,0.32,147.93,090317,,,A*75
114153.000,3325.6360,N,11214.1782,W,1,03,1.40,176.8,M,-26.8,M,,*5D
114154.000,3325.6359,N,11214.1781,W,1,03,1.41,176.8,M,-26.8,M,,*52
114154.209,3325.6358,N,11214.1780,W,1,03,1.40,176.8,M,-26.8,M,,*58
114156.000,3325.6357,N,11214.1779,W,1,03,1.41,176.8,M,-26.8,M,,*59
114157.000,3325.6356,N,11214.1779,W,1,03,1.41,176.8,M,-26.8,M,,*59
779,W,0.17,180.04,090317,,,A*72
114158.000,3325.6353,N,11214.1779,W,1,03,1.41,176.8,M,-26.8,M,,*53
114159.000,3325.6352,N,11214.1779,W,1,03,1.41,176.8,M,-26.8,M,,*53
114200.000,3325.6351,N,11214.1780,W,1,03,1.41,176.8,M,-26.8,M,,*59
114200.213,3325.6350,N,11214.1781,W,1,03,1.41,176.8,M,-26.8,M,,*59
114202.000,3325.6348,N,11214.1781,W,1,03,1.41,176.8,M,-26.8,M,,*52
781,W,0.24,199.75,090317,,,A*77
114203.000,3325.6348,N,11214.1783,W,1,03,1.41,176.8,M,-26.8,M,,*51
114204.000,3325.6347,N,11214.1785,W,1,03,1.41,176.8,M,-26.8,M,,*5F
114205.000,3325.6346,N,11214.1786,W,1,03,1.41,176.8,M,-26.8,M,,*5C
114206.000,3325.6346,N,11214.1786,W,1,03,1.41,176.8,M,-26.8,M,,*5F
114206.212,3325.6346,N,11214.1786,W,1,03,1.40,176.8,M,-26.8,M,,*5F
786,W,0.29,248.78,090317,,,A*74
114208.000,3325.6346,N,11214.1786,W,1,03,1.41,176.8,M,-26.8,M,,*51
114209.000,3325.6345,N,11214.1785,W,1,03,1.41,176.8,M,-26.8,M,,*50
114210.000,3325.6345,N,11214.1782,W,1,03,1.40,176.8,M,-26.8,M,,*5E
114211.000,3325.6345,N,11214.1


*/
