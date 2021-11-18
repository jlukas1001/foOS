// datosMemoria.h

#ifndef _HORARIOCOMIDAS_h
#include "horarioComidas.h"
#endif

#ifndef _DATOSMEMORIA_h
#define _DATOSMEMORIA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
void leerDatos(HoraiosComidas* comidaEeprom[5]);
void guardarDatos(int cantidad, int vecesDiarias, HoraiosComidas* comida[5]);
#endif

