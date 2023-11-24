#include<stdio.h>

int main(int argc, char const *argv[])
{
  // The __LINE__ and __FILE__ macros store the line number and
  // file name respectively.
  printf("I'm on line %d of file %s.\n", __LINE__, __FILE__);

  // We can change the value of the above macros using the
  // #line macro.
  #line 1000 "magicalFile.c"
  printf("I'm on line %d of file %s.\n", __LINE__, __FILE__);

  // The change will be persistent throughout the program.
  printf("I'm on line %d of file %s.\n", __LINE__, __FILE__);
  return 0;
}
