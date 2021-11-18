#include "diseno.h"
#include "horarioComidas.h"
#include "moduloWifi.h"
#include "controlHora.h"
#include "informacionBalanza.h"
#include <Adafruit_GFX.h>
#include <registers.h>
#include <pin_magic_UNO.h>
#include <pin_magic_MEGA.h>
#include <pin_magic.h>
#include <Adafruit_TFTLCD.h>

#define BLACK   0x0000              
#define RED     0xF800 
#define GREEN   0x07E0 
#define WHITE   0xFFFF  
#define BLUE  0x001F 
#define CYAN   0x07FF
#define YELLOW    0xFFE0
#define MAGENTA 0xF81F
#define PINK 0x0F0F
#define GREY 0x7BEF
#define ORANGE 0xFBE0

Adafruit_TFTLCD tft(A3, A2, A1, A0, A4); // Instancia LCD  con libreria LCD
float angulo = 108;

void inicioPantalla()
{
	tft.begin(0x9341);
	tft.setRotation(1);
	tft.fillScreen(WHITE);
}

int inicio() // DEVUELVE 0    ------ PANTALLA 0
{
	tft.setCursor(26, 20);
	tft.setTextSize(4);
	tft.setTextColor(BLACK);
	tft.print("DISPENSADOR");

	tft.setCursor(4, 60);
	tft.setTextSize(4);
	tft.setTextColor(BLACK);
	tft.print(" DE ALIMENTO");


	tft.setCursor(17, 120);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("CONFIG-");

	tft.setCursor(17, 160);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("URACION");



	tft.drawRect(12, 110, 140, 80, BLUE);

	tft.setCursor(172, 120);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("ALIMEN-");

	tft.setCursor(172, 160);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("TAR YA");

	tft.drawRect(167, 110, 140, 80, BLUE);


	tft.setCursor(30, 205);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("Mas informacion");

	tft.drawRect(3, 200, 315, 34, BLUE);

	return 0;
}
int vecesDiarias(int veces) // DEVUELVE 1   -------- PANTALLA 1
{
	tft.setCursor(30, 20);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("COMIDAS DIARIAS");

	tft.setCursor(47, 100);
	tft.setTextSize(8);
	tft.setTextColor(BLUE);
	tft.print("+");

	tft.drawRect(38, 100, 60, 60, BLUE);

	tft.setCursor(130, 101);
	tft.setTextSize(8);
	tft.setTextColor(BLUE);
	tft.print("-");

	tft.drawRect(121, 100, 60, 60, BLUE);

	tft.setCursor(240, 100);
	tft.setTextSize(8);
	tft.setTextColor(BLACK);
	tft.print(veces);

	tft.drawRect(225, 94, 70, 70, BLACK);

	tft.setCursor(150, 200);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("SIGUIENTE");

	tft.drawRect(145, 191, 170, 40, BLACK);

	tft.setCursor(8, 200);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("INICIO");

	tft.drawRect(3, 191, 120, 39, BLACK);
	return 1;
}
int configuracion(int hora, int minuto) // DEVUELVE 2   -------- PANTALLA 2
{
	tft.setCursor(40, 20);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("CONFIGURACION");

	tft.setCursor(4, 60);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("HORA DE");

	tft.setCursor(4, 100);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("ALIMENTAR");

	tft.drawRect(175, 55, 140, 70, BLUE);

	if (hora < 10)
	{
		tft.setCursor(180, 70);
		tft.setTextSize(5);
		tft.setTextColor(BLACK);
		tft.print("0");

		tft.setCursor(210, 70);
		tft.setTextSize(5);
		tft.setTextColor(BLACK);
		tft.print(hora);
	}
	else
	{
		tft.setCursor(180, 70);
		tft.setTextSize(5);
		tft.setTextColor(BLACK);
		tft.print(hora);
	}

	tft.setCursor(232.5, 70);
	tft.setTextSize(5);
	tft.setTextColor(BLACK);
	tft.print(":");

	if (minuto < 10)
	{
		tft.setCursor(255, 70);
		tft.setTextSize(5);
		tft.setTextColor(BLACK);
		tft.print("0");

		tft.setCursor(285, 70);
		tft.setTextSize(5);
		tft.setTextColor(BLACK);
		tft.print(minuto);
	}
	else
	{
		tft.setCursor(255, 70);
		tft.setTextSize(5);
		tft.setTextColor(BLACK);
		tft.print(minuto);
	}

	tft.setCursor(20, 135);
	tft.setTextSize(3);
	tft.setTextColor(RED);
	tft.print("1 H");

	tft.drawRect(4, 165, 40, 40, RED);

	tft.setCursor(9, 164);
	tft.setTextSize(6);
	tft.setTextColor(RED);
	tft.print("+");

	tft.drawRect(54, 165, 40, 40, RED);

	tft.setCursor(59, 164);
	tft.setTextSize(6);
	tft.setTextColor(RED);
	tft.print("-");

	tft.setCursor(117, 135);
	tft.setTextSize(3);
	tft.setTextColor(BLUE);
	tft.print("10 M");

	tft.drawRect(109, 165, 40, 40, BLUE);

	tft.setCursor(114, 164);
	tft.setTextSize(6);
	tft.setTextColor(BLUE);
	tft.print("+");

	tft.drawRect(159, 165, 40, 40, BLUE);

	tft.setCursor(163, 164);
	tft.setTextSize(6);
	tft.setTextColor(BLUE);
	tft.print("-");

	tft.setCursor(230, 135);
	tft.setTextSize(3);
	tft.setTextColor(MAGENTA);
	tft.print("1 M");



	tft.drawRect(214, 165, 40, 40, MAGENTA);

	tft.setCursor(218, 164);
	tft.setTextSize(6);
	tft.setTextColor(MAGENTA);
	tft.print("+");

	tft.drawRect(264, 165, 40, 40, MAGENTA);

	tft.setCursor(268, 164);
	tft.setTextSize(6);
	tft.setTextColor(MAGENTA);
	tft.print("-");



	tft.setCursor(150, 215);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("SIGUIENTE");

	tft.drawRect(145, 212, 170, 28, BLACK);

	tft.setCursor(4, 215);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("ATRAS");

	tft.drawRect(4, 212, 120, 28, BLACK);

	return 2;
}
int tipoAnimal() // DEVUELVE 3   -------- PANTALLA 3
{
	tft.setCursor(10, 20);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("QUE ANIMAL TIENES");

	tft.setCursor(50, 120);
	tft.setTextSize(3);
	tft.setTextColor(BLUE);
	tft.print("GATO");

	tft.drawRect(36, 100, 100, 60, 0x7FF0);

	tft.setCursor(185, 120);
	tft.setTextSize(3);
	tft.setTextColor(BLUE);
	tft.print("PERRO");

	tft.drawRect(178, 100, 100, 60, 0x7FF0);

	tft.setCursor(120, 204);
	tft.setTextSize(3);
	tft.setTextColor(BLUE);
	tft.print("ATRAS");

	tft.drawRect(36, 195, 242, 38, 0x7FF0);
	return 3;
}
int porcionesMejorado(bool animal) // DEVUELVE 4   -------- PANTALLA 4
{
	if (animal == true) //Animal == true animal es un gato -------- Animal == false animal es un perro
	{
		tft.setCursor(120, 10);
		tft.setTextSize(3);
		tft.setTextColor(PINK);
		tft.print("GATO");

		tft.setCursor(10, 40);
		tft.setTextSize(2);
		tft.setTextColor(BLUE);
		tft.print("PESO GATO");

		tft.setCursor(140, 40);
		tft.setTextSize(2);
		tft.setTextColor(BLUE);
		tft.print("CANTIDAD COMIDA");

		tft.setCursor(40, 75);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("2 Kg");

		tft.setCursor(200, 75);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("35 g");

		tft.drawRect(20, 70, 240, 25, 0x7FF0);

		tft.setCursor(40, 105);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("3 Kg");

		tft.setCursor(200, 105);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("48 g");

		tft.drawRect(20, 100, 240, 25, 0x7FF0);

		tft.setCursor(40, 135);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("4 Kg");

		tft.setCursor(200, 135);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("55 g");

		tft.drawRect(20, 130, 240, 25, 0x7FF0);

		tft.setCursor(40, 165);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("5 Kg");

		tft.setCursor(200, 165);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("65 g");

		tft.drawRect(20, 160, 240, 25, 0x7FF0);

		tft.setCursor(150, 210);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("PERSONALIZADA");

		tft.drawRect(142, 198, 170, 40, 0x7FF0);

		tft.setCursor(20, 210);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("ATRAS");

		tft.drawRect(10, 198, 80, 40, 0x7FF0);

	}
	if (animal == false)
	{
		tft.setCursor(120, 10);
		tft.setTextSize(3);
		tft.setTextColor(PINK);
		tft.print("PERRO");

		tft.setCursor(10, 40);
		tft.setTextSize(2);
		tft.setTextColor(BLUE);
		tft.print("PESO PERRO");

		tft.setCursor(140, 40);
		tft.setTextSize(2);
		tft.setTextColor(BLUE);
		tft.print("CANTIDAD COMIDA");

		tft.setCursor(40, 75);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("2-3 Kg");

		tft.setCursor(200, 75);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("70  g");

		tft.drawRect(20, 70, 250, 25, 0x7FF0);

		tft.setCursor(40, 105);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("3-10 Kg");

		tft.setCursor(200, 105);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("130 g");

		tft.drawRect(20, 100, 250, 25, 0x7FF0);

		tft.setCursor(40, 135);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("10-20 Kg");

		tft.setCursor(200, 135);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("250 g");

		tft.drawRect(20, 130, 250, 25, 0x7FF0);

		tft.setCursor(40, 165);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("20-30 Kg");

		tft.setCursor(200, 165);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("540 g");

		tft.drawRect(20, 160, 250, 25, 0x7FF0);

		tft.setCursor(150, 210);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("PERSONALIZADA");

		tft.drawRect(142, 198, 170, 40, 0x7FF0);

		tft.setCursor(20, 210);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("ATRAS");

		tft.drawRect(10, 198, 80, 40, 0x7FF0);
	}
	return 4;
}
int personalizado(int cantidad)  // DEVUELVE 5   -------- PANTALLA 5
{
	tft.setCursor(90, 20);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("CANTIDAD");

	tft.setCursor(20, 50);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("DE ALIMENTO EN g");

	tft.setCursor(47, 100);
	tft.setTextSize(8);
	tft.setTextColor(YELLOW);
	tft.print("+");

	tft.drawRect(38, 100, 60, 60, 0x7FF0);

	tft.setCursor(130, 101);
	tft.setTextSize(8);
	tft.setTextColor(YELLOW);
	tft.print("-");

	tft.drawRect(121, 100, 60, 60, 0x7FF0);

	tft.setCursor(215, 110);
	tft.setTextSize(5);
	tft.setTextColor(BLACK);
	tft.print(cantidad);

	tft.drawRect(210, 94, 100, 70, 0x7FF0);

	tft.setCursor(150, 200);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("SIGUIENTE");

	tft.drawRect(145, 191, 170, 40, 0x7FF0);

	tft.setCursor(18, 200);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("ATRAS");

	tft.drawRect(3, 191, 120, 39, 0x7FF0);
	return 5;
}
int envio(bool animal, int cantidad) // DEVUELVE 6   -------- PANTALLA 6
{
	tft.setCursor(80, 20);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("SU");

	if (animal == true)
	{
		tft.setCursor(140, 20);
		tft.setTextSize(3);
		tft.setTextColor(PINK);
		tft.print("GATO");
	}

	if (animal == false)
	{
		tft.setCursor(140, 20);
		tft.setTextSize(3);
		tft.setTextColor(PINK);
		tft.print("PERRO");
	}

	tft.setCursor(50, 60);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("SE ALIMENTARA");

	tft.setCursor(30, 100);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("CON:");

	tft.setCursor(115, 100);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print(cantidad);

	tft.setCursor(195, 100);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("GRAMOS");

	tft.setCursor(106, 160);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("ESPERE");

	//ABRIR EL SERVO
	controlServo(true,angulo);

	cambiarTara();
	int contador = 0;
	while (obtenerPeso() < cantidad)
	{
		contador = contador + 1;
		
		if (contador > 2)
		{
			angulo = angulo + 0.2;
			
			controlServo(false, angulo);
			delay(500);
			controlServo(true, angulo);
			if (angulo == 155)
			{
				controlServo(false, angulo);
				cantidad = -10;
			}
			contador = 0;
		}
	}
	angulo = 108;
	controlServo(false, angulo);
	// CERRAR EL SERVO
	return 0;
}
int mensaje() // DEVUELVE 7   -------- PANTALLA 7
{
	tft.setCursor(15, 40);
	tft.setTextSize(3);
	tft.setTextColor(RED);
	tft.print("DESEA CAMBIAR LA");

	tft.setCursor(45, 70);
	tft.setTextSize(3);
	tft.setTextColor(RED);
	tft.print("CONFIGURACION");

	tft.setCursor(100, 100);
	tft.setTextSize(3);
	tft.setTextColor(RED);
	tft.print("ACTUAL ?");

	tft.setCursor(75, 160);
	tft.setTextSize(5);
	tft.setTextColor(BLACK);
	tft.print("SI");

	tft.drawRect(61, 150, 80, 60, BLACK);

	tft.setCursor(195, 160);
	tft.setTextSize(5);
	tft.setTextColor(BLACK);
	tft.print("NO");

	tft.drawRect(181, 150, 80, 60, BLACK);
	return 7;
}
int notificaciones(int cantidad, int vecesDiarias, HoraiosComidas* comidaEeprom[5])  // DEVUELVE 8   -------- PANTALLA 8
{
	int altura = 40;
	for (int i = 0; i < vecesDiarias; i++)
	{
		altura += 25;
		tft.setCursor(220, altura);
		tft.setTextSize(3);
		tft.setTextColor(RED);
		tft.print(":");

		int hora = comidaEeprom[i + 1]->mostrarHora();
		int minuto = comidaEeprom[i + 1]->mostrarMinuto();
		
		if (hora < 10)
		{
			tft.setCursor(185, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print("0");

			tft.setCursor(204, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print(hora);
		}
		else
		{
			tft.setCursor(185, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print(hora);
		}
		if (minuto < 10)
		{
			tft.setCursor(235, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print("0");

			tft.setCursor(253, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print(minuto);
		}
		else
		{
			tft.setCursor(235, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print(minuto);
		}
	}

	tft.setCursor(4, 135);
	tft.setTextSize(3);
	tft.setTextColor(RED);
	tft.print(cantidad);


	tft.setCursor(60, 135);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("gramos");

	tft.setCursor(30, 20);
	tft.setTextSize(4);
	tft.setTextColor(BLUE);
	tft.print("INFORMACION");

	tft.setCursor(4, 70);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("Horario");

	tft.setCursor(4, 100);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("comidas:");

	tft.setCursor(124, 195);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("HORA");

	tft.drawRect(116, 175, 90, 60, BLACK);

	tft.setCursor(125 + 111, 195);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("WIFI");

	tft.drawRect(226, 175, 90, 60, BLACK);

	tft.setCursor(4, 195);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("ATRAS");

	tft.drawRect(1, 176, 95, 60, BLACK);
	return 8;
}
int informacionWifi(String redConectada, String puertoDeLaRed, String dirIp) // DEVUELVE 9   -------- PANTALLA 9
{
	tft.setCursor(65, 90);
	tft.setTextSize(2);                // NOMBRE DE LA RED
	tft.setTextColor(BLACK);
	tft.print(redConectada);

	tft.setCursor(90, 120);
	tft.setTextSize(2);                    // PUERTO DE LA RED
	tft.setTextColor(BLACK);
	tft.print(puertoDeLaRed);

	tft.setCursor(40, 150);
	tft.setTextSize(2);
	tft.setTextColor(BLACK);          // DIRRECION IP
	tft.print(dirIp);


	tft.setCursor(60, 20);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("INFORMACION");
	tft.setCursor(85, 50);
	tft.setTextSize(3);
	tft.setTextColor(PINK);
	tft.print("DEL WIFI");

	tft.setCursor(5, 90);
	tft.setTextSize(2);
	tft.setTextColor(PINK);
	tft.print("SSID: ");
	tft.setCursor(5, 120);
	tft.setTextSize(2);
	tft.setTextColor(PINK);
	tft.print("PUERTO: ");
	tft.setCursor(5, 150);
	tft.setTextSize(2);
	tft.setTextColor(PINK);
	tft.print("IP: ");

	tft.setCursor(52, 205);
	tft.setTextSize(2);
	tft.setTextColor(BLACK);
	tft.print("ATRAS");

	tft.drawRect(10, 191, 140, 39, 0x7FF0);

	tft.setCursor(180, 205);
	tft.setTextSize(2);
	tft.setTextColor(BLACK);
	tft.print("CONECTARSE");

	tft.drawRect(170, 191, 140, 39, 0x7FF0);

	return 9;
}
int envioProgramado(int cantidad, int vecesDiarias, HoraiosComidas* comida[5]) // DEVUELVE 10   -------- PANTALLA 10
{
	tft.setCursor(20, 50);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("HORARIO");

	tft.setCursor(20, 80);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("COMIDAS");

	int altura = -10;
	for (int i = 0; i < vecesDiarias; i++)
	{
		altura += 30;
		tft.setCursor(220, altura);
		tft.setTextSize(3);
		tft.setTextColor(RED);
		tft.print(":");

		int hora = comida[i+1]->mostrarHora();
		int minuto = comida[i+1]->mostrarMinuto();

		if (hora < 10)
		{
			tft.setCursor(185, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print("0");

			tft.setCursor(204, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print(hora);
		}
		else
		{
			tft.setCursor(185, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print(hora);
		}
		if (minuto < 10)
		{
			tft.setCursor(235, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print("0");

			tft.setCursor(253, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print(minuto);
		}
		else
		{
			tft.setCursor(235, altura);
			tft.setTextSize(3);
			tft.setTextColor(BLACK);
			tft.print(minuto);
		}
	}

	tft.setCursor(20, 150);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("CANTIDAD");

	tft.setCursor(20, 180);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("PORCION");

	tft.setCursor(180, 160);
	tft.setTextSize(3);
	tft.setTextColor(RED);
	tft.print(cantidad);

	tft.setCursor(250, 160);
	tft.setTextSize(3);
	tft.setTextColor(RED);
	tft.print("g");

	delay(4000);

	return 10;
}
int conectarRedWifi(int cantidadRedes) // DEVUELVE 11
{
	comandoAtRedesDisponibles();
	redesDisponibles();
	int altura = 10;
	int multiplos5 = 0;
	int paginasRedes = 0;
	for (int i = 0; i < cantidadRedes; i++)
	{
		multiplos5 = multiplos5 + 1;
		if (multiplos5 == 5)
		{
			altura = 10;
			paginasRedes += 1;
			multiplos5 = 0;
		}
		tft.drawRect(10, altura, 300, 30, 0x7FF0);
		tft.setCursor(20, altura+8);
		tft.setTextSize(2);
		tft.setTextColor(BLACK);
		tft.print("FibraETB_GarciaOsorio");
		altura += 35;
	}

	tft.setCursor(274, 210);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("->");

	tft.drawRect(270, 198, 40, 40, 0x7FF0);

	tft.setCursor(216, 210);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("<-");

	tft.drawRect(215, 198, 40, 40, 0x7FF0);


	tft.setCursor(107, 210);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("1");
	tft.setCursor(142, 210);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print("/");
	tft.setCursor(177, 210);
	tft.setTextSize(3);
	tft.setTextColor(BLACK);
	tft.print((String)paginasRedes);

	tft.setCursor(20, 210);
	tft.setTextSize(2);
	tft.setTextColor(BLACK);
	tft.print("ATRAS");

	tft.drawRect(10, 198, 80, 40, 0x7FF0);

	return 11;
}
int mostrarHora(int hora, int minuto)
{
	tft.drawRect(5, 20, 310, 90, BLUE);
	if (hora < 10 && minuto < 10)
	{
		tft.setCursor(10, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print("0");
		tft.setCursor(70, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(hora);

		tft.setCursor(130, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(":");

		tft.setCursor(190, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print("0");
		tft.setCursor(250, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(minuto);
	}
	if (hora < 10 && minuto > 9)
	{
		tft.setCursor(10, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print("0");
		tft.setCursor(70, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(hora);

		tft.setCursor(130, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(":");

		tft.setCursor(190, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(minuto);
	}
	if (hora > 9 && minuto < 10)
	{
		tft.setCursor(10, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(hora);

		tft.setCursor(130, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(":");

		tft.setCursor(190, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print("0");
		tft.setCursor(250, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(minuto);
	}
	if (hora > 9 && minuto > 9)
	{
		tft.setCursor(10, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(hora);

		tft.setCursor(130, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(":");

		tft.setCursor(190, 30);
		tft.setTextSize(10);
		tft.setTextColor(BLACK);
		tft.print(minuto);

	}

	tft.setCursor(120, 204);
	tft.setTextSize(3);
	tft.setTextColor(BLUE);
	tft.print("ATRAS");

	tft.drawRect(36, 195, 242, 38, BLUE);
	return 12;
}
void borrarRegionesEspeciales(int inicioX, int inicioY, int largo, int ancho)
{
	tft.fillRect(inicioX, inicioY, largo, ancho, WHITE);
}
void borrarCaracteres(int inicioX, int inicioY, int tamanoLetra, int numBorrar)
{
	tft.setCursor(inicioX, inicioY);
	tft.setTextSize(tamanoLetra);
	tft.setTextColor(WHITE);
	tft.print(numBorrar);
}
void borrarPantalla()
{
	tft.fillScreen(WHITE);
}
void encendido()
{
	int listaColores[9] = { 0x7BEF,0x0F0F,0xF81F,0xFFE0,0x07FF,0x001F,0xFFFF,0x07E0,0xF800 };
	int color;
	int porcentaje;
	for (int l = 0; l < 280; l = l + 20)
	{
		color = map(l, 0, 280, 0, 8);
		porcentaje = map(l, 0, 280, 0, 100);

		tft.setCursor(80, 30);
		tft.setTextSize(8);
		tft.setTextColor(listaColores[color]);
		tft.print("F");
		tft.setCursor(120, 30);
		tft.setTextSize(8);
		tft.setTextColor(listaColores[color + 1]);
		tft.print("O");
		tft.setCursor(165, 20);
		tft.setTextSize(9);
		tft.setTextColor(listaColores[color]);
		tft.print("O");
		tft.setCursor(215, 20);
		tft.setTextSize(9);
		tft.setTextColor(listaColores[color + 1]);
		tft.print("S");

		tft.setCursor(20, 130);
		tft.setTextSize(3);
		tft.setTextColor(BLACK);
		tft.print("INICIANDO");
		tft.setCursor(20, 160);
		tft.setTextSize(3);
		tft.setTextColor(BLACK);
		tft.print("SISTEMA");

		tft.setCursor(200, 150);
		tft.setTextSize(4);
		tft.setTextColor(GREEN);
		tft.print(porcentaje);

		tft.fillRect(195, 146, 75, 40, WHITE);

		tft.setCursor(275, 150);
		tft.setTextSize(4);
		tft.setTextColor(GREEN);
		tft.print("%");


		tft.setCursor(l + 15, 200);
		tft.setTextSize(4);
		tft.setTextColor(GREEN);
		tft.print("-");
	}
	tft.fillScreen(WHITE);
}
