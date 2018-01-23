/*
Compiles to 462 bytes of program space and 9 bytes of dynamic memory


atmega 328 datasheet pages of interest

 - pg 2 - package pinout
 - pg 76 - Ports as general pin IO
 - pg 92 - register description
 - pg 425 - register summary

 set data direction register to input/output by setting binary value on port and pin registers
 0 to read, 1 to write

 then set port register bit to output high or low. If pin is set to output, setting the port bit sets the output, but if the data direction is input, then the port bit enables or disables the internal pull up.
 1 to set high or enable pull up, 0 to set low or disable pull up.

 pin register is treated as read only.


 port, pin and data direction registers are 8bit wide formatted as big endian.
 ddr[7:0]
 port[7:0]
 pin[7:0]

to configure pin directions for input on pin 2 and output on pin 5
ddr = 0010 0000

then write 0000 0100 to portD to enable the internal pullup on pin 2.
*/



int btnPin = 2, //PD2
    ledPin = 5; //PD5

void setup() {
    // pinMode(btnPin, INPUT_PULLUP); // means the button doesn't need a pull up, but I hear the internals are weak.
    // pinMode(ledPin, OUTPUT);

    DDRD = B00100000;
    PORTD = B00000100;
}



void loop() {
    // int btn = digitalRead(btnPin);
    // int btn = ((1 << btnPin) & PIND) >> btnPin; // read bit
    int btn = (_BV(btnPin) & PIND) >> btnPin; // read bit using BV macro

    if(btn == LOW) {
        // digitalWrite(ledPin, HIGH);
        // PORTD = B00100000; // this accidentally overwrites my pull up on the ledpin.
        // PORTD = (1 << ledPin) | PORTD; // set bit
        PORTD = _BV(ledPin) | PORTD; // set bit using BV macro
    }
    else {
        // digitalWrite(ledPin, LOW);
        // PORTD = B00000000; // this accidentally overwrites my pull up on the ledPin.
        // PORTD = ~(1 << ledPin) & PORTD; //clear bit
        PORTD = ~_BV(ledPin) & PORTD; //clear bit using BV macro
    }
}
