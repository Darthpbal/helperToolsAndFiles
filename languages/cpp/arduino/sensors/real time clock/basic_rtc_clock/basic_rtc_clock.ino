#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
RTC_DS3231 rtc;
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2);
char daysOfTheWeek[7][5] = {"Sun",
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

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
//  Serial.println('\n');
  if (!rtc.begin()) {
//    Serial.println("RTC not connected");
    while (1);
  }
//  else if (rtc.lostPower()) {
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
//  }
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello World!");
  delay(3000);
  lcd.noBacklight();
  lcd.clear();
  delay(200);
  lcd.backlight();
}

void loop() {
  lcd.clear();
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();

  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  lcd.print(" ");
  lcd.print(months[now.month() - 1]);
  lcd.print(" ");
  lcd.print(now.day());
  lcd.print(", ");
  lcd.print(now.year());
  lcd.setCursor(0,1);
  if(now.hour() > 12) lcd.print(now.hour() - 12);
  else lcd.print(now.hour());
  lcd.print(':');
  if(now.minute() < 10) lcd.print('0');
  lcd.print(now.minute());
//  lcd.print(':');
//  if(now.second() < 10) lcd.print('0');
//  lcd.print(now.second());
  if(now.hour() > 11) lcd.print("pm");
  else lcd.print("am");
  

  delay(3000);
}
