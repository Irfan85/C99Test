#include<stdio.h>
#include<stdlib.h> // This file contains memory management functions

// Function prototypes
void printIntegerArray(const int* array, const long size);

int main(int argc, char const *argv[])
{
  // The "malloc" function.
  // This function is used for allocating dynamic memory. It returns a "void"
  // pointer (If it successfully allocates memory). So, we have to explicitly cast
  // it to the pointer of our desired type.
  // It takes the amount of allocated memory in bytes. It's a good practice to use
  // the "sizeof" operator here.
  int* numbers = (int*)malloc(sizeof(int) * 5);

  for(int i = 0; i < 5; i++)
  {
    // Note that we can treat a block of memory just like an array.
    // This is beacuse, arrays are infact blocks of dynamic memory.
    // That's why the indexing operator works for pointers.
    numbers[i] = i + 1;
  }

  printIntegerArray(numbers, 5);

  // The "calloc" function.
  // This function not only creates a block of dynamic memory, but also INITIALIZES
  // it with zeros. Unlike "malloc", "calloc" takes the number of slots in a
  // separate parameter. So, we don't have to multiply the size.
  // NOTE: It's recommended to use "calloc" instead of "malloc" as it's more specific.
  int* moreNumbers = (int*)calloc(5, sizeof(int));

  printIntegerArray(moreNumbers, 5);

  // The "realloc" funtion.
  // This function is used for MODIFYING the size of PRE-OCCUPIED dynamic memory.
  // After modifying the initial space, realloc returns a voiid pointer to it just
  // like malloc that has to be explicitly casted.

  // Here, we'll resize "numbers".
  // We're adding two more slots for the integers. So, the new size
  // will be sizeof(int) * 7.
  numbers = realloc(numbers, sizeof(int) * 7);

  // Now, we can assign values to those new slots
  numbers[5] = 6;
  numbers[6] = 7;

  printIntegerArray(numbers, 7);

  // The "free" function.
  // This function is used for freeing a pre-occupied block of dynamic memory.

  // We're freeing the blocks of memories allocated before
  free(numbers);

  // Now, if we attempt to print thier content, we'll get garbage values.
  printIntegerArray(numbers, 1);
  printIntegerArray(moreNumbers, 1);

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
