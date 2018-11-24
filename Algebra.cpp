//
//  *************************************************************************
//  Sergej Edgar Heckel
//  Artel3D
//  Schoelkino, Crimea, Ukraine
//  10.10.2000
//  *************************************************************************
//
#include "Algebra.h"
    // Поворот вокруг оси OX на угол Angle (Rad)
    void TAlgVector::RotateAroundOX(long double Angle){
        long double Cosine = cosl(Angle);
        long double Sine = sinl(Angle);
        long double Y, Z;
        Y = Y_Vect * Cosine - Z_Vect * Sine;
        Z = Y_Vect * Sine   + Z_Vect * Cosine;
        Y_Vect = Y; Z_Vect = Z;
        VectMagnitude();
        return;
    };
    // Поворот вокруг оси OY на угол Angle (Rad)
    void TAlgVector::RotateAroundOY(long double Angle){
        long double Cosine = cosl(Angle);
        long double Sine   = sinl(Angle);
        long double Z, X;
        Z = Z_Vect * Cosine - X_Vect * Sine;
        X = Z_Vect * Sine   + X_Vect * Cosine;
        Z_Vect = Z; X_Vect = X;
        VectMagnitude();
        return;
    };
    //Поворот вокруг оси OZ на угол Angle (Rad)
    void TAlgVector::RotateAroundOZ(long double Angle){
        long double Cosine = cosl(Angle);
        long double Sine   = sinl(Angle);
        long double X, Y;
        X = X_Vect * Cosine - Y_Vect * Sine;
        Y = X_Vect * Sine   + Y_Vect * Cosine;
        X_Vect = X; Y_Vect = Y;
        VectMagnitude();
        return;
    };



