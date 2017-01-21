

void setup() {
    Serial.begin(9600);
    Serial.println("Starting up");


    //check GPS operation at startup for 10 sec
    Serial.println("Checking GPS...");
    char gpsPrefix;
    int timeout = 10000;//in millisec.
    unsigned long startTime = millis();//sample the time when we start waiting for the GPS
    while( ((millis() - startTime) < timeout) && (gpsPrefix != '$') ){//while timeout hasn't happened and char isn't seen from GPS
        if(Serial.available()) gpsPrefix = Serial.peek();
    }
    if(gpsPrefix == '$') Serial.println("GPS ready!!!");
    else Serial.println("GPS error");
    //end og GPS check

    Serial.println("Ending startup");
    delay(500);
}


void loop() {
    Serial.println("Start loop");
    int gpsHeaderSize = 8;
    char gpsRAW[100], gpsHeader[gpsHeaderSize];
    readGPS(gpsRAW);
    //
    // //transfer the front portion of gpsRAW into the header to check it.
    // for(int i = 0; i < gpsHeaderSize; i++){
    //     gpsHeader[i] = gpsRAW[i];
    // }
    // gpsHeader[gpsHeaderSize] = '\0';
    //
    //
    // if(gpsHeader == "$GPRMC,") Serial.print(gpsRAW);
    // delay(500);
}


void readGPS(char* gps){
    int gpsCharNum = 0;
    do{
        while(!Serial.available());
        gps[gpsCharNum] = Serial.read();
        gpsCharNum++;
    }
    while(gps[gpsCharNum - 1] != '\r');
    gps[gpsCharNum] = '\0';
}






/*example ultimate GPS R3 output

$GPRMC,100607.000,A,3324.6004,N,11201.7388,W,0.02,258.10,170117,,,D*77
$GPVTG,258.10,T,,M,0.02,N,0.04,K,D*30
$GPGGA,100608.000,3324.6004,N,11201.7388,W,2,08,0.98,342.7,M,-26.7,M,0000,0000*54
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPRMC,100608.000,A,3324.6004,N,11201.7388,W,0.04,329.09,170117,,,D*71
$GPVTG,329.09,T,,M,0.04,N,0.07,K,D*3A
$GPGGA,100609.000,3324.6004,N,11201.7388,W,2,08,0.98,342.7,M,-26.7,M,0000,0000*55
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPGSV,3,1,11,12,76,196,45,05,56,134,34,02,55,035,14,25,52,307,23*75
$GPGSV,3,2,11,51,50,171,43,29,27,303,24,20,23,193,37,06,17,050,21*7B
$GPGSV,3,3,11,24,09,208,20,19,08,094,27,31,04,318,19*42
$GPRMC,100609.000,A,3324.6004,N,11201.7388,W,0.02,324.89,170117,,,D*73
$GPVTG,324.89,T,,M,0.02,N,0.04,K,D*3A
$GPGGA,100610.000,3324.6005,N,11201.7390,W,2,08,0.98,342.6,M,-26.7,M,0000,0000*54
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPRMC,100610.000,A,3324.6005,N,11201.7390,W,0.02,330.39,170117,,,D*7D
$GPVTG,330.39,T,,M,0.02,N,0.03,K,D*33
$GPGGA,100611.000,3324.6007,N,11201.7391,W,2,08,0.98,342.4,M,-26.7,M,0000,0000*54
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPRMC,100611.000,A,3324.6007,N,11201.7391,W,0.03,346.63,170117,,,D*70
$GPVTG,346.63,T,,M,0.03,N,0.06,K,D*39
$GPGGA,100612.000,3324.6011,N,11201.7394,W,2,08,0.98,342.3,M,-26.7,M,0000,0000*52
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPRMC,100612.000,A,3324.6011,N,11201.7394,W,0.06,327.00,170117,,,D*76
$GPVTG,327.00,T,,M,0.06,N,0.11,K,D*38
$GPGGA,100613.000,3324.6012,N,11201.7396,W,2,08,0.98,342.2,M,-26.7,M,0000,0000*53
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPRMC,100613.000,A,3324.6012,N,11201.7396,W,0.03,297.95,170117,,,D*75
$GPVTG,297.95,T,,M,0.03,N,0.06,K,D*3D
$GPGGA,100614.000,3324.6013,N,11201.7397,W,2,08,0.98,342.0,M,-26.7,M,0000,0000*56
$GPGSA,A,3,19,05,24,12,25,02,20,29,,,,,1.60,0.98,1.26*05
$GPGSV,3,1,11,12,76,195,45,05,56,134,35,02,55,035,13,25,52,307,23*70
$GPGSV,3,2,11,51,50,171,43,29,27,303,25,20,23,193,38,06,17,050,20*74
$GPGSV,3,3,11,24,09,208,20,19,08,094,27,31,04,318,19*42
$GPRMC,100614.000,A,3324.6013,N,11201.7397,W,0.00,334.19,170117,,,D*7D
$GPVTG,334.19,T,,M,0.00,N,0.01,K,D*35

*/
