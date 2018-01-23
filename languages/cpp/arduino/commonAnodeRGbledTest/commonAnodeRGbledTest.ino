
int redPin = 3, greenPin = 2, bluePin = 7;
enum color {RED, GREEN, BLUE, YELLOW, CYAN, PURPLE, WHITE, OFF};


void setup() {
    // put your setup code here, to run once:
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    digitalWrite(redPin, HIGH);
    digitalWrite(bluePin, HIGH);
    digitalWrite(greenPin, HIGH);
}

void loop() {


    int del = 5000;
    setColor(RED);
    delay(del);
    setColor(GREEN);
    delay(del);
    setColor(BLUE);
    delay(del);
    setColor(YELLOW);
    delay(del);
    setColor(CYAN);
    delay(del);
    setColor(PURPLE);
    delay(del);
    setColor(WHITE);
    delay(del);
    setColor(OFF);
    delay(del);
}

void setColor(color ledColor){
    switch(ledColor){
        case RED:
            //redPin
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, HIGH);
            digitalWrite(bluePin, HIGH);
        break;
        case GREEN:
            //greenPin
            digitalWrite(redPin, HIGH);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, HIGH);
        break;
        case BLUE:
            //bluePin
            digitalWrite(redPin, HIGH);
            digitalWrite(greenPin, HIGH);
            digitalWrite(bluePin, LOW);
        break;
        case YELLOW:
            //yellow
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, HIGH);
        break;
        case CYAN:
            //cyan
            digitalWrite(redPin, HIGH);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, LOW);
        break;
        case PURPLE:
            //purple.
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, HIGH);
            digitalWrite(bluePin, LOW);
        break;
        case WHITE:
            // white
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, LOW);
        break;
        default:
            // off
            digitalWrite(redPin, HIGH);
            digitalWrite(greenPin, HIGH);
            digitalWrite(bluePin, HIGH);
        break;
    }

}
