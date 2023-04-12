#include <WiFi.h>
#include <WiFiUDP.h>

const char *ssid = "yourSSID";
const char *password = "password";
const int udpPort = 3333;

int step_pin = 25; //13
int dir_pin = 26; //12
int relay_pin = 27; //11

WiFiUDP Udp;

void setup()
{
  pinMode(step_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(relay_pin, OUTPUT);
  digitalWrite(dir_pin, HIGH);
  digitalWrite(relay_pin, LOW);

  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  Udp.begin(udpPort);
}

void loop()
{
  int packetSize = Udp.parsePacket();
  if (packetSize) //パケットを受信したとき
  {
    char buffer[255];
    int len = Udp.read(buffer, 255);
    if (len > 0)
    {
      buffer[len] = '\0';
    }
    Serial.printf("UDP packet contents: %s\n", buffer);

    int direction = atoi(buffer);
    Serial.print("direction is\n");
    Serial.print(direction);
    Serial.print("\n");
    
    char *commaPosition = strchr(buffer, ',');
    int steps = atoi(commaPosition + 1);

    Serial.print("steps are\n");
    Serial.print(steps);
    Serial.print("\n");
    
    spinMotor(direction, steps);
  }
}

void spinMotor(int direction, int num)
{
  digitalWrite(relay_pin, HIGH);
  if (direction == 0)
  {
    digitalWrite(dir_pin, LOW);
  }
  else
  {
    digitalWrite(dir_pin, HIGH);
  }

  for (int i = 0; i < num; i++)
  {
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(step_pin, LOW);
    delayMicroseconds(1000);
  }
  digitalWrite(relay_pin, LOW);
}
