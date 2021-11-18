// controlHora.h

#ifndef _CONTROLHORA_h
#define _CONTROLHORA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
void inicioModulo();
int obtenerHora();
int obtenerMinuto();
int  obtenerSegundo();
#endif

