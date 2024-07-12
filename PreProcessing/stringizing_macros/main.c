#include<stdio.h>

// Returning the value of a function-like macro will wrap its output with double
// quotes, thus stringizing them. Check out the ".i" file for demonstration.
#define STR(S) #S

int main(int argc, char const *argv[])
{
  // We don't have to put double quotes as the stringizing macro will do that.
  puts(STR(Hello World!));
  return 0;
}
