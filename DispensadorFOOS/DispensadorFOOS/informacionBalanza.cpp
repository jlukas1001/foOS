#include "informacionBalanza.h"

#include <Servo.h>
#include "HX711.h"

#define DOUT  A8
#define CLK  A9

Servo dispensador;

HX711 balanza(DOUT, CLK);

void inicioBalanza()
{
	Serial.print("Lectura del valor del ADC Balanza:  ");
	Serial.println(balanza.read());
	balanza.set_scale(941.655); // Establecemos la escala
	balanza.tare(20);  //El peso actual es considerado Tara.
	dispensador.attach(13);
	dispensador.write(98);
	delay(500);
	dispensador.write(98);
}

int obtenerPeso()
{
	return balanza.get_units(2);
}

void cambiarTara()
{
	balanza.tare(20);
}

void controlServo(bool abierto, int angulo)
{
	if (abierto)
	{
		dispensador.write(angulo);
	}
	else
	{
		dispensador.write(98);
		delay(500);
		dispensador.write(98);
	}
}