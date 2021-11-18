// informacionBalanza.h

#ifndef _INFORMACIONBALANZA_h
#define _INFORMACIONBALANZA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

void inicioBalanza();
int obtenerPeso();
void cambiarTara();
void controlServo(bool abierto, int angulo);

#endif

