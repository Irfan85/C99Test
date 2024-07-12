#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Swap(void* a, void* b, size_t byteCount)
{
  void* tmp = malloc(byteCount);

  memcpy(tmp, a, byteCount);
  memcpy(a, b, byteCount);
  memcpy(b, tmp, byteCount);

  free(tmp);
}

int main(int argc, char const *argv[])
{
  int num1 = 5, num2 = 10;
  double double1 = 5.5, double2 = 10.5;

  puts("Before Swap");

  printf("Num1: %d\n", num1);
  printf("Num2: %d\n", num2);
  printf("Double1: %lf\n", double1);
  printf("Double2: %lf\n", double2);

  printf("\n");

  Swap(&num1, &num2, sizeof(int));
  Swap(&double1, &double2, sizeof(double));

  puts("After Swap");

  printf("Num1: %d\n", num1);
  printf("Num2: %d\n", num2);
  printf("Double1: %lf\n", double1);
  printf("Double2: %lf\n", double2);

  return 0;
}
