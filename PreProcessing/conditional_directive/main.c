#include<stdio.h>

#define IS_LINUX 1

int main(int argc, char const *argv[])
{

  #if IS_LINUX
    puts("Running on linux.");
  #else
    // These codes will be removed by the pre-processor. Checkout the
    // '.i' file for confirmation.
    puts("Running on non-linux.");
  #endif

  /*
    The #ifdef and #ifndef derectives don't care about the values of the macros.
    They only check if the macro in question has been defined or not.
  */

  return 0;
}
