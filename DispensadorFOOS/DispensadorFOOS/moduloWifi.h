
#ifndef _MODULOWIFI_h
#define _MODULOWIFI_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
void redesDisponibles();
void comandoAtRedesDisponibles();

#endif

