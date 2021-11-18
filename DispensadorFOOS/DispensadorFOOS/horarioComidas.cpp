#include "horarioComidas.h"

HoraiosComidas::HoraiosComidas(int _hora, int _minuto){
	hora = _hora;
	minuto = _minuto;
}

HoraiosComidas::~HoraiosComidas()
{
}

void HoraiosComidas::mostrarDatos()
{
	Serial.println(hora);
	Serial.println(minuto);
}

int HoraiosComidas::mostrarHora()
{
	return hora;
}
int HoraiosComidas::mostrarMinuto()
{
	return minuto;
}
