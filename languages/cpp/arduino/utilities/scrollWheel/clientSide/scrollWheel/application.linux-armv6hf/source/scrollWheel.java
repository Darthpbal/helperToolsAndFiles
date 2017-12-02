import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 
import java.awt.Robot; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class scrollWheel extends PApplet {

//https://docs.oracle.com/javase/6/docs/api/java/awt/Robot.html#mousePress(int).html



Robot rbt;

Serial myPort;
String scrollDir = "";
boolean trigger = true;

public void setup(){
  //size(200, 200);
  myPort = new Serial(this, "/dev/ttyUSB0", 9600);
  
  try {
    rbt = new Robot();
  } catch(Exception e) {
    e.printStackTrace();
  }
}


public void draw(){
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
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "scrollWheel" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
