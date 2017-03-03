/*
This is a demo program for the Sparkfun logomatic which displays how the
board operates in general UART mode, which is by collecting UART data to
fill one 512 byte (512 letters) buffer, and then emptying that buffer
into the sd card. While logging that buffer data to the SD card, the system
switches to filling the second buffer in the logomatic. Emptying these two
buffers is shown in the stat0 and stat1 leds on the board.


This program counts up a counter in the loop and prints that count to the
screen. The reason why the count algorithm is weird is because I was attempting
to print how many characters were transmitted to the logomatic. So starting
count at 0 and transmitting "0" would be undesirable because "0" is a character,
so you've actually transmitted 1 character. Things get weirder after you pass
transmitting 9 characters as well because then after every transmission, every
number takes up two digits and so should count up the character count by two, and
likewise for numbers over 99

The purpose of this weirdness was to measure how many characters are logged in
each burst because I noticed that it doesn't log until some minimum amount of
data has been transmitted to the board. So the way to read the result file is
say something like the number 110 is transmitted, that means that after
transmitting the "0" that number is how many characters so far. But the first "1"
would be the 108th character. This means that if at the end of the file you see
a string of 3 digit numbers and the final number is 2 digits, then you know
that transmission was cutoff, but you can still use the pattern to backtrack to
get the character count number.




The logomatic is wired up as follows
logomatic   |||     controller
batt        |||     5V
gnd         |||     gnd
RXI0        |||     tx  (UART TTL)
*/




int charCount = 0;//this is global because I want to keep track of the same count after the loop restarts


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}




void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  if(charCount > 98) charCount += 3;
  else if(charCount > 8) charCount += 2;
  else charCount++;
  Serial.print(charCount);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
}
