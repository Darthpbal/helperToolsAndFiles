void setup() {
  Serial.begin(9600);
  Serial.println("startup finished...");
}


void loop() {
  int a, b;
  char op;
  //Gather first number//
  Serial.println("DoMath! (2 nums at a time, operators available +, -, *, /, %)");//prompt user
  while(!Serial.available()) delay(500);//wait for incoming data
  a = Serial.parseInt();//parse first valid int
  op = Serial.peek();//store next char in op for operator without purging from buffer
  b = Serial.parseInt();//skips the op character since it isn't a valid integer
  while(Serial.read() != -1) Serial.read();//clear remaining chars from buffer



  //start showing results
  Serial.print(a);
  Serial.print(op);
  Serial.print(b);
  Serial.print("=");


  //handle math
  switch(op){
    case '+':
      Serial.println(a + b);
      break;
    case '-':
      Serial.println(a - b);
      break;
    case '*':
      Serial.println(a * b);
      break;
    case '/':
      Serial.println(a / b);
      break;
    case '%':
      Serial.println(a % b);
      break;
    default:
      Serial.println("...\nUnknown function... Try again, loser!\n");
  }
}
