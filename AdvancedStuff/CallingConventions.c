#include <stdio.h>

/*
    In C, we can define how a function will be called by specifying the calling convension before the
    name of the function. Calling convensions typically define these things
    a. How the parameters are passed (left to right or right to left)
    b. How the return value will be passed
    c. Who will clean the stack? The caller of the calee

    Arguments or the parameters of a function are stored in a stack
*/

// The "_stdcall" calling convention passess parameters from right to left and the callee will clean up
// the stack
int _stdcall add1(int a, int b)
{
    return a + b;
}

// The "_cdecl" calling convension also passess parameters from right to left however, the caller cleans up
// the stack in this case. It's the default calling convension in C
int _cdecl add2(int a, int b)
{
    return a + b;
}

int main()
{
    add1(4, 5);
    add2(4, 5);
 
    return 0;
}