#include <SoftwareSerial.h>
#include <Wire.h>
#include <MS5xxx.h>
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include "RTClib.h"


SoftwareSerial btSerial(6, 5); //rx, tx


//temp
OneWire  thermometer(4);  // 4.7K pullup resistor is necessary
byte tempAddr[8];


// humidity
#define DHTPIN 7     // what digital pin we're connected to
DHT humidity(DHTPIN, DHT11);


const int photocellPin = 0;


MS5xxx altimeter(&Wire);


// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);
byte frame = 0; // counter variable for choosing what data to display


RTC_DS3231 rtc;
char daysOfTheWeek[7][5] = {
                            "Sun",
                            "Mon",
                            "Tues",
                            "Wed",
                            "Thur",
                            "Fri",
                            "Sat"
                           };
char months[12][4] = {
                      "Jan",
                      "Feb",
                      "Mar",
                      "Apr",
                      "May",
                      "Jun",
                      "Jul",
                      "Aug",
                      "Sep",
                      "Oct",
                      "Nov",
                      "Dec"
                    };


// tracking when things happen
unsigned long hTime = 0;
int hDelay = 1000;
unsigned long peakTime = 0,
transmitTime = 0;

// binary indication of whether or not the washer/dryer is shaking
bool active = false;

//used for switching between vibration and atmospheric measurement.
bool accelMode = false;





#include <Adafruit_ADS1015.h>

Adafruit_ADS1015 adc11Bit; //construct ADC amplifier

// 3 acceleration axes
const int az = 0,
          ay = 1,
          ax = 2;

// used for reading instantaneous slope
int16_t lastAdcVal = 0;



void setup() {
    Serial.begin(9600);
    btSerial.begin(9600);

  
    // real time clock.
//    if (! rtc.begin()) {
        Serial.println("Couldn't find RTC");
//        while (1);
//    }
//    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));


    

    transmitTime = millis();


    if(altimeter.connect()>0) {
        Serial.println("Error connecting pressure sensor...");
        delay(500);
//        setup();
    }

//    adc11Bit.setGain(GAIN_TWO); // mind the safety range if the vibration sensor is changed
//    adc11Bit.begin();
//    int16_t adcVal = adc11Bit.readADC_SingleEnded(0);
//    adcVal += adc11Bit.readADC_SingleEnded(1);
//    adcVal += adc11Bit.readADC_SingleEnded(2);
//    lastAdcVal = adcVal;//get starting value to avoid a spike at startup
    pinMode(13, OUTPUT); // status led

    // start thermometer
    if(!thermometer.search(tempAddr)) Serial.println(F("temp connection error"));

    //start humidity
    humidity.begin();

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
}

