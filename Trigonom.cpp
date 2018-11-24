//
//  *************************************************************************
//  Sergej Edgar Heckel
//  Artel3D
//  Scholkino, Crimea, Ukraine
//  21.11.2000
//  *************************************************************************
//
//---------------------------------------------------------------------------
//  ����� "������� ��������"
//---------------------------------------------------------------------------
//  � ����������� ���������������, �������� ��������, ��������� ����������
//  ������ ����� ���������� ����������� �������� ����������, ���������������
//  � ������ ��������, � ����������� �� ����, ����� ������ ����������
//  �������������� � ������ ���������� ��� ���� ��������.
//  ��������, ������ � ������� ��������� -
//  ��� ����� �������, ������ � �������, ���� ���������� ������ �� ������������,
//  ��� ��������� � ��������������� ��������.
//  �������������� ��������� ������� �������� ���� ������ � �������.
//  ����������� ������� �������������� ���������, ��������,
//  ������������� ���������� ��������.
//  ������ ����� ���������������� ������� ���������� ���������� ������.
//---------------------------------------------------------------------------
//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!
//  ���� �� ���������� ��������� ������� ������� �� ������������ ��������
//  ������� ������� ��� �� ��������������,
//  ��� ������������� ������ ����������, �� ����� �����
//  ������ ���������� ��������������� ���������, ����� ���� ��������
//  ����� ��������� ������� ��������
//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!
//---------------------------------------------------------------------------
#include "Trigonom.h"
#include <stdio.h>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
//  ������������
TAngularValue::TAngularValue(long double ParRad) {
    SetAngularValue(ParRad);
};
TAngularValue::TAngularValue(int ParDegI, int ParMin, int ParSec, int ParMSec){
    SetAngularValue(ParDegI, ParMin, ParSec, ParMSec);
};
    //� ����������� ����������� - COPY�CONSTRUCTOR
    TAngularValue::TAngularValue(const TAngularValue &Copy){
        Rad     =   Copy.Rad;
        Deg     =   Copy.Deg;
        DegI    =   Copy.DegI; Min = Copy.Min; Sec = Copy.Sec; MSec = Copy.MSec;
    };
//� �������� ������������ - ASSIGNMENT�OPERATOR.
TAngularValue& TAngularValue::operator= (const TAngularValue &Copy) {
        if(this == &Copy) return *this;
        Rad     =   Copy.Rad;
        Deg     =   Copy.Deg;
        DegI    =   Copy.DegI; Min = Copy.Min; Sec = Copy.Sec; MSec = Copy.MSec;
        return *this;
};
//  ������� ��������� ������� ��������
void TAngularValue::SetAngularValue(long double ParRad) {
    Rad  = ParRad;
    // ������ ������� ������������ �������
    Deg = RadToDeg(Rad);
    // ������������� ���������
    while (Deg > 360.00)    Deg -= 360.00;
    while (Deg < -360.00)   Deg += 360.00;
    DegToDegIMinSec();              // � �������� � ����� �������, ������, �������
};
void TAngularValue::SetAngularValue(int ParDegI, int ParMin, int ParSec, int ParMSec){
    if (ParDegI <= 360 && ParDegI >= -360) DegI = ParDegI;
    else {
        DegI = 0;
        ShowMessage(AnsiString("������� � ������������ ���������: ") +
                    IntToStr(DegI));
    };
    if (ParMin < 60 && ParMin > -60) Min = ParMin;
    else {
        Min = 0;
        ShowMessage(AnsiString("������ � ������������ ���������: ") +
                    IntToStr(Min));
    };
    if (ParSec < 60 && ParSec > -60) Sec = ParSec;
    else {
        Sec = 0;
        ShowMessage(AnsiString("������� � ������������ ���������: ") +
                    IntToStr(Sec));
    };
    if (ParMSec < 1000 && ParMSec > -1000) MSec = ParMSec;
    else {
        MSec = 0;
        ShowMessage(AnsiString("������������ � ������������ ���������: ") +
                    IntToStr(MSec));
    };
    DegIMinSecToRad();              // ������������ ����������� � Deg
    // ��� ���� �������� ����������� ����� ��������, ����� � ������:
    if ((Deg > 360.00) || (Deg < -360.00)) {
        ShowMessage(AnsiString("�� � ������������: �������: ") +
                    IntToStr(DegI) +
                    AnsiString(" ������: ") +
                    IntToStr(Min)  +
                    AnsiString(" �������: ") +
                    IntToStr(Sec));
        Min  = 0;
        Sec  = 0;
        MSec = 0;
    };
};
// ������� �������� ������� ������
void TAngularValue::DegIMinSecToDeg(void){
    Deg    =  (long double)DegI
            + (long double)Min  / 60.00L
            + (long double)Sec  / 3600.00L
            + (long double)MSec / 3600000.00L;
};
void TAngularValue::DegToDegIMinSec(void){
    DegI    = Floor(fabsl(Deg));    // ����� ����� - ����� �������
    ExtMin  = (Deg - floorl(Deg)) * 60.0L;
    Min     = Floor(ExtMin);        // ����� ����� - ����� ������
    ExtSec  = (ExtMin - floorl(ExtMin)) * 60.0L;
    Sec     = Floor(ExtSec);        // ����� ����� - ����� �������
    MSec    = Floor((ExtSec - floorl(ExtSec)) * 1000.0L);
    if (Deg < 0.00) {DegI = -DegI; Min = -Min; Sec = -Sec; MSec = -MSec;};
};
void TAngularValue::DegIMinSecToRad(void) {
    DegIMinSecToDeg();              // ������ ������� ������������ �������
    Rad = DegToRad(Deg);            // �� �������� � �������
};
void TAngularValue::RadToDegIMinSec(void){
    Deg = RadToDeg(Rad);            // ������ ������� ������������ �������
    DegToDegIMinSec();              // �� �������� � ����� �������, ������, �������
};
