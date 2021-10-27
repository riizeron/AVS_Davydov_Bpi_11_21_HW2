#ifndef __complex__
#define __complex__

//------------------------------------------------------------------------------
// complex.h - содержит комплексного числа и его интерфейса
//------------------------------------------------------------------------------

using namespace std;

#include "stdio.h"
#include "rnd.h"
#include "number.h"

// комплексное число
class Complex: public Number{
public:
    virtual ~Complex() {}
    // Ввод параметров комплексного числа из файла
    virtual void In(FILE& ifst);
    // Случайный ввод параметров комплексного числа
    virtual void InRnd();
    // Вывод параметров комплексного числа в форматируемый поток
    virtual void Out(FILE& ofst);
    // Вычисление вещественной части комплексного числа
    virtual double Real();
private:
    double x, y; // действительная и мнимая часть
};


#endif //__complex__
