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
//  �������������� ���������
const long double EclipticEccentricity = 0.016751L;
//  Earth Mean Radius (km)
//  ������� ������ ����� (��)
const long double EarthMeanRadius = 6371.01;
//  Astronomical Unit (km)
//  ��������������� ������� ?????? (��)
//  Tag of the summer time
const long double AstronomicalUnit = 149597890.00;
//  ������� ������� �������
int WinterTime;
//  Number of the Time Zone
//  ����� ���������� ����� ��� �����
int myTimeZoneNum = 3;
//  Siderial cycle time of the Earth around of the Sun
//  ������������ ������ ��������� ����� ������ ������
long double SiderialCycleTime(int iYear);
//  Angular velocity of the Sun motion on the celestial orb
//  ������� �������� �������� ������ �� �������� �����
//  _______________________________________________________________
//
long double JulianDay(TDateTime DateTime);
//  _______________________________________________________________
long double SunVelocity();
//  Longitude of a time zone
//  ������� ���������� �����
long double TimeZoneLongitude(int myTimeZoneNum);
//  Longitude of a place
//  ������� ��������� (������, ��� ���������� ������)
long double PlaceLongitude();
//  Latitude of terrain
//  ������ ��������� (������, ��� ���������� ������)
long double TerrainLatitude();
//  Maximum declination of the Sun  (Obliquity of the Ecliptic)
//  ������������ ��������� ������ (������ ��������� � ��������� ��������)
long double MaxSunDeclination(int iYear);
long double EclipticObliquity(TDateTime DateTime);
//  The number of day of vernal equinox
//  ����� ��� ��������� �������������
inline int VernalEquinoxDay() {return 81;};
//  The number of day of Perihelium
//  ����� ��� ���������
inline int DayOfPerihelium() {return 2;};
//  Right ascension of the Sun
//  ������ ����������� ������
long double RightSunAscension(int iDayOfYear, int iYear);
long double RightAscension(TDateTime DateTime);
//  Declination of the Sun
//  ��������� ������
long double SunDeclination(int iDayOfYear, int iYear);
long double Declination(TDateTime DateTime);
//  ---------------------------------------------------------------
//  Equation of time from an eccentricity of an ecliptic
//  ��������� ������� �� ��������������� ���������
//  ---------------------------------------------------------------
//  Mean anomaly
//  ������� ��������
long double MeanAnomaly(int iDayOfYear, int iYear);
//  True anomaly
//  �������� ��������
long double TrueAnomaly(int iDayOfYear, int iYear);
//  !!!
long double EclipticEccentriTimeEquation(int iDayOfYear, int iYear);
//  ---------------------------------------------------------------
//  Equation of time from a declination of an ecliptic
//  ��������� ������� �� ������� ���������
//  ---------------------------------------------------------------
long double EclipticDeclinatTimeEquation(int iDayOfYear, int iYear);
//  ---------------------------------------------------------------
//  ��������� �������
//  Equation of time
//  ---------------------------------------------------------------
long double TimeEquation(int iDayOfYear, int iYear);
// ����� ��������� ������
// Time of true midday
long double TrueMiddayTime(System::TDateTime DateTime);
//  Day of Year
//  ���� ���� (1 - 365)
int DayOfYear(System::TDateTime DateTime);
//
//  ---------------------------------------------------------------
//  Corrections
//  ��������
//  ---------------------------------------------------------------
//  Zenithal Refraction Correction
//  ����������� �������� �� ���������
long double ZenithRefractionCorrect(long double Zeinith,
                                    long double Temperature,
                                    long double AtmosphericPressure);

//  Zenithal Parallax Correction
//  ����������� �������� �� ��������� (����������� �������� ����������,
//  �������������, ��������� ������ �������)
long double ZenithParallaxCorrect(long double Zeinith);

//  ---------------------------------------------------------------
//  'TSun' Class of the Sun
//  ---------------------------------------------------------------

class TSun
{
public:
    TAlgVector SunVect;                     // ������ ������
    long double Radius;                     // ������ ����� ������ �� ������
    // ���������� ������ ��� �������� �������� � �������������� ������� ���������
    // ����������� ���������� ���������
    void SetCoordinate(TDateTime DateTime);
    // ����������� ����������� ���������
    // ������ ������ ��� ����������
    // ������ ������
    long double SolarAzimuth();
    // ���������� ������ �� ������
    void Draw(TFormCanvas*);
};
#endif
