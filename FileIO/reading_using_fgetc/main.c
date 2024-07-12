#include<stdio.h>

int main(int argc, char const *argv[])
{
  FILE* file = fopen("text.txt", "r");

  if(file == NULL)
  {
    printf("Operation failed.\n");
    return -1;
  }

  int readCount = 0;

  char fileCharacter;

  // The fgetc will read the file ONE CHARACTER at a time. It returns an it.
  // Assigning int to a char DOES NOT require explicit casting.
  while((fileCharacter = fgetc(file)) != EOF)
  {
    printf("%c", fileCharacter);

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

  printf("Operation Succeded. Had to fetch characters %d times.\n", readCount);

  return 0;
}
