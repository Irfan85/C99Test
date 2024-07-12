#include<stdio.h>

int main(int argc, char* argv[])
{

  char name[] = "Hello";

  char* ap = name;

  ap += 2;

  *ap = 'p';

  printf("%s\n", name);

  return 0;
}
