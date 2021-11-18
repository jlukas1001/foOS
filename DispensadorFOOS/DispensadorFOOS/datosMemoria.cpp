#include <EEPROM.h>
#include "horarioComidas.h"
#include "datosMemoria.h"
#include "tactil.h"

void guardarDatos(int cantidad, int vecesDiarias, HoraiosComidas* comida[5])
{
	for (int i = 0; i < vecesDiarias; i++)
	{
		EEPROM.write(i, comida[i + 1]->mostrarHora());
		EEPROM.write(i+vecesDiarias, comida[i + 1]->mostrarMinuto());
	}
	EEPROM.write(30, cantidad); // SE GUARDA EN LA DIRECCION 30 EPPROM LA CANTIDAD DE ALIMENTO
	EEPROM.write(31, vecesDiarias); // SE GUARDA EN LA DIRECCION 31 EPPROM LA CANTIDAD DE ALIMENTO
}

void leerDatos(HoraiosComidas* comidaEeprom[5])
{
	for (int i = 0; i < EEPROM.read(31); i++)
	{
		Serial.println(EEPROM.read(i));
		Serial.println(EEPROM.read(i+EEPROM.read(31)));
		comidaEeprom[i+1] = new HoraiosComidas(EEPROM.read(i), EEPROM.read(i + EEPROM.read(31)));
	}

}