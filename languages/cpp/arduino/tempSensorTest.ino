void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  float adcVal = analogRead(A0);
  float voltage = ((adcVal * 5000) / 1023);
  float tempC = (voltage - 500) / 10;
  float tempF = (tempC * 9.0/5.0) + 32.0;
  Serial.println();
  Serial.print("adcVal = ");
  Serial.println(adcVal);
  Serial.print("voltage = ");
  Serial.println(voltage);
  Serial.print("tempC = ");
  Serial.println(tempC);
  Serial.print("tempF = ");
  Serial.println(tempF);
  Serial.println();
  delay(500);
}
90 deg
60 deg
