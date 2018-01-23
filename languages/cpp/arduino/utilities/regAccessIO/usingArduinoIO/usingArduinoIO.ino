/*
Program lights up an LED if and only
if the button is pressed.

program compiles to 910 bytes or 2% of program space
with 9bytes of dynamic memory
*/



int btnPin = 2, ledPin = 5;

void setup() {
    pinMode(btnPin, INPUT_PULLUP); // means the button doesn't need a pull up, but I hear the internals are weak.
    pinMode(ledPin, OUTPUT);
}



void loop() {
    int btn = digitalRead(btnPin);

    if(btn == LOW) {
        digitalWrite(ledPin, HIGH);
    }
    else {
        digitalWrite(ledPin, LOW);
    }
}
