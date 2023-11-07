#include<stdio.h>

int main(int argc, char* argv[])
{
  // There are many more escape characters. A handful of them are discussed here.

  // '\n' for Newline
  printf("Hello!\n");

  // '\t' for Tab
  printf("\t Hello!\n");

  // '\0' for NULL. It represents the end of FILE or STRING.
  // The "printf" function will ignore everything that comes after '\0'.
  printf("Hello\n\0asd"); // "asd" will be ignored by printf.

  // '\x' for converting a HEXADECIMAL number representing an ASCII value to the character that it represents.
  printf("\x43\n");

  return 0;
}
