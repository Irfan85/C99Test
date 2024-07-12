#include<stdio.h>

int main(int argc, char* argv[])
{

  // Defining strings as character array makes them MUTABLE
  char name[] = "Hello";

  char* ap = name;

  ap += 2;

  *ap = 'p'; // Like this, we can CHANGE any character in it.

  printf("%s\n", name);

  // However, defining strings as character pointer makes them IMMUTABLE.
  // It's actually defined as const char*, even if we don't put that "const" ourselves.
  // C does this for backward compatibility with older versions.
  char* namePointer = "Hello";

  ap = namePointer;

  ap += 2;

  // This will cause a segmentation fault as the string is IMMUTABLE.
  // *ap = 'p';

  return 0;
}
