#include<VirtualWire.h>
void setup()
{
Serial.begin(9600);
Serial.println("Program Started Using RF Module ..");
vw_set_ptt_inverted(true); // Required for DR3100
vw_set_rx_pin(12);
vw_setup(1000); // Bits per sec
vw_rx_start(); // Start the receiver PLL running
}
void loop()
{
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

if (vw_get_message(buf, &buflen)) // Non-blocking
{
Serial.print("Humidity :");
for(int i=2;i<5;i++){Serial.print(char(buf[i]));}
Serial.print("% ;  ");
Serial.print("Temperature :");
for(int i=8;i<10;i++){Serial.print(char(buf[i]));}
Serial.println("C ; ");
} 
}
