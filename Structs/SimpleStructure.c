#include <stdio.h>

struct car{
    char *name;
    int number;
} car01, car02;

int SimpleStructure_main(){
    car01.name = "Toyota";
    car01.number = 40008;
    puts(car01.name);
    printf("%d\n", car01.number);

    car02.name = "Ford";
    car02.number = 76493;
    puts(car02.name);
    printf("%d\n", car02.number);

    struct car car03;

    car03.name = "BMW";
    car03.number = 53928;
    puts(car03.name);
    printf("%d\n", car03.number);

    struct car *car03_ptr = &car03;
    car03_ptr->number = 90397; //Here, '->' means dereference car03_ptr.

    puts(car03.name);
    printf("%d\n", car03.number);

    return 0;
}
