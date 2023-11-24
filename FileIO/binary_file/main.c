#include<stdio.h>

int main(int argc, char const *argv[])
{
  // The "w+b" means we want to write a binary file
  FILE* file = fopen("binary.bin", "w+b");

  if(file == NULL)
  {
    printf("Operation failed.\n");
    return -1;
  }

  char data[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

  // The "fwrite" function is used for writing raw data to files. It returns the
  // number of characters that were successfully written.
  if(fwrite(data, sizeof(char), sizeof(data) / sizeof(char), file) != 10)
  {
    printf("Operation failed.\n");
    return -1;
  }

  // Now that we've written our data, we will read it back

  // At first, we have to seek the cursor to the beginning
  if(fseek(file, 0, SEEK_SET))
  {
    printf("Operation failed.\n");
    return -1;
  }

  char fileData[10];

  // The "fread" function is used for reading raw data to files. It returns the
  // number of characters that were successfully read.
  if(fread(fileData, sizeof(char), sizeof(fileData)/sizeof(char), file) != 10)
  {
    printf("Operation failed.\n");
    return -1;
  }

  if(fclose(file) == EOF)
  {
    printf("Operation failed.\n");
    return -1;
  }

  for(int i = 0; i < 10; i++)
  {
    printf("%c ", fileData[i]);
  }

  printf("\n");

  return 0;
}
