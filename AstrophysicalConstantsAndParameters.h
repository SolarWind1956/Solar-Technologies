#pragma once
//
//	Astrophysical Constants and Parameters
//	Астрофизические константы и параметры
//
#ifndef __ASTRODATA_H_
#define __ASTRODATA_H_

using namespace System;
namespace AstroData {
//
//		Географические координаты
//
//
//		Вспомогательная структура для геограифических координат: градусы, минуты и секунды
//
public ref class strDegMinSec
{
public:
	int Degree;
	int Minute;
	int Second;
public:
	strDegMinSec(void){
		Degree = 0;
		Minute = 0;
		Second = 0;
	};
	strDegMinSec(int initDegree, int initMinute, int initSecond){
		Degree = initDegree;
		Minute = initMinute;
		Second = initSecond;
	};
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~strDegMinSec(){}
};

public ref class clLongitude 
{
	public:
		int Degree;
		int Minute;
		int Second;
		double	Radian;
	public:
	// Конструкторы класса
		clLongitude(void)
		{
			Radian = 0.0;
			Degree = 0;
			Minute = 0;
			Second = 0;
		};
		clLongitude(int initDegree, int initMinute, int initSecond){
			Degree = initDegree;
			Minute = initMinute;
			Second = initSecond;
			Radian = 0.0;
		};
		clLongitude(double	InitRadian){
			Radian = InitRadian;
			Degree = 0;
			Minute = 0;
			Second = 0;
		};
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~clLongitude(){}
};

public ref class clLatitude {
	public:
		// Конструкторы класса
		clLatitude(void)
		{
			Radian = 0.0;
			Degree = 0;
			Minute = 0;
			Second = 0;
		};
		clLatitude(int initDegree, int initMinute, int initSecond){
			Degree = initDegree;
			Minute = initMinute;
			Second = initSecond;
			Radian = 0.0;
		};

		clLatitude(double	InitRadian){
			Radian = InitRadian;
			Degree = 0;
			Minute = 0;
			Second = 0;
		};

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~clLatitude(){}
	public:
		int Degree;
		int Minute;
		int Second;
		double	Radian;
};

public ref class clGeoCoordinates
{
	public:
		// Конструктор по умолчанию - Гринвич на экваторе
		clGeoCoordinates(void)
		{
			clLongitude	Longi(0, 0, 0);		//	Географическая долгота
			clLatitude	Latit(0, 0, 0);		//	Географическая широта
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~clGeoCoordinates(){}
	public:
	clLongitude	Longi;								//	Географическая долгота
	clLatitude	Latit;								//	Географическая широта
};


struct cSunCoordinates
{
	double dZenithAngle;
	double dAzimuth;
};

//
//		Текущие дата и время
//
//DateTime CurrentDateTime = DateTime::Now;			// Текущие время и дата
//
//		Юлианский календарь
//
const	double	JDJan2000Moon	=	2451545.0;		// Юлианский день 
													// в полдень (12 ч, 0 минут, 0 секунд) 
													// 1 января 2000 г.
double	JulianDay;									// Юлианский день
double	JDN;										// Julian Day's Number (JDN) - номер Юлианского дня
double	JD;											// Julian Date	- Юлианская дата

double	dDeclinationOfTheSunRad;					// Склонение Солнца, радианы
int		iDeclinationOfTheSunGMS[3];					// То же в градусах, минутах и секундах

double	dObliquityOfTheEclipticRad;					// Максимальное Склонение Солнца или 
													// Наклонение Солнечной орбиты (Эклиптики) 
													// к небесному экватору, радианы
int		iObliquityOfTheEclipticGMS[3];				// То же в градусах, минутах и секундах

double	dHourAngleOfTheSunRad;						// Часовой угол истинного Солнца
double	dRightAscensionOfTheSunRad;					// Прямое восхождение Солнца
double	dEclipticLongitudeRad; 						// Эклиптическая долгота
double	dMeanLongitudeRad; 							// Средняя Долгота
double	dEccentricity;								// Эксцентриситет солнечной орбиты
double	dTrueAnomalyRad; 							// Истинная Аномалия
double	dMeanAnomalyRad; 							// Средняя Аномалия
double	dArgumentOfPerihelion;						// Аргумент Перигелия
double	dSiderealTime;								// Звёздное Время
double	dGreenwichMeanSiderealTime;					// Всемирное Время (Среднее Звёздное Гринвичское Время)
double	dUniversalTime;								// Всемирное Время (Среднее Звёздное Гринвичское Время)
double	dGreenwichMeanSiderealTimeAt00; 			// Среднее Звёздное Гринвичское Время в полночь
int		iTimeZoneNumber;							// Номер часового пояса (число целых часов, 
													// равное номеру часового пояса)
double	dMeanMotion;								// Среднее движение Солнца
double	dVernalEquinoxRad;							// Точка Весеннего Равноденствия
double	dSunsAzimuthRad;							// Азимут Солнца в горизонтальной системе координат
double	dSunsAltitudeRad;							// Высота Солнца в горизонтальной системе координат

//double	dAngularVelocity;						//Скорость вращения Земли вокруг своей оси
double	dParallaxCorrection;						//Поправка на параллакс

//
//	Astrophysical Constants
//	Астрофизические Константы
//
const double PI = 3.14159265358979323846;			// Число Пи из Википедии




double	dAngularVelocity;							// Скорость вращения Земли вокруг своей оси
													// Астрономическая единица расстояния (AU), м
const	double	dAstronomicalUnitDistance	= 149597870700;					
													// Средний Радиус Земли, км						
const	double	dEarthMeanRadius			= 6378.140;		
													// Cреднее расстояние от Земли до Солнца, м
const	double	MeanEarthSunDistance		= 149618753000;
//
//		Функции для определения астрофизических и иных параметров
//

//	Определение текущего времени в десятичных вещественных часах 
//  по целым часам, минутам и секундам
//
double DecimalHoursCalc(int iHour, int iMinutes, int iSeconds);

//
// Функция определения Номера Юлианского Дня для даты, выраженной днем, месяцем, годом
//
long	JDNCalc(int Day, int Month, int Year);		
//
// Функция определения Юлианской Даты для текущей даты, выраженной днем, месяцем, годом
// и текущим временtv
//
double	JDCalc(int Day, int Month, int Year, int Hour, int Minutes, int Seconds);		
//
// Функция определения максимального склонения Солнца
// 
double	ObliquityOfTheEclipticCalc(double JD, double JDfrom2000);

//
//	Вспомогательные функции преобразования
//
//
//	Функция преобразования радиан в градусы, минуты и секунды
//
array<int>^ RadToDegreesMinSec(double Radians);
//
//	Функция преобразования градусов, минут и секунд в радиан 
//
double DegreesMinSecToRad(array<int>^ DegreesMinSec);

}	// End of namespace AstroData

#endif	//__ASTRODATA_H_