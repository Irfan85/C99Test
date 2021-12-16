#include <stdio.h>
#include <stdarg.h> // We need this header file to use variable argument functionality
double average(int n, ...)
{
    // We need a built in data structre "va_list" to store the arguments
    va_list arglist;

    // "va_start" will initialize the va_list. We need to pass the fixed argument just before the
    // variable argument list so that va_start can determine where to look from the stack
    va_start(arglist, n);

    double sum = 0.0;

    for(int i = 0; i < n; i++)
    {
        // We have to specify which type of data type we're expecting as argument. In our case, 
        // all of them are double
        double temp = va_arg(arglist, double);
        sum += temp;
    }

    return sum / n;
}

int main() 
{
    double avg = average(5, 1.0, 2.0, 3.0, 4.0, 5.0);
    printf("Average: %lf\n", avg);

    return 0;
}