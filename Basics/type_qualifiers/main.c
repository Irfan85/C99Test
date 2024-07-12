#include<stdio.h>

int main(int argc, char const *argv[])
{
  // The "volatile" qualifier.
  // A volatile variable is never cached and is directly read from the memory.
  // It's useful for multi-threaded application as it makes sure that all of the
  // threads will get the variable's accurate and real-time value. It comes at a
  // performance cost though as these variables aren't cached. Volatile variables
  // are often used in embedded and real-time systems.
  volatile int a = 10;

  printf("%d\n", a);

  // The "const" qualifier.
  // This qualifier is used for creating constants.
  const int b = 20;
  // b = 50; // This will cause error.

  printf("%d\n", b);

  return 0;
}
