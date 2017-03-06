#include <Wire.h>
#include <Adafruit_Sensor.h> 
#include <Adafruit_LSM303_U.h> //IMU (accel, mag)
#include <Adafruit_BMP085_U.h> //IMU (BMP)
#include <Adafruit_L3GD20_U.h> //IMU (Gryo)
#include <Adafruit_Simple_AHRS.h> //for calculating the roll, pitchm and yaw

char delim = ',';

// Create sensor instances.
Adafruit_LSM303_Accel_Unified A (30301); //accelerometer
Adafruit_LSM303_Mag_Unified   M (30302); //Magnetometer
Adafruit_BMP085_Unified       B (18001); //Pressure/temp
Adafruit_L3GD20_Unified       G  (20);   //Gyro

// Create simple AHRS algorithm using the above sensors.
Adafruit_Simple_AHRS          ahrs(&A, &M);

float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA; 

/////////////////////////////////////////////////////////////////

void setup(){
  Serial.flush(); // I tried using a flush function to clear out the excess data at the begining
  Serial.begin(115200); //sets baud rate
  Serial.flush(); // flush also here but I havn't seen any change
  
  Serial.println(); //just extra lines to separate old data from new
  Serial.println("AinsleyTano was here");
  Serial.println();
  Serial.println("roll, pitch, heading, accelx, accely, accelz, magx, magy, magz, gyrox, gyroy, gyroz, pres, alt, temp,");
  
  // Initializes the sensors
  A.begin();
  M.begin();
  B.begin();
  G.begin();
}

//////////////////////////////////////////////////////////////////

void loop(void){ // why is this void?

  sensors_vec_t   orientation;

  // Uses the AHRS function to get the current orientation (roll, pitch, heading/yaw) and prints data
  if (ahrs.getOrientation(&orientation))
  {
    Serial.print(orientation.roll);
    Serial.print(delim);
    Serial.print(orientation.pitch);
    Serial.print(delim);
    Serial.print(orientation.heading);
    Serial.print(delim);  
  }

//raw sensor datar 
sensors_event_t A_event;
sensors_event_t M_event;
sensors_event_t G_event;
sensors_event_t B_event;

//gets a sensor event from each sensor
A.getEvent(&A_event);
M.getEvent(&M_event);
G.getEvent(&G_event);

//Display Raw Sensor Information: Accel, Mag, Gyro
Serial.print(A_event.acceleration.x); Serial.print(delim);
Serial.print(A_event.acceleration.y); Serial.print(delim);
Serial.print(A_event.acceleration.z); Serial.print(delim);
Serial.print(M_event.magnetic.x);     Serial.print(delim);
Serial.print(M_event.magnetic.y);     Serial.print(delim);
Serial.print(M_event.magnetic.z);     Serial.print(delim);
Serial.print(G_event.gyro.x);         Serial.print(delim);
Serial.print(G_event.gyro.y);         Serial.print(delim);
Serial.print(G_event.gyro.z);         Serial.print(delim);

sensors_event_t bmp_event;
  B.getEvent(&B_event);
  Serial.print(B_event.pressure);     Serial.print(delim); //prints pressure
  if (B_event.pressure)
  {
    // Get temperature
    float temperature;
    B.getTemperature(&temperature);
    //Convert atmospheric pressure, SLP and temp to altitude (get altitude)
    Serial.print(B.pressureToAltitude(seaLevelPressure,
                                        B_event.pressure,
                                        temperature)); //prints altitude
    Serial.print(delim);
    Serial.println(temperature);
    
  }
} 

  
