int cs = 8;
const bool on = LOW, off = HIGH;
bool selState = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  Serial.begin(9600);
  pinMode(cs, INPUT);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = analogRead(A0) * 5.0 / 1023 * 1000.0 / 10.0;
  selState = digitalRead(cs);
//Serial.println(selState);
  if(selState == on){
    digitalWrite(13, HIGH);

    Serial.println(temp);
    while(!digitalRead(cs));
    
    digitalWrite(13, LOW);
  }
}
