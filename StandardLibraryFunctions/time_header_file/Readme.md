# The `time.h` header file

## Core functions

- `clock`: Returns the clock ticks of the processor since the beginning of program.
  Dividing the difference between two "clocks" with CLOCKS_PER_SEC will give the
  execution time of any code in-between the two `clock` calls.
  This is Useful for measuring performance.
- `difftime`: Returns the difference between two `time_t` structures in seconds
- `time`: Retuns current calendar time

# Conversion and formatting functions

- `strftime`: Returns a string following a specific time format
- `mktime`: Converts a `tm` pointer to a `time_t` struct in local time.
- `localtime`: Reverse of `mktime`.
- `gmtime`: Converts a `tm` pointer to a `time_t` struct in UTC/GMT time.
- `ctime`: Takes a `time_t` struct and returns its string representation in local time.
- `asctime`: Returns the string representation of a `tm` pointer.
