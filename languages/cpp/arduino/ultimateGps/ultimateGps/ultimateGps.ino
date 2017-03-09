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
*/

void setup() {
    Serial.begin(9600);
    Serial.println("Finished startup");
}


void loop() {
    char tag[] = "$GPGGA,";
    char gpsRaw[100];
    bool validAns = sendATcommand("", tag, 5000);
    if(validAns){
        readGPS(gpsRaw);
        Serial.print(gpsRaw);
    }
    else {
        Serial.println("invalid answer");
    }
}


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




// $GPVTG,258.10,T,,M,0.02,N,0.04,K,D*30
// $GPGGA,100608.000,3324.6004,N,11201.7388,W,2,08,0.98,342.7,M,-26.7,M,0000,0000*54
// $GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05

// while(Serial.available() > 0) Serial.read();















/*example ultimate GPS R3 output

$GPRMC,100607.000,A,3324.6004,N,11201.7388,W,0.02,258.10,170117,,,D*77
$GPVTG,258.10,T,,M,0.02,N,0.04,K,D*30
$GPGGA,100608.000,3324.6004,N,11201.7388,W,2,08,0.98,342.7,M,-26.7,M,0000,0000*54
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPRMC,100608.000,A,3324.6004,N,11201.7388,W,0.04,329.09,170117,,,D*71
$GPVTG,329.09,T,,M,0.04,N,0.07,K,D*3A
$GPGGA,100609.000,3324.6004,N,11201.7388,W,2,08,0.98,342.7,M,-26.7,M,0000,0000*55
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPGSV,3,1,11,12,76,196,45,05,56,134,34,02,55,035,14,25,52,307,23*75
$GPGSV,3,2,11,51,50,171,43,29,27,303,24,20,23,193,37,06,17,050,21*7B
$GPGSV,3,3,11,24,09,208,20,19,08,094,27,31,04,318,19*42
$GPRMC,100609.000,A,3324.6004,N,11201.7388,W,0.02,324.89,170117,,,D*73
$GPVTG,324.89,T,,M,0.02,N,0.04,K,D*3A
$GPGGA,100610.000,3324.6005,N,11201.7390,W,2,08,0.98,342.6,M,-26.7,M,0000,0000*54
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPRMC,100610.000,A,3324.6005,N,11201.7390,W,0.02,330.39,170117,,,D*7D
$GPVTG,330.39,T,,M,0.02,N,0.03,K,D*33
$GPGGA,100611.000,3324.6007,N,11201.7391,W,2,08,0.98,342.4,M,-26.7,M,0000,0000*54
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPRMC,100611.000,A,3324.6007,N,11201.7391,W,0.03,346.63,170117,,,D*70
$GPVTG,346.63,T,,M,0.03,N,0.06,K,D*39
$GPGGA,100612.000,3324.6011,N,11201.7394,W,2,08,0.98,342.3,M,-26.7,M,0000,0000*52
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPRMC,100612.000,A,3324.6011,N,11201.7394,W,0.06,327.00,170117,,,D*76
$GPVTG,327.00,T,,M,0.06,N,0.11,K,D*38
$GPGGA,100613.000,3324.6012,N,11201.7396,W,2,08,0.98,342.2,M,-26.7,M,0000,0000*53
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPRMC,100613.000,A,3324.6012,N,11201.7396,W,0.03,297.95,170117,,,D*75
$GPVTG,297.95,T,,M,0.03,N,0.06,K,D*3D
$GPGGA,100614.000,3324.6013,N,11201.7397,W,2,08,0.98,342.0,M,-26.7,M,0000,0000*56
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPGSV,3,1,11,12,76,195,45,05,56,134,35,02,55,035,13,25,52,307,23*70
$GPGSV,3,2,11,51,50,171,43,29,27,303,25,20,23,193,38,06,17,050,20*74
$GPGSV,3,3,11,24,09,208,20,19,08,094,27,31,04,318,19*42
$GPRMC,100614.000,A,3324.6013,N,11201.7397,W,0.00,334.19,170117,,,D*7D
$GPVTG,334.19,T,,M,0.00,N,0.01,K,D*35

*/
