//this program was intended for testing the samd21 based motor controller board
//made for the PC ascend team.  For entering a motor number in serial monitor and
//driving a specific motor
int m1 = 2;
int m2 = 3;
int m3 = 4;
int m4 = 5;
int m5 = 6;
int m6 = 7;
int m7 = 8;
int m8 = 9;
int fwd = 10;
int rev = 11;

void driveMotor(int pEnPin, int pFwd){
	int del = 5000;
	digitalWrite(pEnPin, HIGH);
	digitalWrite(pFwd, HIGH);
	delay(del);
	digitalWrite(pFwd, LOW);
}

void setup() {
	Serial.begin(9600);
	Serial.println(F("init..."));
	for(int i = 2; i < 12; i++){
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
	Serial.println(F("finished startup"));
}

void loop() {
  while(Serial.available() > 0){
	  int motor = Serial.parseInt();
	  if(Serial.read() == '\n'){
		//   driveMotor(motor, fwd);
		  Serial.println(motor, DEC);
	  }
  }
}
