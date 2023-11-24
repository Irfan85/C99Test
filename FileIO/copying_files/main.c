#include<stdio.h>

int main(int argc, char const *argv[])
{
  // We're opening file in binary modes because we don't care about human
  // readable format in this case, as we won't be outputting the files' content
  // in the terminal.
  FILE* sourceFile = fopen("text.txt", "rb");
  FILE* destinationFile = fopen("text-copy.txt", "wb");

  if(sourceFile == NULL || destinationFile == NULL)
  {
    printf("Operation failed.\n");
    return -1;
  }

  // We're using a zero-initialized character array for acting as buffer. Increasing it's
  // size will improve performance, but also increase the program's memory footprint.
  char buffer[4096] = { 0 };

  int charactersRead;

  // Keep reading the file till the "fread" is able to read more than 0 characters.
  while((charactersRead = fread(buffer, sizeof(char), sizeof(buffer) / sizeof(char), sourceFile)) > 0)
  {
    // Write the same number of characters that have been read to the destination file. If
    // it fails, return with error.
    if(fwrite(buffer, sizeof(char), charactersRead, destinationFile) != charactersRead)
    {
      printf("Operation failed.\n");
      return -1;
    }
  }

  if(ferror(sourceFile) != 0)
  {
    printf("Operation failed.\n");
    return -1;
  }

  // Close both source and destination files.
  if(fclose(sourceFile) == EOF)
  {
    printf("Operation failed.\n");
    return -1;
  }

  if(fclose(destinationFile) == EOF)
  {
    printf("Operation failed.\n");
    return -1;
  }

  return 0;
}
