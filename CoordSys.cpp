//  *************************************************************************
//  Sergej Edgar Heckel
//  Artel3D
//  Schoelkino, Crimea, Ukraine
//  14.05.2001
//  *************************************************************************
#include <vcl.h>
#pragma hdrstop

#include "CoordSys.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
// ����� "��������� ������������� (�������������) ������� ���������"
// ���������� ���� ������� ���������
void CartesianOrthographicCoordinateSystem::Draw(TFormCanvas* FormCanv){
    // ���������� ������� ��� �� �� ������
    int EndX_X = X_Center
               + FormCanv->WorkForm->Height / 2
               * (FormCanv->FormBasicVectorX * BasicVectorX);
    int EndX_Y = Y_Center
               + FormCanv->WorkForm->Height / 2
               * (FormCanv->FormBasicVectorY * BasicVectorX);
    // ���������� ������� ��� �Y �� ������
    int EndY_X = X_Center
               + FormCanv->WorkForm->Height / 2
               * (FormCanv->FormBasicVectorX * BasicVectorY);
    int EndY_Y = Y_Center
               + FormCanv->WorkForm->Height / 2 * (FormCanv->FormBasicVectorY * BasicVectorY);
    // ���������� ������� ��� �Z �� ������
    int EndZ_X = X_Center
               + FormCanv->WorkForm->Height / 2 * (FormCanv->FormBasicVectorX * BasicVectorZ);
    int EndZ_Y = Y_Center
               + FormCanv->WorkForm->Height / 2 * (FormCanv->FormBasicVectorY * BasicVectorZ);

    FormCanv->WorkForm->Canvas->Pen->Color   = clBlack;
    FormCanv->WorkForm->Canvas->Brush->Color = clBlack;
    FormCanv->WorkForm->Canvas->Font->Color = clBlue;
    FormCanv->WorkForm->Canvas->TextOut(X_Center, Y_Center + 10, "Center");
    // ��� ��
    FormCanv->WorkForm->Canvas->MoveTo(X_Center, Y_Center);
    FormCanv->WorkForm->Canvas->LineTo(EndX_X, EndX_Y);
    FormCanv->WorkForm->Canvas->TextOut(EndX_X + 10, EndX_Y, "OX");
    // ��� �Y
    FormCanv->WorkForm->Canvas->MoveTo(X_Center, Y_Center);
    FormCanv->WorkForm->Canvas->LineTo(EndY_X, EndY_Y);
    FormCanv->WorkForm->Canvas->TextOut(EndY_X + 20, EndY_Y, "OY");
    // ��� �Z
    FormCanv->WorkForm->Canvas->MoveTo(X_Center, Y_Center);
    FormCanv->WorkForm->Canvas->LineTo(EndZ_X, EndZ_Y);
    FormCanv->WorkForm->Canvas->TextOut(EndZ_X + 30, EndZ_Y, "OZ");
};
// �������� ���� ������� ���������
// ������ ��� ��
void CartesianOrthographicCoordinateSystem::
             RotateAroundOX(long double OX_Angle){
    //  ������� ���� ��� OY
    BasicVectorY.RotateAroundOX(OX_Angle);
    //  ������� ���� ��� OZ
    BasicVectorZ.RotateAroundOX(OX_Angle);
    return;
};
// ������ ��� �Y
void CartesianOrthographicCoordinateSystem::
             RotateAroundOY(long double OY_Angle){
    //  ������� ���� ��� OZ
    BasicVectorZ.RotateAroundOY(OY_Angle);
    //  ������� ���� ��� OX
    BasicVectorX.RotateAroundOY(OY_Angle);
};
// ������ ��� �Z
void CartesianOrthographicCoordinateSystem::
             RotateAroundOZ(long double OZ_Angle){
    //  ������� ���� ��� OX
    BasicVectorX.RotateAroundOZ(OZ_Angle);
    //  ������� ���� ��� OY
    BasicVectorY.RotateAroundOZ(OZ_Angle);
};

void CartesianOrthographicCoordinateSystem::
             Rotate(long double OX_Angle,
                    long double OY_Angle,
                    long double OZ_Angle){
    // ������ ��� ��
    RotateAroundOX(OX_Angle);
    // ������ ��� �Y
    RotateAroundOY(OY_Angle);
    // ������ ��� �Z
    RotateAroundOZ(OZ_Angle);
};
// ���������� ������������� ������� � ������ ������� ���������
// [S] = Sx * [i] + Sy * [j] + Sz * [k];
TAlgVector CartesianOrthographicCoordinateSystem::
    VectorCoordinate(TAlgVector Vector){

    TAlgVector ResultSX_i;        // ����� ���������� X �������
    TAlgVector ResultSY_j;        // ����� ���������� Y �������
    TAlgVector ResultSZ_k;        // ����� ���������� Z �������
    TAlgVector ResultSX_i_SY_j;

    ResultSX_i      = Vector.X_Vect * BasicVectorX;
    ResultSY_j      = Vector.Y_Vect * BasicVectorY;
    ResultSZ_k      = Vector.Z_Vect * BasicVectorZ;
    ResultSX_i_SY_j = ResultSX_i    + ResultSY_j;

    return ResultSX_i_SY_j + ResultSZ_k;
};

