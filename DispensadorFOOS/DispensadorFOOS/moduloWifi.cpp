#include "moduloWifi.h"
//String dataString="";
int cantidadRedes=0;
String dataString="";

void redesDisponibles()
{

}
void comandoAtRedesDisponibles()
{
	Serial1.write("AT+CWLAP");
	Serial1.write("\r\n");
	delay(1000);
}

//char data = Serial1.read();
//dataString += data;
//if (data == ')')
//{
//	cantidadRedes += 1;
//	dataString.remove(0, (dataString.indexOf('"') + 1));
//	dataString.remove((dataString.indexOf('-') - 2), dataString.length());
//	Serial.println(dataString);
//	//Serial.print(cantidadRedes);
//	dataString = "";
//}