#include<stdio.h>

// The __VA_ARGS__ macro holds the list of variable macro arguments
#define VARIADIC_TYPE_1(...) printf(__VA_ARGS__)

// Using __VA_ARGS__ is optional. We can use our own named list for variable
// arguments if we want.
#define VARIADIC_TYPE_2(args...) printf(args)

// Variable arguments can also come AFTER named parameters
#define VARIADIC_TYPE_3(x, args...) if(x) printf(args)


int main(int argc, char const *argv[])
{
  VARIADIC_TYPE_1("%d\n", 15);
  VARIADIC_TYPE_2("%d\n", 20);
  VARIADIC_TYPE_3(1, "%d\n", 25);

  return 0;
}
