#include<stdio.h>

int main(int argc, char const *argv[])
{
  // In C, multi-dimensional arrays are stored in ROW-MAJOR notation.
  // Which means, the following array will be stored in the STACK like this:
  // 1, 1, 2, 4, 3, 9, 4, 16.
  // Just like any other STATIC array, these arrays are also stored in the STACK.
  int matrix [][2] = {
    {1, 1},
    {2, 4},
    {3, 9},
    {4, 16}
  };

  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 2; j++)
    {
      printf("%d ", matrix[i][j]);
    }

    puts("");
  }

  return 0;
}
