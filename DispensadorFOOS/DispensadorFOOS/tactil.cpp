#include "tactil.h"
#include "diseno.h"
#include "datosMemoria.h"
#include "horarioComidas.h"
#include "controlHora.h"

#include <TouchScreen.h>
#include <EEPROM.h>

#define YP A2 
#define XM A3 
#define YM 8 
#define XP 9

#define MINPRESSURE 1
#define MAXPRESSURE 1000

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

bool screenInicio = true, screenConfiguracion = false, screenVeces = false, screenAnimal = false, screenPorcionesMejorado = false, screenPersonalizado = false, screenEnvio = false, screenMensaje = false, screenNotificaciones = false, screenInformacionWifi = false, screenEnvioProgramado = false, screenConectarseWifi = false, screenHora = false;
bool alimentarYa = false, animal = false;
int screenActual;
int contadorVecesDiarias = 1, vecesDiariasBucle, hora = 12, minuto = 0, cantidadAlimento=5;
int horariosComidas[5][2], horariosComidasEeprom[5][2];
HoraiosComidas* comida[5];
HoraiosComidas* comidaEeprom[5];

void tactilPantalla()
{
	TSPoint p = ts.getPoint();

	pinMode(XM, OUTPUT);
	pinMode(YP, OUTPUT);

	if (p.z > MINPRESSURE && p.z < MAXPRESSURE)
	{
		int X = map(p.x, TS_MAXX, TS_MINX, 320, 0);
		int Y = map(p.y, TS_MAXY, TS_MINY, 0, 240);

		if (screenActual == 0) // PANTALLA DE INICIO 
		{
			if ((X > 12 && X < 152) && (Y > 110 && Y < 190)) // BOTON CONFIGURACION
			{
				borrarPantalla();
				screenVeces = true;
				alimentarYa = false;
			}
			if ((X > 167 && X < 307) && (Y > 110 && Y < 190)) // BOTON ALIMENTAR YA
			{
				borrarPantalla();
				screenAnimal = true;
				alimentarYa = true;
			}
			if ((X > 3 && X < 318) && (Y > 200 && Y < 243)) // BOTON MAS INFORMACION
			{
				borrarPantalla();
				screenNotificaciones = true;
			}
		}
		if (screenActual == 1) // PANTALLA VECES DIARIAS
		{
			if ((X > 38 && X < 98) && (Y > 100 && Y < 160)) // BOTON MAS VECES DIARIAS
			{
				borrarCaracteres(240, 100, 8, contadorVecesDiarias);
				contadorVecesDiarias += 1;
				if (contadorVecesDiarias > 4)
				{
					contadorVecesDiarias = 1;
				}
				screenVeces = true;
			}
			if ((X > 121 && X < 181) && (Y > 100 && Y < 160)) // BOTON MENOS VECES DIARIAS
			{
				borrarCaracteres(240, 100, 8, contadorVecesDiarias);
				contadorVecesDiarias -= 1;
				if (contadorVecesDiarias < 1)
				{
					contadorVecesDiarias = 4;
				}
				borrarRegionesEspeciales(226, 95, 68, 68);
				screenVeces = true;
			}
			if ((X > 145 && X < 315) && (Y > 170 && Y < 230)) // BOTON SIGUIENTE
			{
				borrarPantalla();
				screenConfiguracion = true;
				vecesDiariasBucle = contadorVecesDiarias;
			}
			if ((X > 3 && X < 123) && (Y > 191 && Y < 230)) // BOTON INICIO
			{
				contadorVecesDiarias = 1;
				borrarPantalla();
				screenInicio = true;
			}
		}
		if (screenActual == 2) // PANTALLA CONFIGURACION HORA
		{
			if ((X > 4 && X < 44) && (Y > 165 && Y < 205)) // BOTON +1 HORA
			{
				hora += 1;
				if (hora > 23) { hora = 0; }
				borrarRegionesEspeciales(176, 56, 60, 66);
				screenConfiguracion = true;
			}
			if ((X > 54 && X < 94) && (Y > 165 && Y < 205)) // BOTON -1 HORA
			{
				hora -= 1;
				if (hora < 0)
				{
					hora = 23;
				}
				borrarRegionesEspeciales(176, 56, 60, 66);
				screenConfiguracion = true;
			}
			if ((X > 109 && X < 149) && (Y > 165 && Y < 205)) // BOTON +10 MINUTOS
			{
				minuto += 10;
				if (minuto > 59)
				{
					minuto = 0;
				}
				borrarRegionesEspeciales(254, 56, 60, 66);
				screenConfiguracion = true;
			}
			if ((X > 159 && X < 199) && (Y > 165 && Y < 205)) // BOTON -10 MINUTOS
			{
				minuto -= 10;
				if (minuto < 0)
				{
					minuto = 50;
				}
				borrarRegionesEspeciales(254, 56, 60, 66);
				screenConfiguracion = true;
			}
			if ((X > 214 && X < 254) && (Y > 165 && Y < 205)) // BOTON +1 MINUTO
			{
				minuto += 1;
				if (minuto > 59)
				{
					minuto = 0;
				}
				borrarRegionesEspeciales(254, 56, 60, 66);
				screenConfiguracion = true;
			}
			if ((X > 264 && X < 304) && (Y > 165 && Y < 205)) // BOTON -1 MINUTO
			{
				minuto -= 1;
				if (minuto < 0)
				{
					minuto = 59;
				}
				borrarRegionesEspeciales(254, 56, 60, 66);
				screenConfiguracion = true;
			}
			if ((X > 4 && X < 124 ) && (Y > 212 && Y < 240)) // BOTON ATRAS
			{
				vecesDiariasBucle += 1;
				if (vecesDiariasBucle-1 == contadorVecesDiarias)
				{
					borrarPantalla();
					screenVeces = true;
				}
				else
				{
					borrarPantalla();
					screenConfiguracion = true;
					hora = comida[vecesDiariasBucle]->mostrarHora();
					minuto = comida[vecesDiariasBucle]->mostrarMinuto();
				}
			}
			if ((X > 145 && X < 305) && (Y > 212 && Y < 240)) // BOTON SIGUIENTE
			{	
				while (vecesDiariasBucle > 0)
				{
					comida[vecesDiariasBucle] = new HoraiosComidas(hora, minuto);
					hora = 12, minuto = 0;
					//comida[vecesDiariasBucle]->mostrarDatos();
					if (vecesDiariasBucle != 1)
					{
						borrarPantalla();
						screenConfiguracion = true;
					}

					vecesDiariasBucle -= 1;

					break;
				}
				if (vecesDiariasBucle <= 0)
				{
					borrarPantalla();
					screenAnimal = true;
				}
			}

		}
		if (screenActual == 3) // PANTALLA TIPO ANIMAL
		{
			if ((X > 36 && X < 136) && (Y > 100 && Y < 160)) // BOTON GATO
			{
				borrarPantalla();
				animal = true;
				screenPorcionesMejorado = true;
			}
			if ((X > 178 && X < 278) && (Y > 100 && Y < 160)) // BOTON PERRO
			{
				borrarPantalla();
				animal = false;
				screenPorcionesMejorado = true;
			}
			if ((X > 36 && X < 278) && (Y > 195 && Y < 233)) // BOTON ATRAS
			{
				if (alimentarYa)
				{
					borrarPantalla();
					screenInicio = true;
				}
				else
				{
					vecesDiariasBucle += 1;
					hora = comida[vecesDiariasBucle]->mostrarHora();
					minuto = comida[vecesDiariasBucle]->mostrarMinuto();
					borrarPantalla();
					screenConfiguracion = true;
				}
			}
		}
		if (screenActual == 4) // PANTALLA CANTIDAD DE COMIDA
		{
			if (animal) // GATO
			{
				if ((X > 20 && X < 260) && (Y > 70 && Y < 95)) // OPCION 1
				{
					cantidadAlimento = 35;
					if (alimentarYa)
					{
						screenEnvio = true;
					}
					else
					{
						screenEnvioProgramado = true;
					}
				}
				if ((X > 20 && X < 260) && (Y > 100 && Y < 125)) // OPCION 2
				{
					cantidadAlimento = 48;
					if (alimentarYa)
					{
						screenEnvio = true;
					}
					else
					{
						screenEnvioProgramado = true;
					}
				}
				if ((X > 20 && X < 260) && (Y > 130 && Y < 155)) // OPCION 3
				{
					cantidadAlimento = 55;
					if (alimentarYa)
					{
						screenEnvio = true;
					}
					else
					{
						screenEnvioProgramado = true;
					}
				}
				if ((X > 20 && X < 260) && (Y > 160 && Y < 185)) // OPCION 4
				{
					cantidadAlimento = 65;
					if (alimentarYa)
					{
						screenEnvio = true;
					}
					else
					{
						screenEnvioProgramado = true;
					}
				}
				borrarPantalla();
			}
			else // PERRO
			{
				if ((X > 20 && X < 260) && (Y > 70 && Y < 95)) // OPCION 1
				{
					cantidadAlimento = 70;
					if (alimentarYa)
					{
						screenEnvio = true;
					}
					else
					{
						screenEnvioProgramado = true;
					}
				}
				if ((X > 20 && X < 260) && (Y > 100 && Y < 125)) // OPCION 2
				{
					cantidadAlimento = 130;
					if (alimentarYa)
					{
						screenEnvio = true;
					}
					else
					{
						screenEnvioProgramado = true;
					}
				}
				if ((X > 20 && X < 260) && (Y > 130 && Y < 155)) // OPCION 3
				{
					cantidadAlimento = 250;
					if (alimentarYa)
					{
						screenEnvio = true;
					}
					else
					{
						screenEnvioProgramado = true;
					}
				}
				if ((X > 20 && X < 260) && (Y > 160 && Y < 185)) // OPCION 4
				{
					cantidadAlimento = 540;
					if (alimentarYa)
					{
						screenEnvio = true;
					}
					else
					{
						screenEnvioProgramado = true;
					}
				}
				borrarPantalla();
			}
			if ((X > 10 && X < 90) && (Y > 198 && Y < 238)) // BOTON ATRAS
			{
				borrarPantalla();
				screenAnimal = true;
			}
			if ((X > 142 && X < 312) && (Y > 198 && Y < 238)) // BOTON PERSONALIZADO
			{
				borrarPantalla();
				screenPersonalizado = true;
			}
		}
		if (screenActual == 5) // PANTALLA PERSONALIZADA DE COMIDA
		{
			if ((X > 38 && X < 98) && (Y > 100 && Y < 168)) // +5 GR COMIDA PERSONALIZADA
			{
				cantidadAlimento += 5;
				if (cantidadAlimento > 800)
				{
					cantidadAlimento = 5;
				}
				borrarRegionesEspeciales(211, 95, 98, 68);
				screenPersonalizado = true;
			}
			if ((X > 121 && X < 181) && (Y > 100 && Y < 168)) // -5 GR COMIDA PERSONALIZADA
			{
				cantidadAlimento -= 5;
				if (cantidadAlimento < 5)
				{
					cantidadAlimento = 800;
				}
				borrarRegionesEspeciales(211, 95, 98, 68);
				screenPersonalizado = true;
			}
			if ((X > 145 && X < 315) && (Y > 191 && Y < 231)) // SIGUIENTE COMIDA PERSONALIZADA
			{
				if (alimentarYa)
				{
					borrarPantalla();
					screenEnvio = true;
				}
				else
				{
					borrarPantalla();
					screenEnvioProgramado = true;
				}
			}
			if ((X > 3 && X < 123) && (Y > 191 && Y < 231)) // ATRAS COMIDA PERSONALIZADA
			{
				cantidadAlimento = 5;
				borrarPantalla();
				screenPorcionesMejorado = true;
			}
		}
		if (screenActual == 8)
		{
			if ((X > 226 && X < 316) && (Y > 176 && Y < 246)) // BOTON WIFI
			{
				borrarPantalla();
				screenInformacionWifi = true;
			}
			if ((X > 116 && X < 206) && (Y > 176 && Y < 246)) // BOTON HORA
			{
				borrarPantalla();
				screenHora = true;
			}
			if ((X > 1 && X < 96) && (Y > 176 && Y < 246)) // BOTON ATRAS
			{
				borrarPantalla();
				screenInicio = true;
			}
		}
		if (screenActual == 9)
		{
			if ((X > 170 && X < 310) && (Y > 191 && Y < 230)) // CONECTARSE A UNA RED
			{
				borrarPantalla();
				screenConectarseWifi = true;
			}

			if ((X > 10 && X < 150) && (Y > 191 && Y < 230)) // BOTON ATRAS
			{
				borrarPantalla();
				screenNotificaciones = true;
			}
		}
		if (screenActual == 12)
		{
			if ((X > 36 && X < 278) && (Y > 195 && Y < 233)) // BOTON ATRAS
			{
				borrarPantalla();
				screenNotificaciones = true;
			}
		}
	}
	else
	{
		if (obtenerSegundo() == 1)
		{
			for (int i = 0; i < EEPROM.read(31); i++)
			{
				if (comidaEeprom[i + 1]->mostrarHora() == obtenerHora() && comidaEeprom[i + 1]->mostrarMinuto() == obtenerMinuto())
				{
					cantidadAlimento = EEPROM.read(30);
					Serial.println("ALIMENTANDO");
					borrarPantalla();
					screenEnvio = true;
				}
			}
			delay(1000);
		}
  	}
}

