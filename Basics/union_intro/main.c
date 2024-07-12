#include<stdio.h>

int main(int argc, char const *argv[])
{
  // Unions are like structs, but we can only assign ONE PROPERTY AT A TIME.
  // This is because in a union, all of the properties will point to a SINGLE memory location.
  union StringOrInt
  {
    char text[100];
    int number;
  };

  // Since we're passing a string, ONLY the string property will be populated.
  union StringOrInt soi1 = { "Twenty Five" };

  puts("After assigning text...");

  printf("Text: %s\n", soi1.text);
  // Note that the number will contain garbage value as it hasn't been assigned.
  printf("Number: %d\n", soi1.number);

  // Now, we're populating the numbe property and the string property will be automatically de-populated.
  soi1.number = 25;

  puts("After assigning number...");

  printf("Number: %d\n", soi1.number);
  // Note that the text property has been de-populated after assigning the numbe property.
  printf("Text: %s\n", soi1.text);


  return 0;
}
