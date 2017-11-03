const int clkPin = A4; //the clk attach to pin2
const int dtPin = A5; //the dt attach to pin3
const int swPin = 2;//the number of the button
const int statLed = A3;

unsigned long transmitTime = 0;
unsigned int transmitDelay = 1000;

bool active = false;

void setup() {
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);
  pinMode(statLed, OUTPUT);
  digitalWrite(statLed, LOW);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(swPin) == LOW){
      while(digitalRead(swPin) == LOW);
      active = !active;
      digitalWrite(statLed, active);
  }

  
  if(active){
    int scroll = getEncoderTurn();
    if(scroll == 1) Serial.print("up");
    else if(scroll == -1) Serial.print("dn");
  }
}


int getEncoderTurn(void)
{
  static int oldA = HIGH; //set the oldA as HIGH
  static int oldB = HIGH; //set the oldB as HIGH
  int result = 0;
  int newA = digitalRead(dtPin);//read the value of clkPin to newA
  int newB = digitalRead(clkPin);//read the value of dtPin to newB
  if (newA != oldA || newB != oldB) //if the value of clkPin or the dtPin has changed
  {
    // something has changed
    if (oldA == HIGH && newA == LOW)
    {
      result = (oldB * 2 - 1);
    }
  }
  oldA = newA;
  oldB = newB;
  return result;
}
