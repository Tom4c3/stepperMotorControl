#include <Uduino_Wifi.h>
Uduino_Wifi uduino("ESP32");

// Servo
#if defined(ESP32)
// Install esp32servo library => Sketch>Include Library>Manager Libraries>Esp32Servo
#include <ESP32Servo.h>
#else
#include <Servo.h>
#endif

#define MAXSERVOS 8

#define LED_PIN 5
int valueOne;

void setup() {

    Serial.begin(115200);
#if defined (__AVR_ATmega32U4__) // Leonardo
  while (!Serial) {}
#elif defined(__PIC32MX__)
  delay(1000);
#endif

  uduino.setPort(4223);   // default 4222
 
 // Optional functions,  to add BEFORE connectWifi(...)

 uduino.addCommand("onLED", onLED);
 uduino.addCommand("offLED", offLED);
  
  uduino.connectWifi("SSID", "Pass");

  pinMode(LED_PIN, OUTPUT);


}

void loop() {
  uduino.update();
}

void onLED(){
//  int parameters = uduino.getNumberOfParameters(); //
//  if(parameters > 0) {
//  valueOne = uduino.charToInt(uduino.getParameter(0)); // returns 255
//}
  digitalWrite(LED_PIN, 1);
}

void offLED(){
//  int parameters = uduino.getNumberOfParameters(); //
//  if(parameters > 0) {
//  valueOne = uduino.charToInt(uduino.getParameter(0)); // returns 0
//}
  digitalWrite(LED_PIN, 0);
}
