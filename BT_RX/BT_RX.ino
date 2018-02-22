#include <SoftwareSerial.h>0
SoftwareSerial BTserial(4, 5); // RX | TX
char c = ' ';

void setup() {
  Serial.begin(9600);
  Serial.print("StaRTED");
  BTserial.begin(38400);
  }

void loop() {
  if(BTserial.available())
  {
    c=BTserial.read();
    Serial.write(c);
  }
  
  if(Serial.available())
  {
    c=Serial.read();
    BTserial.write(c);
  }
}
