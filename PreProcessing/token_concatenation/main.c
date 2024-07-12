#include<stdio.h>

// We can concat two macro parameters using '#'. This is called "Token Concatenation".
#define CONCAT(X, Y) X##Y

int main(int argc, char const *argv[])
{
  int ab = 5;

  // The macro expands to ab, so ab = 5 will be printed.
  printf("ab = %d\n", CONCAT(a, b));

  return 0;
}
