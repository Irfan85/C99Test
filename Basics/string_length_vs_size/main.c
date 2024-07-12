#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
  char input[40];

  printf("Please enter a string:");
  scanf("%39s", input);

  // String length represents the numbe of characters in the string. So it only counts
  // the character slots that are being USED.
  int length = strlen(input);

  // String size represents how many characters a string can contain at max (including the termination character).
  int size = sizeof(input);

  printf("Input length = %d and size = %d\n", length, size);

  return 0;
}
