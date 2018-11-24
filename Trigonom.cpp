//
//  *************************************************************************
//  Sergej Edgar Heckel
//  Artel3D
//  Scholkino, Crimea, Ukraine
//  21.11.2000
//  *************************************************************************
//
//---------------------------------------------------------------------------
//  Класс "Угловая величина"
//---------------------------------------------------------------------------
//  В приложениях радиоастрономии, небесной механики, Солнечных оптических
//  систем часто приходится оперировать угловыми величинами, представленными
//  в разных форматах, в зависимости от того, какая именно информация
//  обрабатывается и какими средствами она была получена.
//  Например, широта и долгота местности -
//  это целые градусы, минуты и секунды, если информация берётся из справочников,
//  или снимается с соответствующих приборов.
//  Математическая обработка требует перевода этих единиц в радианы.
//  Большинство функций преобразования оперирует, например,
//  вещественными значениями градусов.
//  Именно этими обстоятельствами вызвана разработка настоящего класса.
//---------------------------------------------------------------------------
//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!
//  Пока не отработана концепция реакции системы на недопустимые значения
//  угловых величин или их несоответствие,
//  при возникновении такого исключения, на экран будет
//  просто выдаваться соответствующее сообщение, после чего величине
//  будет присвоено НУЛЕВОЕ значение
//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!
//---------------------------------------------------------------------------
#include "Trigonom.h"
#include <stdio.h>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
//  Конструкторы
TAngularValue::TAngularValue(long double ParRad) {
    SetAngularValue(ParRad);
};
TAngularValue::TAngularValue(int ParDegI, int ParMin, int ParSec, int ParMSec){
    SetAngularValue(ParDegI, ParMin, ParSec, ParMSec);
};
    //  Конструктор копирования - COPY CONSTRUCTOR
    TAngularValue::TAngularValue(const TAngularValue &Copy){
        Rad     =   Copy.Rad;
        Deg     =   Copy.Deg;
        DegI    =   Copy.DegI; Min = Copy.Min; Sec = Copy.Sec; MSec = Copy.MSec;
    };
//  Оператор присваивания - ASSIGNMENT OPERATOR.
TAngularValue& TAngularValue::operator= (const TAngularValue &Copy) {
        if(this == &Copy) return *this;
        Rad     =   Copy.Rad;
        Deg     =   Copy.Deg;
        DegI    =   Copy.DegI; Min = Copy.Min; Sec = Copy.Sec; MSec = Copy.MSec;
        return *this;
};
//  Функции установки угловой величины
void TAngularValue::SetAngularValue(long double ParRad) {
    Rad  = ParRad;
    // Сперва получим вещественные градусы
    Deg = RadToDeg(Rad);
    // Скорректируем диапазоны
    while (Deg > 360.00)    Deg -= 360.00;
    while (Deg < -360.00)   Deg += 360.00;
    DegToDegIMinSec();              // И переведём в целые градусы, минуты, секунды
};
void TAngularValue::SetAngularValue(int ParDegI, int ParMin, int ParSec, int ParMSec){
    if (ParDegI <= 360 && ParDegI >= -360) DegI = ParDegI;
    else {
        DegI = 0;
        ShowMessage(AnsiString("Градусы в недопустимом диапазоне: ") +
                    IntToStr(DegI));
    };
    if (ParMin < 60 && ParMin > -60) Min = ParMin;
    else {
        Min = 0;
        ShowMessage(AnsiString("Минуты в недопустимом диапазоне: ") +
                    IntToStr(Min));
    };
    if (ParSec < 60 && ParSec > -60) Sec = ParSec;
    else {
        Sec = 0;
        ShowMessage(AnsiString("Секунды в недопустимом диапазоне: ") +
                    IntToStr(Sec));
    };
    if (ParMSec < 1000 && ParMSec > -1000) MSec = ParMSec;
    else {
        MSec = 0;
        ShowMessage(AnsiString("МиллиСекунды в недопустимом диапазоне: ") +
                    IntToStr(MSec));
    };
    DegIMinSecToRad();              // Одновременно установится и Deg
    // При этом проверим соотвествие целых градусов, минут и секунд:
    if ((Deg > 360.00) || (Deg < -360.00)) {
        ShowMessage(AnsiString("Не в соответствии: Градусы: ") +
                    IntToStr(DegI) +
                    AnsiString(" Минуты: ") +
                    IntToStr(Min)  +
                    AnsiString(" Секунды: ") +
                    IntToStr(Sec));
        Min  = 0;
        Sec  = 0;
        MSec = 0;
    };
};
// Функции перевода угловых единиц
void TAngularValue::DegIMinSecToDeg(void){
    Deg    =  (long double)DegI
            + (long double)Min  / 60.00L
            + (long double)Sec  / 3600.00L
            + (long double)MSec / 3600000.00L;
};
void TAngularValue::DegToDegIMinSec(void){
    DegI    = Floor(fabsl(Deg));    // Целая часть - целые градусы
    ExtMin  = (Deg - floorl(Deg)) * 60.0L;
    Min     = Floor(ExtMin);        // Целая часть - целые минуты
    ExtSec  = (ExtMin - floorl(ExtMin)) * 60.0L;
    Sec     = Floor(ExtSec);        // Целая часть - целые секунды
    MSec    = Floor((ExtSec - floorl(ExtSec)) * 1000.0L);
    if (Deg < 0.00) {DegI = -DegI; Min = -Min; Sec = -Sec; MSec = -MSec;};
};
void TAngularValue::DegIMinSecToRad(void) {
    DegIMinSecToDeg();              // Сперва получим вещественные градусы
    Rad = DegToRad(Deg);            // Их переведём в радианы
};
void TAngularValue::RadToDegIMinSec(void){
    Deg = RadToDeg(Rad);            // Сперва получим вещественные градусы
    DegToDegIMinSec();              // Их переведём в целые градусы, минуты, секунды
};
