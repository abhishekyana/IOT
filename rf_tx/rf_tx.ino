#include<VirtualWire.h>
#include <dht.h>

#define dht_apin A0

dht DHT;

//String controller="";
char humidity[16];
char temperature[16];
char full[32];
void setup() 
{
Serial.begin(9600);
pinMode(13,OUTPUT);
vw_set_ptt_inverted(true); //
vw_set_tx_pin(12);
vw_setup(1000);// speed of data transfer Kbps
}

void loop()
{
char full[32];
DHT.read11(dht_apin);
String(DHT.humidity).substring(0,5).toCharArray(humidity,16);
String(DHT.temperature).substring(0,5).toCharArray(temperature,16);
strcat(full,humidity);
strcat(full,temperature);
Serial.println(full);
vw_send((uint8_t *)full, strlen(full));
vw_wait_tx(); // Wait until the whole message is gone
delay(5000);
}
