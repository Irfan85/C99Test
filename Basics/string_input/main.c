#include<stdio.h>

int main(int argc, char const *argv[])
{
  // Will hold name of max 39 chars. One space is reserved for null (\0) character.
  char name[40];

  // We can specify the max allowed character number in the "%s" format specifier.
  // Note that ampercent '&' isn't required for arrays since array names alrady refer to a pointer.
  scanf("%39s", name);

  printf("Hello %s\n", name);

  return 0;
}
