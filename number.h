#ifndef __number__
#define __number__

//------------------------------------------------------------------------------
// number.h - содержит описание обобщающего числа
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся числа
class Number {
protected:
    static Random rnd20;
    static Random rnd2;
public:
    virtual ~Number(){}
    // Ввод обобщенного числа
    static Number *StaticIn(FILE& ifdt);
    // Ввод обощенного числа
    virtual void In(FILE& ifdt) = 0;
    // Случайный ввод обощенного числа
    static Number *StaticInRnd();
    // Виртуальный метод ввода случайного числа
    virtual void InRnd() = 0;
    // Вывод обобщенного числа
    virtual void Out(FILE& ofst) = 0;
    //Вычисление вещественной части обощенного числа
    virtual double Real() = 0;

};


#endif


