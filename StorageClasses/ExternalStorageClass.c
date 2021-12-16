#include <stdio.h>
/* In C, the 'extern' storage class simply means a variable is declared somewhere outside the scope
 * in the file and asks the compiler to find it. That's why the output of the following
 * program is 5 even though a = 5 is assigned below the printf() function. */

int ExternalStorageClass_main(){
    extern int a;
    printf("%d\n", a);

    return 0;
}

int a = 5;