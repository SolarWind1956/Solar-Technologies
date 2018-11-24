//
//  *************************************************************************
//  Sergej Edgar Heckel and Sergej Victor Astakhov
//  Artel3D
//  Schoelkino, Crimea, Ukraine
//  10.10.2000
//  *************************************************************************
//
//---------------------------------------------------------------------------
#ifndef AlgebraH
#define AlgebraH
//---------------------------------------------------------------------------
#include <math.h>
// Cartesian coordinates of Vector
class VectCartesianCoord {
public:
    long double X_Vect;
    long double Y_Vect;
    long double Z_Vect;
};
class TAlgVector : public VectCartesianCoord {  // Vector coordinates
public:
    long double AlgVectMagnitude;               // Vector magnitude

    TAlgVector() {                              // DEFAULT VECTOR 
        X_Vect = 1.0;   Y_Vect = 1.0;   Z_Vect = 1.0;
        VectMagnitude();
    };
    // INITIALIZATION
    TAlgVector(long double X, long double Y, long double Z) {
        X_Vect = X;     Y_Vect = Y;     Z_Vect = Z;
        VectMagnitude();
    };
    // COPY CONSTRUCTOR
    TAlgVector(const TAlgVector&C){
        X_Vect = C.X_Vect;  Y_Vect = C.Y_Vect;  Z_Vect = C.Z_Vect;
         AlgVectMagnitude = C.AlgVectMagnitude;
    };
    // ASSIGNMENT OPERATOR.
    TAlgVector& operator= (const TAlgVector &C) {
        if(this == &C) return *this;
        X_Vect = C.X_Vect;  Y_Vect = C.Y_Vect;  Z_Vect = C.Z_Vect;
        AlgVectMagnitude = C.AlgVectMagnitude;
        return *this;
    };
    // Base operations
    // Vector * Scalar
    friend TAlgVector operator* (long double Scalar, TAlgVector& AAV) {
        TAlgVector result;     // DO NOT MODIFY THE ORIGINAL
        result.X_Vect = AAV.X_Vect * Scalar;
        result.Y_Vect = AAV.Y_Vect * Scalar;
        result.Z_Vect = AAV.Z_Vect * Scalar;
        result.VectMagnitude();
        return result;
    };
    // Scalar Product
	friend long double operator* (TAlgVector& AAV, TAlgVector& BAV) {
		long double ScalarProduct;
        ScalarProduct  = AAV.X_Vect * BAV.X_Vect
        			   + AAV.Y_Vect * BAV.Y_Vect
                	   + AAV.Z_Vect * BAV.Z_Vect;
        return ScalarProduct;
    };
    // Vector Product
    friend TAlgVector operator>> (TAlgVector& AAV, TAlgVector& BAV) {
		TAlgVector result;	// DO NOT MODIFY THE ORIGINAL
        result.X_Vect = AAV.Y_Vect * BAV.Z_Vect - AAV.Z_Vect * BAV.Y_Vect;
        result.Y_Vect = AAV.Z_Vect * BAV.X_Vect - AAV.X_Vect * BAV.Z_Vect;
        result.Z_Vect = AAV.X_Vect * BAV.Y_Vect - AAV.Y_Vect * BAV.X_Vect;
        result.VectMagnitude();
        return result;
	};
    // Sum of vectors
    friend TAlgVector operator+ (TAlgVector& AAV, TAlgVector& BAV) {
        TAlgVector result;     // DO NOT MODIFY THE ORIGINAL
        result.X_Vect = AAV.X_Vect + BAV.X_Vect;
        result.Y_Vect = AAV.Y_Vect + BAV.Y_Vect;
        result.Z_Vect = AAV.Z_Vect + BAV.Z_Vect;
        result.VectMagnitude();
        return result;
    };
    // Difference of vectors
    friend TAlgVector operator- (TAlgVector& AAV, TAlgVector& BAV) {
        TAlgVector result;     // DO NOT MODIFY THE ORIGINAL
        result.X_Vect = AAV.X_Vect - BAV.X_Vect;
        result.Y_Vect = AAV.Y_Vect - BAV.Y_Vect;
        result.Z_Vect = AAV.Z_Vect - BAV.Z_Vect;
        result.VectMagnitude();
        return result;
    };
    // MixedProduct - Смешанное произведение векторов [D] = [A] x [[B] x [C]];
    friend TAlgVector
    MixedProduct(TAlgVector& AAV, TAlgVector& BAV, TAlgVector& CAV) {
        TAlgVector result;
        result = BAV >> CAV, AAV >> result; // Заодно проверь, как работает оператор "запятая"
        return result;
    };
    // Vector Magnitude
    void VectMagnitude(){
        AlgVectMagnitude = sqrt(powl(X_Vect, 2) + powl(Y_Vect, 2) + powl(Z_Vect, 2));
    };
    // Нормирование вектора
    void NormVector(){
        X_Vect = X_Vect / AlgVectMagnitude;
        Y_Vect = Y_Vect / AlgVectMagnitude;
        Z_Vect = Z_Vect / AlgVectMagnitude;
    };
    // Поворот вокруг оси OX на угол Angle (Rad)
    void RotateAroundOX(long double Angle);
    // Поворот вокруг оси OY на угол Angle (Rad)
    void RotateAroundOY(long double Angle);
    // Поворот вокруг оси OZ на угол Angle (Rad)
    void RotateAroundOZ(long double Angle);
};
#endif


