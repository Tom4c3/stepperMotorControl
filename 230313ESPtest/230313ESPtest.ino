int LED_Pin = 5; 
 
void setup() {
  pinMode(LED_Pin,OUTPUT); 
} 
 
void loop() {
  digitalWrite(LED_Pin,HIGH);
  delay(300);
  digitalWrite(LED_Pin,LOW);
  delay(300);
}
