#include<stdio.h>

int main(int argc, char const *argv[])
{
  FILE* file = fopen("text.txt", "r");

  if(file == NULL)
  {
    printf("Operation failed.\n");
    return -1;
  }

  char fileData[128];

  int readCount = 0;

  // We will read 127 characters + 1 NULL/EMPTY character FOR EACH LINE.
  // The fgets function will read one line at a time. So at each iteration it will get data
  // til it encounts a '\n'.
  while(fgets(fileData, 128, file) != NULL)
  {
    printf(fileData);

    readCount++;
  }

  printf("\n");

  if(ferror(file) != 0)
  {
    printf("Operation failed.\n");
    return -1;
  }

  if(ferror(file) == EOF)
  {
    printf("Operation failed.\n");
    return -1;
  }

  printf("Operation Succeded. Had to fetch lines %d times.\n", readCount);

  return 0;
}
