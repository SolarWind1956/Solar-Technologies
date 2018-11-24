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
// Класс "Декартова прямоугольная (ортогональная) система координат"
// Прорисовка осей системы координат
void CartesianOrthographicCoordinateSystem::Draw(TFormCanvas* FormCanv){
    // Координаты стрелки оси ОХ на экране
    int EndX_X = X_Center
               + FormCanv->WorkForm->Height / 2
               * (FormCanv->FormBasicVectorX * BasicVectorX);
    int EndX_Y = Y_Center
               + FormCanv->WorkForm->Height / 2
               * (FormCanv->FormBasicVectorY * BasicVectorX);
    // Координаты стрелки оси ОY на экране
    int EndY_X = X_Center
               + FormCanv->WorkForm->Height / 2
               * (FormCanv->FormBasicVectorX * BasicVectorY);
    int EndY_Y = Y_Center
               + FormCanv->WorkForm->Height / 2 * (FormCanv->FormBasicVectorY * BasicVectorY);
    // Координаты стрелки оси ОZ на экране
    int EndZ_X = X_Center
               + FormCanv->WorkForm->Height / 2 * (FormCanv->FormBasicVectorX * BasicVectorZ);
    int EndZ_Y = Y_Center
               + FormCanv->WorkForm->Height / 2 * (FormCanv->FormBasicVectorY * BasicVectorZ);

    FormCanv->WorkForm->Canvas->Pen->Color   = clBlack;
    FormCanv->WorkForm->Canvas->Brush->Color = clBlack;
    FormCanv->WorkForm->Canvas->Font->Color = clBlue;
    FormCanv->WorkForm->Canvas->TextOut(X_Center, Y_Center + 10, "Center");
    // Ось ОХ
    FormCanv->WorkForm->Canvas->MoveTo(X_Center, Y_Center);
    FormCanv->WorkForm->Canvas->LineTo(EndX_X, EndX_Y);
    FormCanv->WorkForm->Canvas->TextOut(EndX_X + 10, EndX_Y, "OX");
    // Ось ОY
    FormCanv->WorkForm->Canvas->MoveTo(X_Center, Y_Center);
    FormCanv->WorkForm->Canvas->LineTo(EndY_X, EndY_Y);
    FormCanv->WorkForm->Canvas->TextOut(EndY_X + 20, EndY_Y, "OY");
    // Ось ОZ
    FormCanv->WorkForm->Canvas->MoveTo(X_Center, Y_Center);
    FormCanv->WorkForm->Canvas->LineTo(EndZ_X, EndZ_Y);
    FormCanv->WorkForm->Canvas->TextOut(EndZ_X + 30, EndZ_Y, "OZ");
};
// Повороты осей системы координат
// Вокруг оси ОХ
void CartesianOrthographicCoordinateSystem::
             RotateAroundOX(long double OX_Angle){
    //  Поворот орта оси OY
    BasicVectorY.RotateAroundOX(OX_Angle);
    //  Поворот орта оси OZ
    BasicVectorZ.RotateAroundOX(OX_Angle);
    return;
};
// Вокруг оси ОY
void CartesianOrthographicCoordinateSystem::
             RotateAroundOY(long double OY_Angle){
    //  Поворот орта оси OZ
    BasicVectorZ.RotateAroundOY(OY_Angle);
    //  Поворот орта оси OX
    BasicVectorX.RotateAroundOY(OY_Angle);
};
// Вокруг оси ОZ
void CartesianOrthographicCoordinateSystem::
             RotateAroundOZ(long double OZ_Angle){
    //  Поворот орта оси OX
    BasicVectorX.RotateAroundOZ(OZ_Angle);
    //  Поворот орта оси OY
    BasicVectorY.RotateAroundOZ(OZ_Angle);
};

void CartesianOrthographicCoordinateSystem::
             Rotate(long double OX_Angle,
                    long double OY_Angle,
                    long double OZ_Angle){
    // Вокруг оси ОХ
    RotateAroundOX(OX_Angle);
    // Вокруг оси ОY
    RotateAroundOY(OY_Angle);
    // Вокруг оси ОZ
    RotateAroundOZ(OZ_Angle);
};
// Координаты произвольного вектора в данной системе координат
// [S] = Sx * [i] + Sy * [j] + Sz * [k];
TAlgVector CartesianOrthographicCoordinateSystem::
    VectorCoordinate(TAlgVector Vector){

    TAlgVector ResultSX_i;        // Новая координата X вектора
    TAlgVector ResultSY_j;        // Новая координата Y вектора
    TAlgVector ResultSZ_k;        // Новая координата Z вектора
    TAlgVector ResultSX_i_SY_j;

    ResultSX_i      = Vector.X_Vect * BasicVectorX;
    ResultSY_j      = Vector.Y_Vect * BasicVectorY;
    ResultSZ_k      = Vector.Z_Vect * BasicVectorZ;
    ResultSX_i_SY_j = ResultSX_i    + ResultSY_j;

    return ResultSX_i_SY_j + ResultSZ_k;
};

