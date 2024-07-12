#include <stdio.h>
#include "TerminalControl.h"
#include <sys/ioctl.h>

int main()
{
    /*
        In UNIX, everything is a file. Same is applicable for input and output streams.
        For instance, we have the three files for IO operaion
        File "0" is for standard input (stdin)
        File "1" is for standard output (stdout)
        File "2" is for standard error (stderr)
    */

    char *greetings = "Hello World!";
    printf("%s\n", greetings);

    // The above statement can also be written as
    fprintf(stdout, "%s\n", greetings);
     
    // Different terminal windows also have assosiated IO files. We can use them to communicate between terminals
    // Let's say we want to output to a terminal which is located at "/dev/pts/1". We can get this path by the 
    //"tty" command

    FILE *otherTerminal = fopen("/dev/pts/1", "w");
    fprintf(otherTerminal, "%s%sHello From the Other Terminal!\n%s", TC_YEL, TC_BG_GRN, TC_NRM);

    fclose(otherTerminal);

    // Writing to another terminal can also be done using the process id of that terminal. We can use
    // "ps -aux | grep pts" command to get the process ids of the active terminals. Once we know the process
    // id, we can write to that terminal in the following way

    FILE *otherTerminal2 = fopen("/proc/19016/fd/1", "w"); // Notice the "1" file in the "fd" directory of the process. It stands for output as we said before
    fprintf(otherTerminal2, "%s%sHello Again From the Other Terminal!\n%s", TC_YEL, TC_BG_GRN, TC_NRM);
    fclose(otherTerminal2);

    return 0;
}