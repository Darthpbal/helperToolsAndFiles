int temp1Pin = 0, temp2Pin = 1;

void setup() {
    Serial.begin(9600);
}



void loop() {
    int temp1Raw = analogRead(temp1Pin);
    int temp2Raw = analogRead(temp2Pin);

    Serial.print("temp1Raw: ");
    Serial.print(temp1Raw);
    Serial.print("\ttemp1mVolt: ");
    Serial.print(convADCtomilliV(temp1Raw));

    Serial.print("mV\ttemp2Raw: ");
    Serial.print(temp2Raw);
    Serial.print("\ttemp2mVolt: ");
    Serial.print(convADCtomilliV(temp2Raw));
    Serial.println("mV");
}


int convADCtomilliV(int adcVal){
    return (adcVal * 5000) / 1023;
}
