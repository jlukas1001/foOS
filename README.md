# foOS
Proyecto de un dispensador de alimento para animales basado en Arduino, cuenta con funcionalidad bluetooth y wifi, permite dispensar alimento n veces al día desde cualquier parte del mundo donde se cuente con conexión a internet, además, el recipiente contiene una báscula la cual entrega la cantidad exacta de comida. El diseño físico fue impreso en 3d, material PLA, diseñado en rhinoceros 3D

## Código Arduino

- `DispensadorFOOS.ino`: Aplicación principal, corre todos los módulos.
- 'tactil': Modulo que gestiona la parte táctil de la pantalla con la que el usuario interactúa.
- `moduloWifi`: Gestiona la conexión, envío de paquetes, entre otros. 
- `informacionBalanza`: Modulo que controla el peso de la comida que cae en el plato.
- `horarioComidas`: Modulo encargado de controlar el horario de alimentación.
- `diseño`: "Front end" de la aplicación, es la parte visual de la interfaz con la que el usuario interactua en la pantalla.
- `datosMemoria`: Modulo que administra los datos guardados en la memoria EEPROM, como: horario de comidas, conexión wifi, entre otros.
- `controLeds`: Modulo encargado de manejar 4 leds los cuales indican el estado/potencia de la conexión wifi,
- `controlHora`: Modulo encargado de gestionar el reloj D3132.
- `animacionDeInicio`: Animación inicial que se muestra mientras cargan los componentes.

## Diseño 3D

El diseño 3D es un diseño modular, el cual permite el armado de partes mecánicas complejas, costa de tres partes: 

1) Plato de comida
2) Mecanismo de caída comida
3) Parte externa del dispensador

En el repo se puede encontrar una tabla de Excel `Costos dispensador de alimento` el cual indica el material gastado, tiempos de impresión y costo aproximado.
Los datos de peso y tiempo fueron calculados para una Ender3 con capa 0.2 y un relleno al 20%.

## Materiales

- Arduino mega 
- Modulo reloj DS3231
- ESP8266
- modulo BT HC-05
- Servo motor 20kg
- leds (x4)
- Celda de carga HX711 + ADC
- Pantalla Táctil Lcd Tft De 2.0
- Tornillos m3 x 6mmcomponentes.
