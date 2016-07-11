int alt;
int altArrSize = 1000000000;
int sampleTime = 1000;
int altArray[altArrSize];
bool fwdRev = true;

void loop(){
	for(int i = 0; i < altArrSize; i++){
		if(alt == altArray[i]){
			fwdRev = (fwdRev)? driveFwd(i) : driveRev(i);
			fwdRev = (fwdRev)? driveFwd(i) : driveRev(i);
		}
	}
}







bool driveFwd(int motorNum){
	//do motor stuff
	delay(sampleTime);
	return false; // to signal next drive is reverse
}

bool driveRev(int motorNum){
	//do motor stuff
	return true; // signal next drive is forward
}
