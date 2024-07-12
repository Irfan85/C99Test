#include <stdio.h>
#include "TerminalControl.h"
int main() {

    // Let's clear the terminal screen first
    // tc_clear_screen();

    // Let's move the cursor to (X, Y) row and column
    // tc_move_cursor(10, 5);

    // Let's change the whole terminal background color
    printf("%s", TC_BG_CYN); // Change the background color
    tc_clear_screen(); // Clear the screen with the new background color

    // We're shifting color to yellow, printing the string and again
    // returning to the normal color mode
    printf("%sHello World in Color!%s\n", TC_YEL, TC_NRM);

    // Were doing the same thing above but this time with a green background.
    // This background will only apply to the text. Not the whole terminal
    printf("%s%sHello World in Color!%s\n", TC_YEL, TC_BG_GRN, TC_NRM);


    return 0;
}