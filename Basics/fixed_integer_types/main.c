#include<stdio.h>
#include<inttypes.h> // This header file contains fixed integer types

int main(int argc, char const *argv[])
{
  /*
    In C, the size of "int" varies betwen platforms. As a result, C99 introduced
    fixed with integers that will guarantee the creation of integers of specific size
    across different platforms. Some of them are discussed here.
  */

  // EXACTLY 8 BIT signed int
  int8_t a = 10;

  // EXACTLY 16 BIT signed int
  int16_t b = 10;

  // EXACTLY 16 BIT unsigned int
  uint16_t c = 10;

  // AT LEAST 16 BIT signed int
  int_least16_t d = 10;

  // FASTEST integer type the platform can PROCESS that's at least 16 bits.
  int_fast16_t e = 10;

  // LARGEST integer type the platform can provide
  intmax_t g = 10;

  return 0;
}
