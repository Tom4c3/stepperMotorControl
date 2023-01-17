int step_pin = 13;
int dir_pin = 12;
int relay_pin = 11;

void setup()
{
  pinMode(step_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(relay_pin, OUTPUT);
  digitalWrite(dir_pin, HIGH);
  digitalWrite(relay_pin, LOW);

  Serial.begin( 9600 );
}
 
void loop() 
{
  //0がモーター無い側向き
  spinMotor(0,500);
  delay(1000);

  //モーター側に移動
  spinMotor(1,500);
  delay(1000);

}

void spinMotor(int direction, int num){
  digitalWrite(relay_pin, HIGH);
  if(direction == 0){
    digitalWrite(dir_pin, LOW);
  }else{
    digitalWrite(dir_pin, HIGH);
  }

  for(int i=0;i<num;i++)
  {
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(step_pin, LOW);
    delayMicroseconds(1000);
  }
  digitalWrite(relay_pin, LOW);
} 
