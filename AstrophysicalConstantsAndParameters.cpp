//
//	Astrophysical Constants and Parameters
//	Астрофизические константы и параметры
//
#include	"stdafx.h"
#include	<math.h>

using namespace Solar Technologies;
#include	"AstrophysicalConstantsAndParameters.h"
//
//	Определение текущего времени в десятичных дробных часах 
//  по целым часам, минутам и секундам
//
double DecimalHoursCalc(int iHour, int iMinutes, int iSeconds) {

	double dDecimalHours = (double)iHour + 
						   (double)iMinutes / 60.0 + 
						   (double)iSeconds / 3600.0;
	return dDecimalHours;	//	Возвращаем десятичные дробные часы времени
	}
//
//	Определение текущего времени в целых часах, минутах и секундах 
//	по величине десятичных дробных часов
//
array<int>^ DecimalHoursToHourMinSec(double dDecimalHours)	{
	array<int>^ iHourMinSec = {0, 0, 0};				//	Массив с целыми часами, минутами, секундами
	
	iHourMinSec[0]	=	(int)(dDecimalHours);			//	Целые часы
	double Minutes	=	dDecimalHours - iHourMinSec[0];	//	Дробные минуты и секунды, как дробная часть одного часа
	iHourMinSec[1]	=	(int)(Minutes * 60.0);			//	Целые минуты
	double Seconds	=	Minutes * 60.0;					//	Дробные секунды
	iHourMinSec[2]	=	(int)((Seconds - iHourMinSec[1]) * 60.0); // Целые секунды

	return iHourMinSec;			//	Возвращаем указатель на массив c часами, минутами и секундами
	}
//
// Максимальное Склонение Солнца или Наклонение Солнечной орбиты (Эклиптики) 
// к небесному экватору, радианы
//
double	ObliquityOfTheEclipticCalc(double JD, double JDJan2000Moon){
		//	Параметры:
		//	JD	-	Дата по Юлианскому календарю (Юлианская дата)
		//	
		double dOmega				= 2.1429 - 0.0010394594 * (JD - JDJan2000Moon);
		double dEclipticObliquity	= 0.4090928 - 6.2140E-9 * (JD - JDJan2000Moon) + 
									  0.0000396 * cos(dOmega);
		return dEclipticObliquity;
	}

//
//		Функции для определения астрономических и иных параметров
//
//		Функция определения Номера Юлиансткого Дня
//		для даты, выраженной днем, месяцем, годом
//
long	JDNCalc(int Day, int Month, int Year){		
	// Определяем вспомогательные параметры по правилам Юлианского календаря
	long lAux1	= (Month - 14) / 12;
	long lAux2	=  Year + 4800 + lAux1;
	long lAux3	=  Month - 2 - lAux1 * 12;
	// Определяем собственно Юлианский день 
	// (скобки важны - для правильного округления при целочисленном делении)
	long dJDN	= (1461 * (lAux2)) / 4  + 
		          ( 367 * (lAux3)) / 12 - 
				  (   3 * ((lAux2 + 100) / 100)) / 4 + Day - 32075;
	return dJDN;
	}
//
//	Функция определения Юлианской Даты для текущей даты, выраженной днем, месяцем, годом
//	и текущим временем
//
double	JDCalc(int Day, int Month, int Year, int UTHour, int UTMinutes, int UTSeconds){
	long	JDN	= JDNCalc(Day, Month, Year);	// Номер Юлианского дня
	// Определим время по Гринвичу в дробных часах  
	double	dDecimalUTHours = DecimalHoursCalc(UTHour, UTMinutes, UTSeconds);	
	// Юлианская Дата
	// Необходимо привести полученный Юлианский день к средней Гринвичской ночи и 
	// текущему времени дня, выраженному дробными часами всемирного времени 
	// то есть, времени по Гринвичу
	double	dJulianDate = (double)JDN - 0.5 + dDecimalUTHours / 24.0;

	return	dJulianDate ;
	}		

//
//	Вспомогательные функции преобразования величин
//
//
//	Функция преобразования радиан в градусы, минуты и секунды
//
array<int>^ RadToDegreesMinSec(double Radians){
	array<int>^ DegreesMinSec = {0, 0, 0};				//	Массив с угловыми градусами, минутами и секундами
	const double PI = System::Math::PI;					//	Число Пи из класса ViSt-2010 System::Math
               	      

	double Degrees		=  Radians * 360  / 2 / PI;		//	Определим дробные градусы 
	DegreesMinSec[0]	=  (int)(Degrees);				//	Целые градусы	
	double Minutes		=  Degrees - DegreesMinSec[0];	//	Дробные минуты и секунды, как часть одного градуса
	DegreesMinSec[1]	=  (int)(Minutes * 60.0);		//	Целые минуты
	double Seconds		=	Minutes * 60.0;				//	Дробные секунды
	DegreesMinSec[2]	=  (int)((Seconds - DegreesMinSec[1]) * 60.0); // Целые секунды

	return DegreesMinSec;								//	Возвращаем указатель на массив c градусами, минутами и секундами
	}
//
//	Функция преобразования градусов, минут и секунд в радианы 
//
double DegreesMinSecToRad(array<int>^ DegreesMinSec){
	const double PI = 3.14159265358;			// Число Пи из Википедии
	// Преобразуем градусы, минуты и секунды в радианы
	double Radians = 2.0 * PI / 360.0 * ((double)DegreesMinSec[0] +
										 (double)DegreesMinSec[1] / 60.0 +
										 (double)DegreesMinSec[2] / 3600.0);
	return Radians;								// Возвращаем радианы
	}