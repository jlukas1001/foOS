// diseno.h
//#include "horarioComidas.h"
#ifndef _HORARIOCOMIDAS_h
#include "horarioComidas.h"
#endif

#ifndef _DISENO_h
#define _DISENO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
void inicioPantalla();

int inicio();
int configuracion(int hora, int minuto);
int vecesDiarias(int veces);
int tipoAnimal();
int porcionesMejorado(bool animal);
int personalizado(int cantidad);
int envio(bool animal, int cantidad);
int mensaje();
int notificaciones(int cantidad, int vecesDiarias, HoraiosComidas* comidaEeprom[5]);
int informacionWifi(String redConectada, String puertoDeLaRed, String dirIp);
int envioProgramado(int cantidad, int vecesDiarias, HoraiosComidas* comida[5]);
int conectarRedWifi(int cantidadRedes);
void borrarRegionesEspeciales(int inicioX, int inicioY, int largo, int ancho);
void borrarCaracteres(int inicioX, int inicioY, int tamanoLetra, int numBorrar);
void borrarPantalla();
void encendido();
int mostrarHora(int hora, int minuto);

#endif

