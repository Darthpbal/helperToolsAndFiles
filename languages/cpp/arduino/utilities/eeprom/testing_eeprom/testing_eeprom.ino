#include <EEPROM.h>


char myString[] = "Hello World!";

void setup() {
  // put your setup code here, to run once:
  for(int address = 0; address < sizeof(myString); address++){
    EEPROM[address] = myString[address];
  }
  Serial.begin(9600);
  Serial.println("\n\nDone saving to memory\n");
}

void loop() {
  // put your main code here, to run repeatedly:

}
