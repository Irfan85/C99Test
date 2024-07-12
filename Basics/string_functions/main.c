#include<stdio.h>
#include<string.h> // This contains necessary string functions.
#include<stdlib.h> // This contains the "strtol" function.

int main(int argc, char const *argv[])
{
  char fruitName[40];

  printf("Enter a fruit name: ");
  scanf("%39s", fruitName);

  char output[100];

  // Copying string (strcpy)
  // NOTE: In Wi ndows, this function has an safer variation "strcpy_s". USE THAT.
  //       In Unix, use the safer "strncpy" function. USE THAT.
  // In that new variation, we have to specify how many bytes we may write in the second (Windows) or third (Unix) parameter using "sizeof(destination_string)".
  // In the size parameter, we're subtracting 1 beacuse one space has to be reserved for the null or termination character.
  strncpy(output, fruitName, sizeof(output) - 1);

  // Concatenating string (strcat)
  // NOTE: In windows, this function has an safer variation "strcat_s". USE THAT.
  //       In Unix, use the safer "strncat" function. USE THAT.
  strncat(output, " is", sizeof(output) - 1);
  strncat(output, " a good fruit.", sizeof(output) - 1);

  // Printing string (puts)
  // The "puts" function automatically appends a newline character at the end of the string.
  puts(output);

  // Printing single character (putchar)
  // The "putchar" prints a single character. But UNLIKE "puts", it doesn't append a new line.
  putchar(output[0]);
  putchar('\n');

  // Comparing strings (strcmp)
  // This function returns 0 when two stirngs are equal
  // In Unix, we're using it's safer variant "strncmp".
  int comparisonResult = strncmp(fruitName, "Apple", sizeof(fruitName) - 1);
  printf("%d\n", comparisonResult);

  // Converting string to integer (long) (strtol)
  // This function is used for parsing an integer (long) from a string.
  // It takes string pointer as its second parameter where it stores the non-numeric part
  // of the string. We can pass NULL pointer there if we don't need that. It takes the
  // base of the number to be parsed as its third parameter. For decimal numbers,
  // it would be 10.
  char* sampleString = "12345 This is a test 123.";
  long parsedNumber;
  char* nonNumericPart;

  // Note that the function will parsed only if the given string STARTS with a number. It will
  // only parse the FIRST numeric part.
  parsedNumber = strtol(sampleString, &nonNumericPart, 10);

  printf("Parsed number: %ld\n", parsedNumber);
  puts(nonNumericPart);

  return 0;
}
