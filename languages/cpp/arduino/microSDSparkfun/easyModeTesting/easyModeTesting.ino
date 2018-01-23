#include <SPI.h>
#include <SD.h>


File logFile;
char fileName[] = "logFile.csv";
const uint8_t chipSelect = 10;
const uint8_t cardDetect = 9;
bool alreadyBegan = false;


void setup() {
    Serial.begin(9600);

    pinMode(cardDetect, INPUT);
    initializeCard();

    logFile = SD.open(fileName, FILE_WRITE);
    if(logFile) {
        logFile.println("x,y,z,#");
        for(int i = -50; i < 50; i++){
            logFile.print(pow(i,1));
            logFile.print(',');
            logFile.print(pow(i,2));
            logFile.print(',');
            logFile.print(pow(i,3));
            logFile.print(',');
            logFile.println(millis());
        }
        logFile.close();
    }
    else{
        Serial.println(F("Failed to open file"));
    }


}



void loop() {
    if (!digitalRead(cardDetect)){
        initializeCard();
    }

    logFile = SD.open("startup.csv", FILE_WRITE);
    if(logFile) {
        logFile.print(4);
        logFile.print(',');
        logFile.print(2);
        logFile.print(',');
        logFile.print(0);
        logFile.print(',');
        logFile.println(millis());
        logFile.close();
    }
    else{
        Serial.println(F("Failed to open file"));
    }
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
