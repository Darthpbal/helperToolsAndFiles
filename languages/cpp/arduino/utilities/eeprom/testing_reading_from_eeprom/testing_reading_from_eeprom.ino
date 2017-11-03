#include <EEPROM.h>


char myString[] = "Hello World!";

void setup() {
  Serial.begin(9600);
  Serial.println("\n\nReading from memory...\n\n");
  // put your setup code here, to run once:
  for(int address = 0; address < sizeof(myString); address++){
    Serial.print(char(EEPROM[address]));
  }
  Serial.println("\n\nDone reading from memory.");
}

void loop() {
  // put your main code here, to run repeatedly:

}
