# The `stdlib.h` header file

## Conversion functions

- `atoi`: Converts a C string (char\*) to an integer
- `atol`: Converts a C string (char\*) to a long integer
- `strtod`: Converts the first numeric part found in a string to double
- `strtol`: Converts the first numeric part found in a string to long
- `strtoul`: Converts the first numeric part found in a string to unsigned long

## Memory functions

- `malloc`: Allocates memory
- `calloc`: Allocates memory and initializes them with 0
- `realloc`: Given a pointer, reallocates memory with a new size
- `free`: Frees up chunks of memory.

## Process and program functions

- `abort`: Will stop the program abnormally.
- `atexit`: It takes a function pointer and will call that function before the program
  exits. Typically, a cleanup function is passed here.
- `exit`: Will exit the program normally.
- `getenv`: Will get an environment variable
- `system`: Executes a shell command that is passed to it as a string.

## Algorithms

- `bsearch`: Binary search
- `qsort`: Quick sort

## Math related

- `abs`: Returns integer absolute value
- `lab`: Returns long integer absolute value
- `div`: Divides two integers. This is was useful before C99 where the behaviour of integer
  division, especaily in case of negative operands denended on compiler implementation. So, the `div` function was used for making sure a division produces
  the same output irrespective of compiler implementation. Since C99, the `/` and `%`
  operators are guranteed to produce same output across compilers.
- `ldiv`: Same as `div` but for long integers.
- `rand`: Returns a random integer number between 0 and `RAND_MAX`.`RAND_MAX` is a macro
  defined in the `stdlib.h` header file.
- `srand`: This function seeds the random number genreator. It's typically used in tandem
  with `rand`. Setting a constant value here will make sure that the random numbers are
  **REPRODUCIBLE** across tests. It makes debugging and testing easier. In non-testing
  environments, the sytem time is passed here for making sure that the generated numbers
  are as much random as possible.

## Multi-byte character functions (Used for dealing with unicode)

- `mbstowcs`: Converts multi-byte string to wide character string.
- `mbtowc`: Converts one multi-byte character to a wide character.
- `mblen`: Returns the length of a multi-byte character.
- `wcstombs`: Converts an array of wide characters to multi-byte characters.
- `wctomb`: Converts a wide character to a multi-byte character.
