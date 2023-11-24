#include<stdio.h>

int main(int argc, char const *argv[])
{
  FILE* file = fopen("formatted_text.txt", "r");

  if(file == NULL)
  {
    printf("Operation failed.\n");
  }

  char name[64];
  int age;
  char grade;

  int tokenCount;

  // The fscanf function returns the number of input tokens that it successfully
  // read. In our case, we expect 3 tokens for each line. The name, age and grade.
  // For name, one character is reserved for the null termination character.
  while((tokenCount = fscanf(file, "%63s    %d    %c\n", name, &age, &grade)) != EOF)
  {
    if(tokenCount == 3)
    {
      printf("---------------------------------------------------\n");
      printf("Full Name: %s\n", name);
      printf("Age: %d\n", age);
      printf("Grade: %c\n", grade);
      printf("---------------------------------------------------\n");
    }
  }

  if(ferror(file) != 0)
  {
    printf("Operation failed.\n");
    return -1;
  }

  if(fclose(file) != EOF)
  {
    printf("Operation failed.\n");
    return -1;
  }

  return 0;
}
