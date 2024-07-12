#include<stdio.h>
#include<stdlib.h>

void cleanup(void);

int main(int argc, char const *argv[])
{
  atexit(&cleanup);

  char* pathValue = getenv("PATH");

  puts(pathValue);

  puts("");

  system("ls");

  return 0;
}

void cleanup()
{
  puts("Exiting...");
}
