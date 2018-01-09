#include <SPI.h>
#include <SD.h>


File logFile;
char fileName[] = "logFile.txt";
const uint8_t chipSelect = 8;
const uint8_t cardDetect = 7;
bool alreadyBegan = false;


void setup() {
    Serial.begin(9600);

    pinMode(cardDetect, INPUT);
    initializeCard();

    Serial.println("Started up, logging header.");
    String header = "Fucking header you piece of shit.\n";
    lineLogger(header);
}



void loop() {
    if (!digitalRead(cardDetect)){
        initializeCard();
    }

    Serial.println("logging line...");


    String logLine = "Whatevers,";

    for(int i = 0; i < 35; i++){// appending 35 is fine, 36 will fault
      logLine += "Whatevers,";
    }
    logLine += "\n";

    lineLogger(logLine);
}



////////////////////////////////////////////////////////////////////////////////
// Do everything from detecting card through opening the demo file
////////////////////////////////////////////////////////////////////////////////
void initializeCard(void){
    Serial.print(F("Initializing SD card..."));

    // Is there even a card?
    if (!digitalRead(cardDetect)){
        Serial.println(F("No card detected. Waiting for card."));
        while (!digitalRead(cardDetect));
    delay(250); // 'Debounce insertion'
    }

    // Card seems to exist.  begin() returns failure
    // even if it worked if it's not the first call.
    if (!SD.begin(chipSelect) && !alreadyBegan){  // begin uses half-speed...
        Serial.println(F("Initialization failed!"));
        initializeCard(); // Possible infinite retry loop is as valid as anything
    }
    else{
        alreadyBegan = true;
    }
    Serial.println(F("Initialization done."));

    Serial.print(fileName);
    if (SD.exists(fileName)){
        Serial.println(F(" exists."));
    }
    else{
        Serial.println(F(" doesn't exist. Creating."));
    }

    Serial.print("Opening file: ");
    Serial.println(fileName);

    Serial.println(F("Enter text to be written to file. 'EOF' will terminate writing."));
}


// Write the buffer to the log file. If we are possibly in the EOF state, verify
// that to make sure the command isn't written to the file.
void lineLogger(String line){
    logFile = SD.open(fileName, FILE_WRITE);
    if (logFile){
        logFile.write(line.c_str(), line.length());
        logFile.flush();
        logFile.close();
    }
}
