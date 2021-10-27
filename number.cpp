//------------------------------------------------------------------------------
// number.cpp - содержит процедуры связанные с обработкой обобщенного числа
// и создания произвольного числа
//------------------------------------------------------------------------------

#include "polar.h"
#include "fraction.h"
#include "complex.h"

//------------------------------------------------------------------------------
Random Number::rnd20(1, 20);
Random Number::rnd2(1,2);

//------------------------------------------------------------------------------
// Ввод параметров обобщенного числа из файла
Number* Number::StaticIn(FILE& ifst){
    int k;
    fscanf(&ifst,"%d", &k);
    Number* num = nullptr;
    switch(k){
        case 1:
            num = new Complex;
            break;
        case 2:
            num = new Fraction;
            break;
        case 3:
            num = new Polar;
            break;
    }
    num->In(ifst);
    return num;
}

// Случайный ввод обобщенного числа
Number *Number::StaticInRnd(){
    auto k = Number::rnd2.Get();
    Number* num = nullptr;
    switch(k){
        case 1:
            num = new Complex;
        case 2:
            num = new Fraction;
        case 3:
            num = new Polar;
    }
    num->InRnd();
    return num;
}


