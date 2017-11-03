int signalPin = 2;
int radStatePin = 3;
int loNoRadPeriod = 5000,
    hiNoRadPeriod = 2500,
    loRadiatedPeriod = 125,
    hiRadiatedPeriod = 83;

void setup() {
    pinMode(signalPin, OUTPUT);
    pinMode(radStatePin, OUTPUT);
    Serial.begin(9600);
    Serial.println("Startup fininshed");
}



void loop() {
    digitalWrite(signalPin, HIGH);
    bool radState = digitalRead(radStatePin);
    if(radState){//nopress
        Serial.println("noRad - ON");
        delay(loNoRadPeriod);
    }
    else{//press
        Serial.println("Rad - ON");
        delay(loRadiatedPeriod);

    }

    digitalWrite(signalPin, LOW);

    if(radState) {
        Serial.println("noRad - OFF");
        delay(loNoRadPeriod);
    }
    else {
        Serial.println("Rad - OFF");
        delay(loRadiatedPeriod);
    }
}
