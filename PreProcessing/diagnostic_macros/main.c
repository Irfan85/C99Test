#include<stdio.h>

#define IS_LINUX 1

int main(int argc, char const *argv[])
{

  #if (IS_LINUX == 1)
    #warning "Be careful. This is a sensitive software."

    puts("Running on linux.");
  #elif (IS_LINUX == 2)
    // The pre-processor will stop the pre-processing operation when it counters
    // an error macro.
    // NOTE: The editor or IDE is likely going to mark error macros red if they
    // are in the execution path, but compile this program anyway to see this
    // macro in action.
    #error "This is an unrecognized platform"
  #else
    // These codes will be removed by the pre-processor. Checkout the
    // '.i' file for confirmation.
    puts("Running on non-linux.");
  #endif

  return 0;
}
