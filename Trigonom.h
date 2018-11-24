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
//  Класс "Угловая величина"
//---------------------------------------------------------------------------
class TAngularValue {
public:
    long double Rad;        // Радианы угловой величины
    long double Deg;        // Вещественные градусы угловой величины
    int         DegI;       // Целые Градусы угловой величины
    int         Min;        // Целые Минуты  угловой величины
    int         Sec;        // Целые Секунды угловой величины
    int         MSec;       // Целые МиллиСекунды угловой величины
    long double ExtMin;     // Вещественные Минуты угловой величины
    long double ExtSec;     // Вещественные Секунды угловой величины
//  Конструкторы
    TAngularValue(long double Rad = 0.00);
    TAngularValue(int ParDegI = 0, int ParMin = 0, int ParSec = 0, int ParMSec = 0);
    //  Конструктор копирования - COPY CONSTRUCTOR
    TAngularValue(const TAngularValue &Copy);
//  Оператор присваивания - ASSIGNMENT OPERATOR.
    TAngularValue& operator= (const TAngularValue &Copy);
//  Функции установки угловой величины
    virtual void SetAngularValue(long double Rad = 0.00);
    virtual void SetAngularValue(int ParDegI = 0, int ParMin = 0, int ParSec = 0, int ParMSec = 0);
//  Функции перевода угловых единиц
    void DegIMinSecToDeg(void);
    void DegToDegIMinSec(void);
    void DegIMinSecToRad(void);
    void RadToDegIMinSec(void);
};
#endif
