#include<stdio.h>

int main(int argc, char const *argv[])
{
  int num;

  printf("Enter a number: ");
  scanf("%d", &num);

  // Note that if we mistakenly use assignment operator instead of equality operator, the
  // program will actually compile because it's a VALID operation. Here, the expression
  // "num = 64" will return the value of the variable num which will be 64. The "if" statement
  // will consider any non zero value as true and hence the condition will be evaluated as true.
  if(num = 64)
  {
    printf("num = %d\n", num);
  }

  return 0;
}
