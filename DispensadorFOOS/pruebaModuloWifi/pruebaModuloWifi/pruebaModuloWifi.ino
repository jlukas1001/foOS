#include "ESP8266.h"

const char* SSID = "FibraETB_GarciaOsorio";
const char* PASSWORD = "POURTOUS2212191";

ESP8266 wifi(Serial1);

void setup()
{
	Serial.begin(115200);
	Serial1.begin(115200);

	wifi.restart();
	delay(500);

	wifi.setOprToSoftAP();
	wifi.createTCP("192.168.0.1", 80);


}
void loop()
{
	if (Serial1.available())
	{
		Serial.print((char)Serial1.read());
	}
}