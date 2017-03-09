const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data

boolean newData = false;

void setup() {
 Serial.begin(9600);
 Serial.println("<Arduino is ready>");
}

void loop() {
 recvWithEndMarker();
 showNewData();
}

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

void showNewData() {
 if (newData == true) {
 Serial.print("This just in ... ");
 Serial.println(receivedChars);
 newData = false;
 }
}





















void setup() {
    Serial.begin(9600);
    Serial.println("Starting up");


    //check GPS operation at startup for 10 sec
    Serial.println("Checking GPS...");
    char gpsPrefix;
    int timeout = 10000;//in millisec.
    unsigned long startTime = millis();//sample the time when we start waiting for the GPS
    while( ((millis() - startTime) < timeout) && (gpsPrefix != '$') ){//while timeout hasn't happened and char isn't seen from GPS
        if(Serial.available()) gpsPrefix = Serial.peek();
    }
    if(gpsPrefix == '$') Serial.println("GPS ready!!!");
    else Serial.println("GPS error");
    //ending GPS check

    Serial.println("Ending startup");
    delay(500);
}


void loop() {
    Serial.println("Start loop");
    int gpsHeaderSize = 8;
    char gpsRAW[100], gpsHeader[gpsHeaderSize];
    readGPS(gpsRAW);
    //
    // //transfer the front portion of gpsRAW into the header to check it.
    // for(int i = 0; i < gpsHeaderSize; i++){
    //     gpsHeader[i] = gpsRAW[i];
    // }
    // gpsHeader[gpsHeaderSize] = '\0';
    //
    //
    // if(gpsHeader == "$GPRMC,") Serial.print(gpsRAW);
    // delay(500);
}


void readGPS(char* gps){
    int gpsCharNum = 0;
    do{
        while(!Serial.available());
        gps[gpsCharNum] = Serial.read();
        gpsCharNum++;
    }
    while(gps[gpsCharNum - 1] != '\r');
    gps[gpsCharNum] = '\0';
}






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









////////////////  references   ////////////////////////////////////





if(Serial.available()){
while(Serial.peek() != '$') Serial.read();//empty buffer until dollar sign
// String serialString = Serial.readString();
String serialString = Serial.readStringUntil('\n');
serialString = serialString.substring(0, serialString.length() - 1);
Serial.println(serialString);
// if(serialString.substring(1, 6) == "GPGGA"){
//     Serial.println(serialString.substring(7));
//     serialString = "";//empty string so no old data is in it.
// }else {
//     // Serial.println("empty unwanted data");
//     while(Serial.available() > 0) Serial.read();
// }
}else {
// Serial.println("noData");
}
delay(1000);





if(Serial.available()){

}

while(Serial.available() > 0){
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
        stringComplete = true;
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










//check GPS operation at startup for 10 sec
Serial.println("Checking GPS...");
char gpsPrefix;
int timeout = 10000;//in millisec.
unsigned long startTime = millis();//sample the time when we start waiting for the GPS
while( ((millis() - startTime) < timeout) && (gpsPrefix != '$') ){//while timeout hasn't happened and char isn't seen from GPS
    if(Serial.available()) gpsPrefix = Serial.peek();
}
if(gpsPrefix == '$') Serial.println("GPS ready!!!");
else Serial.println("GPS error");
//ending GPS check












/*
  String substring()

 Examples of how to use substring in a String

 created 27 July 2010,
 modified 2 Apr 2012
 by Zach Eveland

 http://www.arduino.cc/en/Tutorial/StringSubstring

 This example code is in the public domain.
*/

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  Serial.println("\n\nString  substring():");
  Serial.println();
}

void loop() {
  // Set up a String:
  String stringOne = "Content-Type: text/html";
  Serial.println(stringOne);

  // substring(index) looks for the substring from the index position to the end:
  if (stringOne.substring(19) == "html") {
    Serial.println("It's an html file");
  }
  // you can also look for a substring in the middle of a string:
  if (stringOne.substring(14, 18) == "text") {
    Serial.println("It's a text-based file");
  }

  // do nothing while true:
  while (true);
}





/*
  Serial Event example

 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and
 clears it.

 A good test for this is to try it with a GPS receiver
 that sends out NMEA 0183 sentences.

 Created 9 May 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/SerialEvent

*/

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}


 //  SerialEvent occurs whenever a new data comes in the
 // hardware serial RX.  This routine is run between each
 // time loop() runs, so using delay inside loop can delay
 // response.  Multiple bytes of data may be available.

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
