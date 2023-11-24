#include<stdio.h>
#include<signal.h>

int main(int argc, char const *argv[])
{
  signal(SIGABRT, SIG_IGN); // We're telling the program to ignore the abort signal

  raise(SIGABRT); // We're raising the abort signal

 // The program ignores that signal and so, doesn't stop the execution. As a result,
 // this line is printed.
  puts("Hello World!");

  return 0;
}
