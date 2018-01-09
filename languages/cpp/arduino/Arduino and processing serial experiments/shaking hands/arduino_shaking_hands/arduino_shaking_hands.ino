char val;    //store a 1 byte character
int ledPin = 13;
boolean ledState = LOW;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  establishContact();    //send a byte to establish contact until receiver responds
}

void loop(){
  if(Serial.available()>0){ //if data is available to read
    val = Serial.read();   //read serial port and store in "val"
    if(val == '1'){
      ledState = !ledState;//toggle ledState
      digitalWrite(ledPin, HIGH/*ledState*/);
    }
    delay(100);
  }
  else{
    //digitalWrite(ledPin, LOW);
    Serial.println("Hello world!");
    delay(50);
  }
}

void establishContact(){
  while(Serial.available()<=0){  //while serial connection isn't available 
    Serial.println("A"); //send string "A" 
    delay(300);
  }
}
