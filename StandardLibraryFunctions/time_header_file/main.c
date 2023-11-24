#include<stdio.h>
#include<time.h>

int main(int argc, char const *argv[])
{
  unsigned long count = 0;

  clock_t startClock = clock();

  for(int i = 0; i < 2e+9; i++)
  {
    count++;
  }

  clock_t endClock = clock();

  double requiredTime = (endClock - startClock) * 1.0 / CLOCKS_PER_SEC;

  printf("Time required for loop execution: %lf seconds.\n", requiredTime);

  return 0;
}
