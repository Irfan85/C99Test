# The `errno.h` header file

- `errno`: A global variable that's used by system calls for communicating an
  error code
- `EDOM`: A macro that can be compared against the `errno` and represents any DOMAIN
  error while using a mathematical function.
- `ERANGE`: A macro that can be compared against the `errno` and represents any RANGE
  error while using a mathematical function.
- `ENOENT`: A certain value of `errno` that occurs when the program fails to open a file.