void loop() {
    String line = "";
    // Receive bluetooth data
    if (btSerial.available()){
      char c;
        do{
            c = btSerial.read();
            Serial.write(c);
            if(c == '#') Serial.println();
            else if(c == '~') accelMode = false;
            else if(c == '`') accelMode = true;
            digitalWrite(13, LOW);
        }
        while(btSerial.available());
    }

if(accelMode == false){
    // temperature
    byte data[12];
    thermometer.reset();
    thermometer.select(tempAddr);
    thermometer.write(0x44, 1);
    thermometer.reset();
    thermometer.select(tempAddr);
    thermometer.write(0xBE);

    for (int i = 0; i < 9; i++) {           // we need 9 bytes
      data[i] = thermometer.read();
    }

    int16_t raw = (data[1] << 8) | data[0];
    float tempDs18b20 = (float)(raw / 16.0) * 1.8 + 32.0;
    line += tempDs18b20;
    line += "F, ";
    // end temp


    // Humidity
    float humidVal;
    if( ( (millis() - hTime) > hDelay) || (millis() < hDelay) ){
        humidVal = humidity.readHumidity();
        if ( isnan(humidVal) ) {
            Serial.println("Humidity error");
            return;
        }
    }
    line += humidVal;
    line += "%, ";
    // end humidity

    // pressure
    altimeter.ReadProm();
    altimeter.Readout();
    float tempAlt = altimeter.GetTemp();
    float pressAlt = altimeter.GetPres();

    line += tempAlt;
    line += ", ";
    line += pressAlt;
    line += ", ";
    // end pressure

    // light detection
    int photocellReading = analogRead(photocellPin);
    line += photocellReading;
    line += ", ";
    if (photocellReading < 10) {
        line += "Dark";
    } else if (photocellReading < 260) {
        line += "Dim";
    } else if (photocellReading < 510) {
        line += "Light";
    } else if (photocellReading < 760) {
        line += "Bright";
    } else {
        line += "Very bright";
    }
    line += ", ";
    if(photocellReading < 200) lcd.noBacklight();
    else lcd.backlight();
    // end light detection

    // time
    DateTime now = rtc.now();
    line += now.month();
    line += '/';
    line += now.day();
    line += '/';
    line += now.year();
    line += ", ";

    line += now.hour();
    line += ':';
    line += now.minute();
    line += ':';
    line += now.second();
    // end time



    if((now.second() % 10) == 0) {
        frame++;
        if(frame > 2) frame = 0;
    }
    if((now.second() % 2) == 0){
        if(frame == 0) {// date time frame w/light
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
            lcd.print(' ');
            lcd.print(months[now.month()]);
            lcd.print(' ');
            lcd.print(now.day());


            lcd.setCursor(12,0);
            lcd.print(photocellReading);


            lcd.setCursor(0,1);
            if(now.hour() > 12) lcd.print(now.hour() - 12);
            else lcd.print(now.hour());
            lcd.print(':');

            if(now.minute() < 10) lcd.print('0');
            lcd.print(now.minute());

            if(now.hour() > 12) lcd.print("pm");
            else lcd.print("am");



            lcd.setCursor(8,1);
            if (photocellReading < 10) {
                lcd.print("Dark");
            } else if (photocellReading < 260) {
                lcd.print("Dim");
            } else if (photocellReading < 510) {
                lcd.print("Light");
            } else if (photocellReading < 760) {
                lcd.print("Bright");
            } else {
                lcd.print("Very bright");
            }
        }

        if(frame == 1) { // temperature frame
            lcd.clear();
            lcd.setCursor(0,0);

            lcd.print(tempDs18b20);
            lcd.print("F |");

            lcd.print(tempAlt * 0.01 * 1.8 + 32);
            lcd.print("F");

            lcd.setCursor(0,1);

            lcd.print(humidity.readTemperature(true));
            lcd.print("F");
        }
        if(frame == 2) { // humidity
            lcd.clear();
            lcd.setCursor(0,0);

            lcd.print(humidVal);
            lcd.print("% ");
            lcd.print(tempDs18b20);
            lcd.print("F");

            lcd.setCursor(0,1);
            lcd.print(humidity.computeHeatIndex(tempDs18b20, humidVal));
            lcd.print("F");

            lcd.setCursor(8,1);
            lcd.print(pressAlt / 101325.0);
            lcd.print("atm");
        }

    }

    line += '\n';
    Serial.print(line);

    if( (millis() - transmitTime) >= 2000){ //transmit status every 2 second.
        btSerial.print(line);
        transmitTime = millis();
    }

    delay(500);
}
else{
    int16_t adcVal = adc11Bit.readADC_SingleEnded(0);
    adcVal += adc11Bit.readADC_SingleEnded(1);
    adcVal += adc11Bit.readADC_SingleEnded(2);//aggregate vibrations  in all 3 axes
//    int16_t adcVal = analogRead(A0);
//    adcVal = analogRead(A1);
//    adcVal = analogRead(A2);

    Serial.print(abs(adcVal - lastAdcVal));//print vibration value
    Serial.println();

    if( abs(adcVal - lastAdcVal) > 4){//threshold, positive or negative spike magnitude
      if( (millis() - peakTime) < 15){//high frequency detection, if the detected thresholds have a short period, i.e. high frequency vibration
        digitalWrite(13, HIGH);
        active = true; // large magnitude and high frequency signal detected
      }
      peakTime = millis();
    }
    else{
      if( (millis() - peakTime) > 30000){// not shaking timeout 30 sec, washing machines have fakeout times
        digitalWrite(13, LOW);
        active = false;
      }
    }

    if( (millis() - transmitTime) >= 2000){ //transmit status every 2 second.
      if(active) btSerial.print("ACTIVE");
      else btSerial.print("INACTIVE");

      btSerial.print(',');
      btSerial.print(adcVal - lastAdcVal);

      transmitTime = millis();
    }

    lastAdcVal = adcVal;//update vibration value
}
}




/*
GAIN_TWOTHIRDS   2/3x gain +/- 6.144V  1 bit = 3mV    (default)
GAIN_ONE         1x gain   +/- 4.096V  1 bit = 2mV
GAIN_TWO         2x gain   +/- 2.048V  1 bit = 1mV
GAIN_FOUR        4x gain   +/- 1.024V  1 bit = 0.5mV
GAIN_EIGHT       8x gain   +/- 0.512V  1 bit = 0.25mV
GAIN_SIXTEEN     16x gain  +/- 0.256V  1 bit = 0.125mV
*/
//float getVoltageWGain(int channel, adsGain_t gain, bool single0_diff1){
//    int16_t adcVal = 0;
//
//    adc11Bit.setGain(gain);
//
//    //read from the desired channel in single ended or differential
//    //differential 0-1 is channel 0 and differential 2-3 is channel 1
//    if(!single0_diff1){
//        adcVal = adc11Bit.readADC_SingleEnded(channel);
//    }
//    else {
//        if(channel % 2 == 0)adcVal = adc11Bit.readADC_Differential_0_1();
//        else adcVal = adc11Bit.readADC_Differential_2_3();
//    }
//
//    //convert adc value to voltage using appropriate multiplier based on gain
//    switch(gain){
//        case GAIN_TWOTHIRDS:
//            return adcVal * 3.0 / 1000;
//        break;
//        case GAIN_ONE:
//            return adcVal * 2.0 / 1000;
//        break;
//        case GAIN_TWO:
//            return adcVal * 1.0 / 1000;
//        break;
//        case GAIN_FOUR:
//            return adcVal * 0.5 / 1000;
//        break;
//        case GAIN_EIGHT:
//            return adcVal * 0.25 / 1000;
//        break;
//        case GAIN_SIXTEEN:
//            return adcVal * 0.125 / 1000;
//        break;
//        default:
//            return 0.0;
//        break;
//    }
//}
