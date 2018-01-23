#include <OneWire.h>

OneWire temp(5);
byte tempExt[8] = {0x28, 0x9C, 0x59, 0x4, 0x0, 0x0, 0x80, 0x36},
    tempInt[8] = {0x28, 0xF2, 0x91, 0xAB, 0x5, 0x0, 0x0, 0x70},
    genericTempAddress[8];

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);

    bool extPass = FALSE;
    bool intPass = FALSE;
    while(temp.search(genericTempAddress)){
        bool extCheck = TRUE;
        bool intCheck = TRUE;
        for(int i = 0; i < 8; i++){
            if( genericTempAddress[i] != tempExt[i] ) {
                extCheck = FALSE;
            }
            if( genericTempAddress[i] != tempInt[i] ) {
                intCheck = FALSE;
            }
        }
        if(intCheck){
            Serial.println(F("internal found"));
            intPass = TRUE;
        }

        if(extCheck){
            Serial.println(F("external found"));
            extPass = TRUE;
        }
        // if(!intCheck && !extCheck) Serial.println(F("problem"));
    }
    if(!extPass) Serial.println(F("external failure"));
    if(!intPass) Serial.println(F("internal failure"));



}

void loop() {

    byte data[12];
    int16_t raw;

    temp.reset();
    temp.select(tempInt);
    temp.write(0x44, 1);
    temp.reset();
    temp.select(tempInt);
    temp.write(0xBE);

    for (int i = 0; i < 9; i++) {           // we need 9 bytes
      data[i] = temp.read();
    }

    raw = (data[1] << 8) | data[0];
    float fahrenheit = (float)(raw / 16.0) * 1.8 + 32.0;

    Serial.println(fahrenheit);


    delay(1 * 1000);
}
