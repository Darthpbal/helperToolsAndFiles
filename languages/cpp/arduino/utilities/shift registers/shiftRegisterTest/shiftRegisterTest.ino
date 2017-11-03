/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/
const byte digitDefinitions[10] = {// a, b, c, e, f, g
                            B00000011,    // 0
                            B10011111,    // 1
                            B00100101,    // 2
                            B00001101,    // 3
                            B10011001,    // 4
                            B01001001,    // 5
                            B01000001,    // 6
                            B00011111,    // 7
                            B00000001,    // 8
                            B00011001     // 9
                            };

int latchPin = 1;
int clockPin = 0;
int dataPin = 2;
int del = 2000;
byte leds = 0;
word clockFace[] = {B00100101, B10011001};
byte secondCount = 0, minuteCount = 0, hourCount = 0;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop()
{
  leds = B11111111;
  updateShiftRegister(leds);
  delay(del);

  leds = B10011001;
  updateShiftRegister(leds);
  delay(del);

  leds = B00100101;
  updateShiftRegister(leds);
  delay(del);

  leds = B00000011;
  updateShiftRegister(leds);
  delay(del);

  leds = B11111110;
  updateShiftRegister(leds);
  delay(del);



  leds = digitDefinitions[0];
  updateShiftRegister(leds);
  delay(del);

  leds = digitDefinitions[1];
  updateShiftRegister(leds);
  delay(del);
  leds = digitDefinitions[2];
  updateShiftRegister(leds);
  delay(del);
  leds = digitDefinitions[3];
  updateShiftRegister(leds);
  delay(del);
  leds = digitDefinitions[4];
  updateShiftRegister(leds);
  delay(del);
  leds = digitDefinitions[5];
  updateShiftRegister(leds);
  delay(del);
  leds = digitDefinitions[6];
  updateShiftRegister(leds);
  delay(del);
  leds = digitDefinitions[7];
  updateShiftRegister(leds);
  delay(del);
  leds = digitDefinitions[8];
  updateShiftRegister(leds);
  delay(del);
  leds = digitDefinitions[9];
  updateShiftRegister(leds);
  delay(del);


  updateShiftRegister(B11111111,B11111111);
  updateShiftRegister(clockFace[0],clockFace[1]);
  delay(del);

//  for (int i = 0; i < 8; i++)
//  {
//    bitSet(leds, i);
//    updateShiftRegister();
//    delay(del);
//  }
}


void updateShiftRegister(byte lowBits)
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, lowBits);
   digitalWrite(latchPin, HIGH);
}

void updateShiftRegister(byte lowBits, byte highBits)
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, highBits);
   shiftOut(dataPin, clockPin, LSBFIRST, lowBits);
   digitalWrite(latchPin, HIGH);
}
