void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("$GPGSA,A,1,,,,,,,,,,,,,0.0,0.0,0.0*30\r\n");
  delay(200);

  Serial.print("$GPGSV,1,1,03,23,00,000,44,01,00,000,43,03,00,000,41*4B\r\n");
  delay(200);

  Serial.print("$GPRMC,115949.000,V,0000.0000,N,00000.0000,E,000.0,000.0,280606,,,N*7D\r\n");
  delay(200);

  Serial.print("$GPVTG,000.0,T,,M,000.0,N,000.0,K,N*02\r\n");
  delay(200);

  Serial.print("$GPGGA,115950.000,0000.0000,N,00000.0000,E,0,00,0.0,0.0,M,0.0,M,,0000*64\r\n");
  delay(200);
  
}




