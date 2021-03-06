//------------------------------------------------------------------------------
// complex.cpp - содержит методы комплексного числа
//------------------------------------------------------------------------------

#include "complex.h"
#include "math.h"


//------------------------------------------------------------------------------
// Ввод параметров комплексного числа из файла
void Complex::In(FILE &ifst) {
    fscanf(&ifst,"%lf%lf", x, y);
}

// Случайный ввод параметров комплексного числа
void Complex::InRnd() {
    x = Number::rnd20.Get();
    y = Number::rnd20.Get();
}

//------------------------------------------------------------------------------
// Вывод параметров комплексного числа в форматируемый поток
void Complex::Out(FILE &ofst) {
    fprintf(&ofst, "%s%g%s%g%s%g%s", "It is Complex: x = "
        , x, ", y = ", y
        , ". Real = ", Real(), "\n");
}

//------------------------------------------------------------------------------
// Приведение комплексного числа к действительному
double Complex::Real() {
    return sqrt(x*x + y*y);
}


