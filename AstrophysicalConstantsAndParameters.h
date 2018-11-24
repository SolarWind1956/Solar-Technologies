#pragma once
//
//	Astrophysical Constants and Parameters
//	��������������� ��������� � ���������
//
#ifndef __ASTRODATA_H_
#define __ASTRODATA_H_

using namespace System;
namespace AstroData {
//
//		�������������� ����������
//
//
//		��������������� ��������� ��� ��������������� ���������: �������, ������ � �������
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
		/// ���������� ��� ������������ �������.
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
	// ������������ ������
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
		/// ���������� ��� ������������ �������.
		/// </summary>
		~clLongitude(){}
};

public ref class clLatitude {
	public:
		// ������������ ������
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
		/// ���������� ��� ������������ �������.
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
		// ����������� �� ��������� - ������� �� ��������
		clGeoCoordinates(void)
		{
			clLongitude	Longi(0, 0, 0);		//	�������������� �������
			clLatitude	Latit(0, 0, 0);		//	�������������� ������
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~clGeoCoordinates(){}
	public:
	clLongitude	Longi;								//	�������������� �������
	clLatitude	Latit;								//	�������������� ������
};


struct cSunCoordinates
{
	double dZenithAngle;
	double dAzimuth;
};

//
//		������� ���� � �����
//
//DateTime CurrentDateTime = DateTime::Now;			// ������� ����� � ����
//
//		��������� ���������
//
const	double	JDJan2000Moon	=	2451545.0;		// ��������� ���� 
													// � ������� (12 �, 0 �����, 0 ������) 
													// 1 ������ 2000 �.
double	JulianDay;									// ��������� ����
double	JDN;										// Julian Day's Number (JDN) - ����� ���������� ���
double	JD;											// Julian Date	- ��������� ����

double	dDeclinationOfTheSunRad;					// ��������� ������, �������
int		iDeclinationOfTheSunGMS[3];					// �� �� � ��������, ������� � ��������

double	dObliquityOfTheEclipticRad;					// ������������ ��������� ������ ��� 
													// ���������� ��������� ������ (���������) 
													// � ��������� ��������, �������
int		iObliquityOfTheEclipticGMS[3];				// �� �� � ��������, ������� � ��������

double	dHourAngleOfTheSunRad;						// ������� ���� ��������� ������
double	dRightAscensionOfTheSunRad;					// ������ ����������� ������
double	dEclipticLongitudeRad; 						// ������������� �������
double	dMeanLongitudeRad; 							// ������� �������
double	dEccentricity;								// �������������� ��������� ������
double	dTrueAnomalyRad; 							// �������� ��������
double	dMeanAnomalyRad; 							// ������� ��������
double	dArgumentOfPerihelion;						// �������� ���������
double	dSiderealTime;								// ������� �����
double	dGreenwichMeanSiderealTime;					// ��������� ����� (������� ������� ����������� �����)
double	dUniversalTime;								// ��������� ����� (������� ������� ����������� �����)
double	dGreenwichMeanSiderealTimeAt00; 			// ������� ������� ����������� ����� � �������
int		iTimeZoneNumber;							// ����� �������� ����� (����� ����� �����, 
													// ������ ������ �������� �����)
double	dMeanMotion;								// ������� �������� ������
double	dVernalEquinoxRad;							// ����� ��������� �������������
double	dSunsAzimuthRad;							// ������ ������ � �������������� ������� ���������
double	dSunsAltitudeRad;							// ������ ������ � �������������� ������� ���������

//double	dAngularVelocity;						//�������� �������� ����� ������ ����� ���
double	dParallaxCorrection;						//�������� �� ���������

//
//	Astrophysical Constants
//	��������������� ���������
//
const double PI = 3.14159265358979323846;			// ����� �� �� ���������




double	dAngularVelocity;							// �������� �������� ����� ������ ����� ���
													// ��������������� ������� ���������� (AU), �
const	double	dAstronomicalUnitDistance	= 149597870700;					
													// ������� ������ �����, ��						
const	double	dEarthMeanRadius			= 6378.140;		
													// C������ ���������� �� ����� �� ������, �
const	double	MeanEarthSunDistance		= 149618753000;
//
//		������� ��� ����������� ��������������� � ���� ����������
//

//	����������� �������� ������� � ���������� ������������ ����� 
//  �� ����� �����, ������� � ��������
//
double DecimalHoursCalc(int iHour, int iMinutes, int iSeconds);

//
// ������� ����������� ������ ���������� ��� ��� ����, ���������� ����, �������, �����
//
long	JDNCalc(int Day, int Month, int Year);		
//
// ������� ����������� ��������� ���� ��� ������� ����, ���������� ����, �������, �����
// � ������� ������tv
//
double	JDCalc(int Day, int Month, int Year, int Hour, int Minutes, int Seconds);		
//
// ������� ����������� ������������� ��������� ������
// 
double	ObliquityOfTheEclipticCalc(double JD, double JDfrom2000);

//
//	��������������� ������� ��������������
//
//
//	������� �������������� ������ � �������, ������ � �������
//
array<int>^ RadToDegreesMinSec(double Radians);
//
//	������� �������������� ��������, ����� � ������ � ������ 
//
double DegreesMinSecToRad(array<int>^ DegreesMinSec);

}	// End of namespace AstroData

#endif	//__ASTRODATA_H_