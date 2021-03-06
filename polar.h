#ifndef __polar__
#define __polar__

//------------------------------------------------------------------------------
// polar.h - содержит описание полярных координат
//------------------------------------------------------------------------------

#include "stdio.h"
#include "rnd.h"
#include "number.h"

//------------------------------------------------------------------------------
// полярная координата
class Polar: public Number{
public:
    virtual ~Polar() {}
    // Ввод параметров полярной координаты из файла
    virtual void In(FILE& ifst);
    // Случайный ввод параметров полярной координаты
    virtual void InRnd();
    // Вывдо параметров полярной координаты в форматируемый поток
    virtual void Out(FILE& ofst);
    // Вычисление вещественной части полярной координаты
    virtual double Real();
private:
    int a, b; // полярный радиус и угол
};



#endif //__polar__
