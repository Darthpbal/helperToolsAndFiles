import processing.serial.*;
import java.awt.Robot;

Robot rbt;

Serial myPort;
String scrollDir = "";
boolean trigger = true;

void setup(){
  //size(200, 200);
  myPort = new Serial(this, "/dev/ttyUSB0", 9600);
  
  try {
    rbt = new Robot();
  } catch(Exception e) {
    e.printStackTrace();
  }
}


void draw(){
  if(trigger) {
    surface.setVisible(false);
    trigger = !trigger;
  }
  
  if ( myPort.available() > 0) {  // If data is available,
    scrollDir = myPort.readString();         // read it and store it in val
    if(scrollDir.equals("up")) {
      rbt.mouseWheel(-1);
    }
    else if(scrollDir.equals("dn")) {
      rbt.mouseWheel(1);
    }
  }
}