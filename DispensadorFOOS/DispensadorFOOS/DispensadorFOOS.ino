#include "informacionBalanza.h"
#include "controlHora.h"
#include "animacionDeInicio.h"
#include "controlLeds.h"
#include "moduloWifi.h"
#include "horarioComidas.h"
#include "datosMemoria.h"
#include "tactil.h"
#include "diseno.h"

void setup() {
	Serial.begin(115200);
	Serial1.begin(115200);
	Serial.println("---------------INICIANDO CONSOLA------------------");
	inicioModulo();
	inicioPantalla();
	inicioLeds();
	inicioBalanza();
	leerDatosEnInicio();
	encendido();
}
void loop() 
{
	controlPantallas();
}

