import processing.serial.*;

Serial myPort; //creates object from serial class

void setup(){
  size(200,200);
  String portName = "COM4";
  myPort = new Serial(this, portName, 9600);
}

void draw(){
  if(mousePressed == true){
    myPort.write('1');
    println("1");
  } else{
    myPort.write('0');
    println("0");
  }
}
