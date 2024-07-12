#include<stdio.h>
#include<complex.h>

int main(int argc, char const *argv[])
{

  // A complex floating point number. Note that it's the UNIX variant. Microsoft implementation differs from this one.
  float complex cmp1 = 3.0 + 4.0 * _Complex_I;

  printf("cmp1(real) = %f, cmp1(imaginary) = %f\n", creal(cmp1), cimag(cmp1));

  // Complex double.
  // We can also use the shorthand "I" instead of "_Complex_I".
  double complex cmp2 = 4.0 + 5.0 * I;

  printf("cmp2(real) = %f, cmp2(imaginary) = %f\n", creal(cmp2), cimag(cmp2));

  return 0;
}
