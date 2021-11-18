#include "controlLeds.h"

#define LED1 52
#define LED2 50
#define LED3 46
#define LED4 48

void inicioLeds()
{
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);
}