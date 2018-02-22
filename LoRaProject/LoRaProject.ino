#include <dht.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include<SoftwareSerial.h>

#define ONE_WIRE_BUS 2 //digital pin for onewirebus 2
#define dht_apin A0 // Analog Pin sensor is connected to DHT

/* Create object named bt of the class SoftwareSerial */ 
//SoftwareSerial bt(0,1); /* (Rx,Tx) */  

dht DHT;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup()
{
Serial.begin(9600);
//bt.begin(9600);
//bt.write("Bluetooth Started");
delay(500); //Delay to let system boot
Serial.println("Program Started...\n\n");
sensors.begin();
delay(1000); //for stability
}
 
void loop()
{
DHT.read11(dht_apin);
sensors.requestTemperatures();
Serial.print("RH = ");
Serial.print(DHT.humidity);
Serial.print("%; ");
Serial.print("Temp = ");
Serial.print(DHT.temperature);
Serial.print("C; ");
Serial.print("Soil Temp: ");
Serial.print(sensors.getTempCByIndex(0));
Serial.println("C; ");
delay(3000);//5000msec for every reading. min=2000msec
} 







//char data = 0;            //Variable for storing received data
//void setup()
//{
//    Serial.begin(9600);   //Sets the baud for serial data transmission                               
//    pinMode(13, OUTPUT);  //Sets digital pin 13 as output pin
//}
//void loop()
//{
//   if(Serial.available() > 0)      // Send data only when you receive data:
//   {
//      data = Serial.read();        //Read the incoming data & store into data
//      Serial.print(data);          //Print Value inside data in Serial monitor
//      Serial.print("\n");        
//      if(data == '1')              // Checks whether value of data is equal to 1
//         digitalWrite(13, HIGH);   //If value is 1 then LED turns ON
//      else if(data == '0')         //  Checks whether value of data is equal to 0
//         digitalWrite(13, LOW);    //If value is 0 then LED turns OFF
//   }
//}
