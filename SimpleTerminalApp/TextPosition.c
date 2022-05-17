#include <stdio.h>
#include <signal.h>
#include "TerminalControl.h"

void onWindowSizeChanged() {
    tc_clear_screen();

    int cols = 0;
    int rows = 0;
    tc_get_cols_rows(&cols, &rows);

    tc_move_cursor((cols-12)/2, rows/2);

    printf("%s%sHello World!\n%s", TC_YEL, TC_BG_GRN, TC_NRM);
}

int main() {

    // We are listening to window size change signal
    signal(SIGWINCH, &onWindowSizeChanged);

    // Turn off echoing input characters
    tc_echo_off();

    // Now we will enter inside an alternative screen
    tc_enter_alt_screen();

    tc_clear_screen();

    int cols = 0;
    int rows = 0;
    tc_get_cols_rows(&cols, &rows);

    tc_move_cursor((cols-12)/2, rows/2);

    printf("%s%sHello World!\n%s", TC_YEL, TC_BG_GRN, TC_NRM);

    // We're doing this we want the application to keep running until we press a key
    char c = getchar();

    // Turns on echoing input characters back
    tc_echo_on();

    tc_exit_alt_screen();

    return 0;
}
