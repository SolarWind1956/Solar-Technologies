//
//	Astrophysical Constants and Parameters
//	��������������� ��������� � ���������
//
#include	"stdafx.h"
#include	<math.h>

using namespace Solar Technologies;
#include	"AstrophysicalConstantsAndParameters.h"
//
//	����������� �������� ������� � ���������� ������� ����� 
//  �� ����� �����, ������� � ��������
//
double DecimalHoursCalc(int iHour, int iMinutes, int iSeconds) {

	double dDecimalHours = (double)iHour + 
						   (double)iMinutes / 60.0 + 
						   (double)iSeconds / 3600.0;
	return dDecimalHours;	//	���������� ���������� ������� ���� �������
	}
//
//	����������� �������� ������� � ����� �����, ������� � �������� 
//	�� �������� ���������� ������� �����
//
array<int>^ DecimalHoursToHourMinSec(double dDecimalHours)	{
	array<int>^ iHourMinSec = {0, 0, 0};				//	������ � ������ ������, ��������, ���������
	
	iHourMinSec[0]	=	(int)(dDecimalHours);			//	����� ����
	double Minutes	=	dDecimalHours - iHourMinSec[0];	//	������� ������ � �������, ��� ������� ����� ������ ����
	iHourMinSec[1]	=	(int)(Minutes * 60.0);			//	����� ������
	double Seconds	=	Minutes * 60.0;					//	������� �������
	iHourMinSec[2]	=	(int)((Seconds - iHourMinSec[1]) * 60.0); // ����� �������

	return iHourMinSec;			//	���������� ��������� �� ������ c ������, �������� � ���������
	}
//
// ������������ ��������� ������ ��� ���������� ��������� ������ (���������) 
// � ��������� ��������, �������
//
double	ObliquityOfTheEclipticCalc(double JD, double JDJan2000Moon){
		//	���������:
		//	JD	-	���� �� ���������� ��������� (��������� ����)
		//	
		double dOmega				= 2.1429 - 0.0010394594 * (JD - JDJan2000Moon);
		double dEclipticObliquity	= 0.4090928 - 6.2140E-9 * (JD - JDJan2000Moon) + 
									  0.0000396 * cos(dOmega);
		return dEclipticObliquity;
	}

//
//		������� ��� ����������� ��������������� � ���� ����������
//
//		������� ����������� ������ ����������� ���
//		��� ����, ���������� ����, �������, �����
//
long	JDNCalc(int Day, int Month, int Year){		
	// ���������� ��������������� ��������� �� �������� ���������� ���������
	long lAux1	= (Month - 14) / 12;
	long lAux2	=  Year + 4800 + lAux1;
	long lAux3	=  Month - 2 - lAux1 * 12;
	// ���������� ���������� ��������� ���� 
	// (������ ����� - ��� ����������� ���������� ��� ������������� �������)
	long dJDN	= (1461 * (lAux2)) / 4  + 
		          ( 367 * (lAux3)) / 12 - 
				  (   3 * ((lAux2 + 100) / 100)) / 4 + Day - 32075;
	return dJDN;
	}
//
//	������� ����������� ��������� ���� ��� ������� ����, ���������� ����, �������, �����
//	� ������� ��������
//
double	JDCalc(int Day, int Month, int Year, int UTHour, int UTMinutes, int UTSeconds){
	long	JDN	= JDNCalc(Day, Month, Year);	// ����� ���������� ���
	// ��������� ����� �� �������� � ������� �����  
	double	dDecimalUTHours = DecimalHoursCalc(UTHour, UTMinutes, UTSeconds);	
	// ��������� ����
	// ���������� �������� ���������� ��������� ���� � ������� ����������� ���� � 
	// �������� ������� ���, ����������� �������� ������ ���������� ������� 
	// �� ����, ������� �� ��������
	double	dJulianDate = (double)JDN - 0.5 + dDecimalUTHours / 24.0;

	return	dJulianDate ;
	}		

//
//	��������������� ������� �������������� �������
//
//
//	������� �������������� ������ � �������, ������ � �������
//
array<int>^ RadToDegreesMinSec(double Radians){
	array<int>^ DegreesMinSec = {0, 0, 0};				//	������ � �������� ���������, �������� � ���������
	const double PI = System::Math::PI;					//	����� �� �� ������ ViSt-2010 System::Math
               	      

	double Degrees		=  Radians * 360  / 2 / PI;		//	��������� ������� ������� 
	DegreesMinSec[0]	=  (int)(Degrees);				//	����� �������	
	double Minutes		=  Degrees - DegreesMinSec[0];	//	������� ������ � �������, ��� ����� ������ �������
	DegreesMinSec[1]	=  (int)(Minutes * 60.0);		//	����� ������
	double Seconds		=	Minutes * 60.0;				//	������� �������
	DegreesMinSec[2]	=  (int)((Seconds - DegreesMinSec[1]) * 60.0); // ����� �������

	return DegreesMinSec;								//	���������� ��������� �� ������ c ���������, �������� � ���������
	}
//
//	������� �������������� ��������, ����� � ������ � ������� 
//
double DegreesMinSecToRad(array<int>^ DegreesMinSec){
	const double PI = 3.14159265358;			// ����� �� �� ���������
	// ����������� �������, ������ � ������� � �������
	double Radians = 2.0 * PI / 360.0 * ((double)DegreesMinSec[0] +
										 (double)DegreesMinSec[1] / 60.0 +
										 (double)DegreesMinSec[2] / 3600.0);
	return Radians;								// ���������� �������
	}