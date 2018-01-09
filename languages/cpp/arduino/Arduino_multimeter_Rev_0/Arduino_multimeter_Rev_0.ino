/*
Here is my arduino multimeter code. First I want to get out of the way mhy expectations for this project. Here are all of the things I want to be able to
read about the circuit in question. 
1.Voltage (within safe arduino functioning range)
2.Current (either through the arduino, or through calculation from voltage)
3.Continuity
4.Resistance
5.Capacitance (this is an optional implementation as I probably wont udnerstand the code well enough to include.)

For my earlier versions I'll work on the program structure choosing options through serial commands.
*/

int command = 0; //command to be used to store a users input.

void setup(){
  Serial.begin(9600);
  while(!Serial){
    ;
  }
}

void loop(){
  
}
