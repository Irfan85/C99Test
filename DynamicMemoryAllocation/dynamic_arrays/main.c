#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
  // In legacy C code, dynamic arrays were created using pointers and functions like
  // "malloc", "calloc" etc. Note that arrays are NOT pointers. Infact they DECAY to
  // pointers. Dynamic arrays created using such memory management functions are stored
  // in the HEAP.
  int* someNumbers = (int*)malloc(sizeof(int) * 10);

  // We're freeing the allocated memory free when we don't need it.
  free(someNumbers);

  // In C99, Variable-Length Array (VLA) was introduced that let uses define array sizes
  // using variables. Unlike other dynamic arrays, these are stored in the STACK.
  int size = 5;

  // We can pass a variable for defining array size, which was not possible before C99.
  int someMoreNumbers[size];

  // Variable length arrays have a caveat. Since they're stored in the stack, they can easily
  // cause stack-overflow if their size isn't controlled. If there's a possibility of using large
  // amount of data, stick to HEAP based legacy dynamic arrays instead.

  // We can combine the power of legacy dynamic arrays and VLAs for created multi-dimensional
  // dynamic arrays. Creating these multi-dimensional arrays using just pointers would be hard.
  // But, VLAs make it easier for us to define the sizes of each memory slot in the malloc/calloc function.
  int row = 3;
  int column = 3;

  // Note that in this case, the pointer syntax has to be in the parentheses, just like function pointers.
  int (*dynamicMatrix)[row][column] = malloc(sizeof(int[row][column]));

  int content = 1;

  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < column; j++)
    {
      // Note that dereferencing the pointer is important. Not doing this can lead
      // to unexpected results.
      (*dynamicMatrix)[i][j] = 1;
    }
  }

  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < column; j++)
    {
      // Note that dereferencing the pointer is important. Not doing this can lead
      // to unexpected results.
      printf("%d ", (*dynamicMatrix)[i][j]);
    }

    puts("");
  }

  return 0;
}
