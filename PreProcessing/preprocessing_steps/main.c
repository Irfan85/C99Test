#include<stdio.h>

/\
*
*/ # /*
*/ defi\
ne NU\
M 5\
25

int main(int argc, char const *argv[])
{
  /*
    A C program goes through the following stages while compilation
    1. Preprocessor -> Outputs a ".i" file
    2. Compiler -> Outputs a ".s" file
    3. Assembler -> Outputs a ".o" file. The assembly codes are later optimized
    4. Linker -> Outputs a ".out" or ".exe" file

    Compile this file using the command:
      gcc main.c -save-temps
    For checking out all the intermediate files produced in each step.

    If we don't want GCC to compile the program, but just output the pre-proessed code,
    we can do so using the "cpp" (C Pre-processor) command:
      cpp main.c <OUTPUT_FILE_NAME>
    The output file name is optional. If we don't pass it, the command will print the
    output in the terminal.
  */

  // Note that C will AUTOMATICALLY concatenate adjacent string literals. So,
  // we don't have to use '+'.
  printf("The number is: %d" "\n", NUM);

  return 0;
}
