int xAxisPin = 2, yAxisPin = 3;

void setup() {
    Serial.begin(9600);
    pinMode(xAxisPin, INPUT);
    pinMode(yAxisPin, INPUT);
}


void loop() {
    int pulseX;
    int accelX, accelY;
    pulseX = pulseIn(xAxisPin, HIGH);//10 microsec to max 10 ms
    accelX = pulseToMilliG(pulseX);
    // int simpleAccel = map(pulseX, 10, 10000, -3000, 3000);//could this possibly work somehow? intuitively I wanna say yes, but the test was wrong...
    accelY = pulseToMilliG( pulseIn(yAxisPin, HIGH) );

    Serial.print(accelX);
    Serial.print("\t");
    Serial.println(accelY);
    delay(100);
}


int pulseToMilliG(int pulseDuration){
    return ( (pulse / 10) - 500 ) * 8;
}
