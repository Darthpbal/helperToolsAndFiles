//an example of using aref pin and otherwise getting accurate analog signal readings.

/*
the problem with just straight analog reading, is that when calculated to voltage
and then compared to a multimeter reading, you might get something around 0.02V off.

Upon investigation, I realized that the power rail used for powering a voltage
divider to be measured was sitting at 4.97V instead of a solid 5V. And in my calculation
the assumed railVoltage is 5V. However when backcalculating what the ADC value for
4.97V on a 5V maximum scale was ~1016, but when reading the raw value I'd see 1023, the
maximum ADC value. This means that for "calibration" one must measure the rail voltage
and incorperate that into the conversion to voltage rather than an assumed prestine
5V.
the 3.3V rail seems to be stable, so it doesn't have the same behavior. Note that
the use of the AREF pin would not fix this problem of having inaccurate results from
the 5V power rail actually sitting at 4.97V because the system appears to simply be scaling
the 1023 to be from 0V to whatever the power rail is sitting at. So it's like an automatic
analog reference, but the problem occurs when 5V is used in the coversion calculation.

A safer method of changing scaled from 5V to something like 3.3V is displayed below
the loop function. However, less ADC divisions are used for measurement so it's
the same resolution as the 5V scale (still 4.9mV per div) and the only way to change
that resolution is to use analogReference and either use the AREF pin or use one of the
internal references.
*/

void setup() {
  Serial.begin(9600);//***AREF CAN BE DANGEROUS!!!!! THINK!!!!*******
   analogReference (EXTERNAL) ;//upload this code before connecting to AREF. Otherwise it's dangerous.
                                //This will change the scale of 1023 from the ~5V rail to whatever is in AREF


}

void loop() {
  //These two lines are just for the analogReference example
  uint16_t outputVoltage = analogRead(0);//assuming the power rail is sitting at 3.3V
  outputVoltage += analogRead(1);
  outputVoltage += analogRead(2);
  Serial.println(outputVoltage);


}




// float railVoltage = 4.97;//measure the 5V power rail and put that value here, if not using the analogReference function.
// outputVoltage = railVoltage / analogRead(1) * analogRead(0);//no analogReference required.//where 0 is the subject, and 1 is the reference. Works for scaling for 5V and 3.3V systems
// Serial.println(analogRead(0));//subject to read
// Serial.println(analogRead(1));//reference voltage. So if
// Serial.println(outputVoltage);
