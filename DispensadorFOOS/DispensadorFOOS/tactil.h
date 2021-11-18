#ifndef _TACTIL_h
#define _TACTIL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
void tactilPantalla();
void controlPantallas();
void leerDatosEnInicio();
#endif

