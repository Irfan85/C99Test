#include<stdio.h>

void swap(int* a, int* b)
{
  // We can dereference a pointer using "*".
  int temp = *a;

  // The defererence operator can also be used for assigning values
  // to the variable that a pointer points to.
  *a = *b;
  *b = temp;
}

int main(int argc, char const *argv[])
{
  int a = 10;
  int b = 20;

  swap(&a, &b);

  printf("a = %d\n", a);
  printf("b = %d\n", b);

  return 0;
}
