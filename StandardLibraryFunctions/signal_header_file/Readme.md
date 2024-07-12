# The `signal.h` header file

## Process signaling macros

- `SIGABRT`: Signals abnormal program termination
- `SIGFPE`: Signals when a floating point error is occurred
- `SIGILL`: Signals when an illegal operation is attempted
- `SIGINT`: Signals an interrupt (CTRL + C)
- `SIGSEGV`: Signals segmentation violoation (Illegal memory/data access)
- `SIGTERM`: Signals process termination
- `signal`: A function that takes a singla macro and a function pointer and registers
  the function that the pointer points to as the event handler for that signal
- `raise`: Takes a signal macro as argument and raises that signal
- `SFG_DFL`: This is the default signal handling function used by the `signal` function
- `SIG_IGN`: A macro that's used for ignoring a given signal by the running process. It
  is passed to the `signal` function for ignoring a specific signal.
