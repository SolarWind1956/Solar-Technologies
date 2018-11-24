//
//  *************************************************************************
//  Sergej Edgar Heckel
//  Artel3D
//  Schoelkino, Crimea, Ukraine
//  21.10.2000
//  *************************************************************************
//
//---------------------------------------------------------------------------
#ifndef TrigonomH
#define TrigonomH
#include <stdlib.h>
#include <math.h>
#include <Math.hpp>
//---------------------------------------------------------------------------
//  ����� "������� ��������"
//---------------------------------------------------------------------------
class TAngularValue {
public:
    long double Rad;        // ������� ������� ��������
    long double Deg;        // ������������ ������� ������� ��������
    int         DegI;       // ����� ������� ������� ��������
    int         Min;        // ����� ������  ������� ��������
    int         Sec;        // ����� ������� ������� ��������
    int         MSec;       // ����� ������������ ������� ��������
    long double ExtMin;     // ������������ ������ ������� ��������
    long double ExtSec;     // ������������ ������� ������� ��������
//  ������������
    TAngularValue(long double Rad = 0.00);
    TAngularValue(int ParDegI = 0, int ParMin = 0, int ParSec = 0, int ParMSec = 0);
    //� ����������� ����������� - COPY�CONSTRUCTOR
    TAngularValue(const TAngularValue &Copy);
//� �������� ������������ - ASSIGNMENT�OPERATOR.
    TAngularValue& operator= (const TAngularValue &Copy);
//  ������� ��������� ������� ��������
    virtual void SetAngularValue(long double Rad = 0.00);
    virtual void SetAngularValue(int ParDegI = 0, int ParMin = 0, int ParSec = 0, int ParMSec = 0);
//  ������� �������� ������� ������
    void DegIMinSecToDeg(void);
    void DegToDegIMinSec(void);
    void DegIMinSecToRad(void);
    void RadToDegIMinSec(void);
};
#endif
