
#ifndef _HORARIOCOMIDAS_h
#define _HORARIOCOMIDAS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class HoraiosComidas
{
public:
	HoraiosComidas(int,int);
	~HoraiosComidas();
	void mostrarDatos();
	int mostrarHora();
	int mostrarMinuto();

private:
	int hora;
	int minuto;

};
#endif

