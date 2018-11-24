//---------------------------------------------------------------------------
//  *************************************************************************
//  Sergej Edgar Heckel
//  Artel3D
//  Schoelkino, Crimea, Ukraine
//  14.05.2001
//  *************************************************************************

#ifndef CoordSysH
#define CoordSysH
#include "Algebra.h"
#include "FormCanv.h"
//---------------------------------------------------------------------------
//  Классы систем координат
enum CoordinateSystemClasses {  Cartesian,      /* Декартовы */
                                Curvilinear     /* Криволинейные */ };
//  Виды систем координат
enum CoordinateSystemKinds   {  Orthographic,   /* Ортогональные */
                                Obligue         /* Косоугольные */  };
//  Типы систем координат
enum CoordinateSystemTypes   {  Right,          /* Правая */
                                Left            /* Левая */         };
// Класс "Система координат"
class CoordinateSystem {
public:
    //
    CoordinateSystemClasses     CSystemClass;   // Класс системы координат
    CoordinateSystemKinds       CSystemKind;    // Вид системы координат
    CoordinateSystemTypes       CSystemType;    // Тип системы координат
    // Орты осей
    TAlgVector BasicVectorX;
    TAlgVector BasicVectorY;
    TAlgVector BasicVectorZ;
    // Координаты центра системы координат
    long double X_Center;
    long double Y_Center;
    long double Z_Center;
    void SetCenterCoordinate(long double X,
                             long double Y,
                             long double Z) {
        X_Center = X; Y_Center = Y; Z_Center = Z;
    };
    // Прорисовка осей системы координат
    virtual void Draw(TFormCanvas*) = 0;
    // Повороты осей системы координат (Положительное направление - против
    //                                  часовой стрелки)
    // Вокруг оси ОХ
    virtual void RotateAroundOX(long double) = 0;
    // Вокруг оси ОY
    virtual void RotateAroundOY(long double) = 0;
    // Вокруг оси ОZ
    virtual void RotateAroundOZ(long double) = 0;
    virtual void Rotate(long double, long double, long double) = 0;
    virtual TAlgVector VectorCoordinate(TAlgVector) = 0;
    virtual ~CoordinateSystem() {};
};
// _________________________________________________________________
// С и с т е м ы    к о о р д и н а т
// _________________________________________________________________
// Класс "Декартова прямоугольная система координат"
class CartesianOrthographicCoordinateSystem : public CoordinateSystem {
public:
    // Конструктор
    CartesianOrthographicCoordinateSystem(CoordinateSystemTypes enSystemType) {
        // Класс системы координат
        CSystemClass = Cartesian;       // Декартова
        // Вид системы координат
        CSystemKind  = Orthographic;    // Прямоуголная (или ортогональная)
        // Тип системы координат
        CSystemType  = enSystemType;
        if (enSystemType == Right) {    // Правая
            BasicVectorX = TAlgVector(1, 0, 0);
            BasicVectorY = TAlgVector(0, 1, 0);
            BasicVectorZ = TAlgVector(0, 0, 1);
        } else {                        // Левая
            BasicVectorX = TAlgVector(1, 0, 0);
            BasicVectorY = TAlgVector(0, 1, 0);
            BasicVectorZ = TAlgVector(0, 0, 1);
        };
    };
    // Прорисовка осей системы координат
    void Draw(TFormCanvas*);
    // Повороты осей системы координат
    // Вокруг оси ОХ
    void RotateAroundOX(long double OX_Angle);
    // Вокруг оси ОY
    void RotateAroundOY(long double OY_Angle);
    // Вокруг оси ОZ
    void RotateAroundOZ(long double OZ_Angle);
    void Rotate(long double OX_Angle = 0.0L,
                long double OY_Angle = 0.0L,
                long double OZ_Angle = 0.0L);
    // Координаты произвольного вектора в данной системе координат
    virtual TAlgVector VectorCoordinate(TAlgVector);
};
#endif