void controlPantallas()
{
	tactilPantalla();
	if (screenInicio)
	{
		screenActual = inicio();
		screenInicio = false;
	}
	if (screenConfiguracion)
	{
		screenActual = configuracion(hora, minuto); // parametro -> hora, minuto
		screenConfiguracion = false;
	}
	if (screenVeces)
	{
		screenActual = vecesDiarias(contadorVecesDiarias); // parametro -> cantidad de veces al dia
		screenVeces = false;
	}
	if (screenAnimal)
	{
		screenActual = tipoAnimal();
		screenAnimal = false;
	}
	if (screenPorcionesMejorado)
	{
		screenActual = porcionesMejorado(animal); // parametro -> true = gato | false = perro
		screenPorcionesMejorado = false;
	}
	if (screenPersonalizado)
	{
		screenActual = personalizado(cantidadAlimento); // parametro -> cantidad personalizada
		screenPersonalizado = false;
	}
	if (screenEnvio)
	{
		screenActual = envio(animal, cantidadAlimento); // parametro -> true = gato | false = perro,  cantidad de alimento
		cantidadAlimento = 5;
		screenEnvio = false;
		borrarPantalla();
		screenInicio = true;
	}
	if (screenMensaje)
	{
		screenActual = mensaje();
		screenMensaje = false;
	}
	if (screenNotificaciones)
	{
		int horariosComidas[5][2];
		screenActual = notificaciones(EEPROM.read(30), EEPROM.read(31), comidaEeprom); // parametro -> cantidad de alimento, veces de alimento, horarios de comidas[cantidad de comidas max 5][hora,minuto]
		screenNotificaciones = false;
	}
	if (screenInformacionWifi)
	{
		screenActual = informacionWifi("fibraETB", "1600", "192.168.0.6"); // parametro -> red,puerto e ip
		screenInformacionWifi = false;
	}
	if (screenHora)
	{
		screenActual = mostrarHora(obtenerHora(),obtenerMinuto());
		screenHora = false;
	}
	if (screenEnvioProgramado)
	{
		screenActual = envioProgramado(cantidadAlimento, contadorVecesDiarias, comida); // parametro -> cantidad de alimento, veces de alimento, horarios de comidas[cantidad de comidas max 5][hora,minuto]
		guardarDatos(cantidadAlimento, contadorVecesDiarias, comida);
		leerDatos(comidaEeprom);
		contadorVecesDiarias = 1;
		delete comida;
		borrarPantalla();
		screenEnvioProgramado = false;
		screenInicio = true;
	}
	if (screenConectarseWifi)
	{
		screenActual = conectarRedWifi(30);
		screenConectarseWifi = false;
	}
}
void leerDatosEnInicio()
{
	leerDatos(comidaEeprom);
}

