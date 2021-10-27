//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include "stdlib.h" // для функций rand() и srand()
#include "time.h" // для функции time()
#include "stdio.h"
#include "string.h"

#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n"
        "  Waited:\n"
        "     command -f infile outfile\n"
        "  Or:\n"
        "     command -r number outfile\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
        "  Waited:\n"
        "     command -f infile outfile\n"
        "  Or:\n"
        "     command -r number outfile\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if (argc != 4) {
        errMessage1();
        return 1;
    }
    printf("Start\n");

    Container c;
    FILE* fp;

    if (!strcmp(argv[1], "-f")) {
        // Проверка на способность открыть файл чтения
        if ((fp = fopen(argv[2], "r")) == NULL) {
            printf("Unable to open the file\n");
            return 0;
        }
        c.In(*fp);
        fclose(fp);
    }
    else if (!strcmp(argv[1], "-r")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect amount of numbers = %d%s",
                size, ". Set 0 < amount <= 10000\n");
            return 3;
        }
        // системные часы в качестве инициализатора
        srand((unsigned int)(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    if ((fp = fopen(argv[3], "w+")) == NULL) {
        printf("Unable to open the file\n");
        return 0;
    }

    // Вывод содержимого контейнера в файл
    fprintf(fp, "%s", "Filled container:\n");
    c.Out(*fp);
    fprintf(fp, "%s%f%s", "Real average = ", c.RealAverage(),"\n\n");

    // The 2nd part of task
    fprintf(fp, "%s", "New container:\n");
    c.DeleteLowerThanAverage();
    c.Out(*fp);

    c.Clear();
    fclose(fp);

    printf("Stop");

    return 0;
}
