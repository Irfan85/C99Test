#include<stdio.h>
#include<stdlib.h>

void printIntegerArray(const int* array, const long size);

int main(int argc, char const *argv[])
{
  int* numbers = (int*)malloc(sizeof(int) * 5);

  for (int i = 0; i < 5; i++)
  {
    // Adding 1 to a pointer means moving the pointer to the next memory
    // location. In fact, the indexing operator '[]' is actually a shorthand
    // of the code writtena in the left hand side. Here, we could write
    // "numbers[i]" if we wanted to use the indexing operator.
    *(numbers + i) = i + 1;
  }

  printIntegerArray(numbers, 5);

  return 0;
}

void printIntegerArray(const int* array, const long size)
{
  printf("[");

  for(int i = 0; i < size; i++)
  {
    printf("%d", array[i]);

    if(i != size - 1)
    {
      printf(", ");
    }
    else
    {
      printf("]\n");
    }
  }
}
