# Pre-processor and pre-processor directives

## Types of macros

- Object Like: `#define IS_LINUX 1`
- Function like: `#define SQUARE(X) (X*X)`

## Some more macros include:

- `pragma`: Used for providing additional information to the compiler. For instance,
  `pragma once` tells the compiler to read a header file only once.

- `__DATE__`: This macro stores the current system date.
- `__TIME__`: This macro stores the current system time.
- `__func__`: This macro stores the current function name.
