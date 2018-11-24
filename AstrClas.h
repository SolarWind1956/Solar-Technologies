//
//  *************************************************************************
//  Sergej Edgar Heckel
//  Artel3D
//  Schoelkino, Crimea, Ukraine
//  11.10.2000
//  *************************************************************************
//
//---------------------------------------------------------------------------
#ifndef astrclasH
#define astrclasH
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <math.h>
#include <Math.hpp>
#include <SysUtils.hpp>
#include "Trigonom.h"
#include "Algebra.h"
#include "FormCanv.h"
//  Eccentricity of an ecliptic
//  Эксцентриситет эклиптики
const long double EclipticEccentricity = 0.016751L;
//  Earth Mean Radius (km)
//  Средний радиус земли (км)
const long double EarthMeanRadius = 6371.01;
//  Astronomical Unit (km)
//  Астрономическая единица ?????? (км)
//  Tag of the summer time
const long double AstronomicalUnit = 149597890.00;
//  Признак Зимнего времени
int WinterTime;
//  Number of the Time Zone
//  Номер временного пояса для Крыма
int myTimeZoneNum = 3;
//  Siderial cycle time of the Earth around of the Sun
//  Сидерический период обращения Земли вокруг Солнца
long double SiderialCycleTime(int iYear);
//  Angular velocity of the Sun motion on the celestial orb
//  Угловая Скорость движения Солнца по небесной сфере
//  _______________________________________________________________
//
long double JulianDay(TDateTime DateTime);
//  _______________________________________________________________
long double SunVelocity();
//  Longitude of a time zone
//  Долгота временного пояса
long double TimeZoneLongitude(int myTimeZoneNum);
//  Longitude of a place
//  Долгота местности (данной, где установлен объект)
long double PlaceLongitude();
//  Latitude of terrain
//  Широта местности (данной, где установлен объект)
long double TerrainLatitude();
//  Maximum declination of the Sun  (Obliquity of the Ecliptic)
//  Максимальное склонение Солнца (Наклон эклиптики к небесному экватору)
long double MaxSunDeclination(int iYear);
long double EclipticObliquity(TDateTime DateTime);
//  The number of day of vernal equinox
//  Номер дня весеннего равноденствия
inline int VernalEquinoxDay() {return 81;};
//  The number of day of Perihelium
//  Номер дня перигелия
inline int DayOfPerihelium() {return 2;};
//  Right ascension of the Sun
//  Прямое восхождение Солнца
long double RightSunAscension(int iDayOfYear, int iYear);
long double RightAscension(TDateTime DateTime);
//  Declination of the Sun
//  Склонение Солнца
long double SunDeclination(int iDayOfYear, int iYear);
long double Declination(TDateTime DateTime);
//  ---------------------------------------------------------------
//  Equation of time from an eccentricity of an ecliptic
//  Уравнение времени от эксцентриситета эклиптики
//  ---------------------------------------------------------------
//  Mean anomaly
//  Средняя аномалия
long double MeanAnomaly(int iDayOfYear, int iYear);
//  True anomaly
//  Истинная аномалия
long double TrueAnomaly(int iDayOfYear, int iYear);
//  !!!
long double EclipticEccentriTimeEquation(int iDayOfYear, int iYear);
//  ---------------------------------------------------------------
//  Equation of time from a declination of an ecliptic
//  Уравнение времени от наклона эклиптики
//  ---------------------------------------------------------------
long double EclipticDeclinatTimeEquation(int iDayOfYear, int iYear);
//  ---------------------------------------------------------------
//  Уравнение времени
//  Equation of time
//  ---------------------------------------------------------------
long double TimeEquation(int iDayOfYear, int iYear);
// Время истинного полдня
// Time of true midday
long double TrueMiddayTime(System::TDateTime DateTime);
//  Day of Year
//  День года (1 - 365)
int DayOfYear(System::TDateTime DateTime);
//
//  ---------------------------------------------------------------
//  Corrections
//  Поправки
//  ---------------------------------------------------------------
//  Zenithal Refraction Correction
//  Зенитальная поправка на рефракцию
long double ZenithRefractionCorrect(long double Zeinith,
                                    long double Temperature,
                                    long double AtmosphericPressure);

//  Zenithal Parallax Correction
//  Зенитальная поправка на параллакс (увеличивает зенитное расстояние,
//  следовательно, уменьшает высоту светила)
long double ZenithParallaxCorrect(long double Zeinith);

//  ---------------------------------------------------------------
//  'TSun' Class of the Sun
//  ---------------------------------------------------------------

class TSun
{
public:
    TAlgVector SunVect;                     // Вектор Солнца
    long double Radius;                     // Радиус диска Солнца на экране
    // Координаты солнца при суточном движении в горизонтальной системе координат
    // Определение декартовых координат
    void SetCoordinate(TDateTime DateTime);
    // Определение сферических координат
    // Высота Солнца над горизонтом
    // Азимут Солнца
    long double SolarAzimuth();
    // Прорисовка Солнца на экране
    void Draw(TFormCanvas*);
};
#endif
