//
//  *************************************************************************
//  Sergej Edgar Heckel
//  Artel3D
//  Schoelkino, Crimea, Ukraine
//  11.10.2000
//  *************************************************************************
//
//---------------------------------------------------------------------------
#include <vcl.h>
#include "AstrClas.h"
#include "FormCanv.h"
#include "Math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//  Siderial cycle time of the Earth around of the Sun
//  Сидерический период обращения Земли вокруг Солнца (тропический год)
//  содержит количество средних суток
long double SiderialCycleTime(int Year){
    // Year - время, выраженное в юлианских столетиях от начала 1900 года,
    // январь, 0, 12ч эфемеридного времени.
    return 365.24219879L - 0.00000614L * (Year - 1900);
};
//  Angular velocity of the Sun motion on the celestial orb
//  Угловая Скорость движения Солнца по небесной сфере
long double SunVelocity() {
TAngularValue *SV;
    SV = new TAngularValue(15, 0, 0);
    return SV->Rad;                 // Radians per hour
};
//  Longitude of a time zone
//  Долгота временного пояса
long double TimeZoneLongitude(int myTimeZoneNum) {
TAngularValue *TZL;
    TZL = new TAngularValue(0);
    TZL->SetAngularValue(15 * myTimeZoneNum, 0,0);
    return TZL->Rad;                 // Radians
};
//  Longitude of a place
//  Долгота местности (данной, где установлен объект)
long double PlaceLongitude() {
TAngularValue *PL;
    PL = new TAngularValue(35, 51, 54);
    return PL->Rad;                 // Radians
};
//  Latitude of terrain
//  Широта местности (данной, где установлен объект)
long double TerrainLatitude() {
TAngularValue *TL;
    TL = new TAngularValue(45, 24, 12);
    return TL->Rad;                 // Radians
};
//  ______________________________________________________________________
//  Maximum declination of the Sun  (Obliquity of the Ecliptic)
//  Максимальное склонение Солнца (Наклон эклиптики к небесному экватору)
//  23 27' 8"",26 - 0",468 (t - 1900);
long double MaxSunDeclination(int iYear) {
TAngularValue *MSD;
TAngularValue *B;
    MSD = new TAngularValue(23, 27, 8, 260);    // Radians
    B   = new TAngularValue(0, 0, 0, 468);      // Radians
    return MSD->Rad - B->Rad * (iYear - 1900);  // Radians
};
// Алгоритм PSA (Plataforma Solar de Almeria)
long double EclipticObliquity(TDateTime DateTime){
//    return 0.4090928 - 6.2140E-10 * JulianDay + 0.396E-4 * cosl(Omega);
};
//  ______________________________________________________________________
// Direct ascension of the Sun
// Прямое восхождение Солнца
long double RightSunAscension(int iDayOfYear, int iYear) {
    long double Result = 2.0L * M_PI
                       / SiderialCycleTime(iYear)
                       * (long double)(iDayOfYear - VernalEquinoxDay());

   	return  Result >= 0.00 ? Result : Result += 2.0L * M_PI;
};
// Алгоритм PSA (Plataforma Solar de Almeria)
long double RightAscension(TDateTime DateTime){
//    long double eo = EclipticObliquity(JulianDay, Omega){
//    return ArcTan2(cosl()
};
//  ______________________________________________________________________
// Declination of the Sun
// Склонение Солнца
long double SunDeclination(int iDayOfYear, int iYear) {
    long double MaxSunDecl  = MaxSunDeclination(iYear);
    long double Result      = ArcSin(sin(MaxSunDecl)
                            * sin(RightSunAscension(iDayOfYear, iYear)));
   	return  Result;
};
// ---------------------------------------------------------------
// Equation of time from an eccentricity of an ecliptic
// Уравнение времени от эксцентриситета эклиптики
// ---------------------------------------------------------------
// Average anomaly
// Средняя аномалия
long double AverageAnomaly(int iDayOfYear, int iYear){
    long double Result =  2.0L * M_PI
                        / SiderialCycleTime(iYear)
                        * (iDayOfYear - DayOfPerihelium());
   	return  Result;
};
// True anomaly
// Истинная аномалия
long double TrueAnomaly(int iDayOfYear, int iYear){
    long double AverAnom = AverageAnomaly(iDayOfYear, iYear);
    long double Result = (long double)(
                        AverAnom
                      + 2.0L * EclipticEccentricity * sin(AverAnom)
                      + 5.0L / 4.0L * Power(EclipticEccentricity, 2.00L)
         			       	        * sin(2.0L * AverAnom)
                                      );
   	return  Result;
};
// Собственно Уравнение времени от эксцентриситета эклиптики
long double EclipticEccentriTimeEquation(int iDayOfYear, int iYear) {
    long double AverAnom = AverageAnomaly(iDayOfYear, iYear);
    long double Result = (long double)  (
                          2.0L * EclipticEccentricity * sin(AverAnom)
                        + 5.0L / 4.0L * Power(EclipticEccentricity, 2.00L)
                                      * sin(2.0L * AverAnom)
                                        );
   	return  Result;
};
// ---------------------------------------------------------------
// Equation of time from a declination of an ecliptic
// Уравнение времени от наклона эклиптики
// ---------------------------------------------------------------
long double EclipticDeclinatTimeEquation(int iDayOfYear, int iYear){
    long double SunAscen = RightSunAscension(iDayOfYear, iYear);
    long double SinDirSunAscenPr = (long double) (
                                    sin(SunAscen)
                                  * cos(MaxSunDeclination(iYear))
                                  / cos(SunDeclination(iDayOfYear, iYear))
                                                  );
    long double Result = ArcSin (SinDirSunAscenPr);

    // Определим угол с учётом знака косинуса
    if (cos(SunAscen) < 0) Result = M_PI - Result;
    else if (Result < 0.00) Result += 2.0L * M_PI;

   	return  Result -= SunAscen;;
};
//  Уравнение времени
//  Equation of time
long double TimeEquation(int iDayOfYear, int iYear) {
    long double EclEccTE = EclipticEccentriTimeEquation(iDayOfYear, iYear);
    long double EclDecTE = EclipticDeclinatTimeEquation(iDayOfYear, iYear);
    long double Result = EclEccTE + EclDecTE;
     	return  Result;
};
// Время истинного полдня
// Time of true midday
long double TrueMiddayTime(System::TDateTime DateTime) {
    int iDayOfYear;
    Word iYear, iMonth, iDay;
    DecodeDate(DateTime, iYear, iMonth, iDay);      // Распакуем дату
    iDayOfYear  = DayOfYear(DateTime);              // День года
    long double Result =  12.00L;
                Result += (TimeZoneLongitude(myTimeZoneNum) - PlaceLongitude())
                        / SunVelocity();
                Result += TimeEquation(iDayOfYear, iYear)
                        / SunVelocity();
                Result -= (long double)WinterTime;
   	return  Result <= 24.00 ? Result : Result - 24.00;
};
//  ---------------------------------------------------------------
//  Day of Year
//  День года (1, 2, 3, ..., 360, ...)
int DayOfYear(System::TDateTime DateTime){
int DaysOfMonthes [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
Word Year, Month, Day;
int Result = 0;
    DecodeDate(DateTime, Year, Month, Day);         // Распакуем дату
    if (IsLeapYear(Year)) DaysOfMonthes[1] = 29;    // В високосном году
                                                    // в феврале 29 дней
    // Считаем сумму дней до начала текущего месяца
    int i = 0;
    while (i < Month - 1) Result += DaysOfMonthes[i++];
    // и добавляем день в месяце текущей даты
    return Result += Day;
};
//
//  ---------------------------------------------------------------
//  Corrections
//  Поправки
//  ---------------------------------------------------------------
//  Zenithal Refraction Correction
//  Зенитальная поправка на рефракцию (уменьшает зенитное расстояние,
//  следовательно, увеличивает высоту светила)
long double ZenithRefractionCorrect(long double Zeinith,
                                    long double Temperature,
                                    long double AtmosphericPressure) {
    TAngularValue *K   = new TAngularValue(0, 0, 60, 200);      // Radians
    long double Result = K->Rad * AtmosphericPressure
                       * 273.16 / (273.16 + Temperature)
                       * Tan(Zeinith);
    return Result;
};
//  Zenithal Parallax Correction
//  Зенитальная поправка на параллакс (увеличивает зенитное расстояние,
//  следовательно, уменьшает высоту светила)
long double ZenithParallaxCorrect(long double Zeinith) {
    return EarthMeanRadius / AstronomicalUnit * sinl(Zeinith);
};

//  ---------------------------------------------------------------
//  'TSun' Class of the Sun
//  ---------------------------------------------------------------
//  Определение прямоугольных координат вектора Солнца
void TSun::SetCoordinate(TDateTime DateTime)
{
    // Переменные год, месяц, день
    Word Year, Month, Day;
    Word Hour, Minute, Seconds, MS;
    // Распакуем дату и время
    DecodeDate(DateTime, Year, Month, Day);
    DecodeTime(DateTime, Hour, Minute, Seconds, MS);
    // Определим день года
    int iDayOfYear = DayOfYear(DateTime);
    // Широта местности
    long double Latitude = TerrainLatitude();
    // Склонение солнца
    long double Declination = SunDeclination(iDayOfYear, Year);
    // Часовой угол Солнца
    long double ldTime  = (long double)Hour
                        + (long double)Minute / 60.00L
                        + (long double)Seconds / 3600.00L;
    long double TMTime      = TrueMiddayTime(DateTime);
    long double HourAngle   = 2.00L * M_PI / 24.00L * (ldTime - TMTime);

    // Координаты вектора Солнца
    SunVect.X_Vect  = - cosl(Latitude) * sinl(Declination)
                    + sinl(Latitude)   * cosl(Declination) * cosl(HourAngle);
    SunVect.Y_Vect  = cosl(Declination)* sinl(HourAngle);
    SunVect.Z_Vect  =   sinl(Latitude) * sinl(Declination)
                    + cosl(Latitude)   * cosl(Declination) * cosl(HourAngle);
    SunVect.VectMagnitude();
    return;
};
// в горизонтальной системе координат
// Высота Солнца над горизонтом
// Азимут Солнца (рад)
long double TSun::SolarAzimuth(){
    return ArcTan2(SunVect.Y_Vect, SunVect.X_Vect);
};

//  Прорисовка Солнца на экране
void TSun::Draw(TFormCanvas* FormCanv){
    long double X_Sun   = FormCanv->FormCenter.x
                        + (SunVect * FormCanv->FormBasicVectorX)
                        * (FormCanv->WorkForm->Height / 2);
    long double Y_Sun   = FormCanv->FormCenter.y +
                        + (SunVect * FormCanv->FormBasicVectorY)
                        * (FormCanv->WorkForm->Height / 2);
    FormCanv->WorkForm->Canvas->Ellipse(X_Sun + Radius, Y_Sun + Radius,
                              X_Sun - Radius, Y_Sun - Radius);
};




