#include<stdio.h>

/*
  In C, we can modify the name of the program's entry point function  by using a macro
  like this. As expected, this macro will replace the word "foo" with "main", thus
  turning the function "foo" to "main".
*/
#define foo main

int foo(int argc, char const *argv[])
{
  puts("Hello World!");

  return 0;
}
