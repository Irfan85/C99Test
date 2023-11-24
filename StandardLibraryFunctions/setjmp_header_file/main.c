#include<stdio.h>
#include<setjmp.h>

int main(int argc, char const *argv[])
{
  jmp_buf jumpBuffer;

  if(setjmp(jumpBuffer) == 2)
  {
    puts("This will print after longjmp is called.");
  }
  else
  {
    puts("Calling longjmp.");

    longjmp(jumpBuffer, 2);
  }

  return 0;
}
