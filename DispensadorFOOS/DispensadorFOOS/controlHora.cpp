#include "controlHora.h"

#include <RTClib.h>
#include <Wire.h>

RTC_DS3231 rtc;

void inicioModulo() {
	rtc.begin();
	//rtc.adjust(DateTime(2019, 07, 14, 9, 33, 0));
}
int  obtenerHora() {
	DateTime now = rtc.now();
	return now.hour();
}
int  obtenerMinuto() {
	DateTime now = rtc.now();
	return now.minute();
}
int  obtenerSegundo() {
	DateTime now = rtc.now();
	return now.second();
}
