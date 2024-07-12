# The `stdarg.h` header file

This header file contains tools for building variadic functions (Functions) that
take variable number of arguments.

- `va_start`: A macro that initializes the vairbale argument list
- `va_arg`: A macro that fetches next argument of a given type from the variable
  argument list
- `va_end`: A macro that cleans up the variable argument list after the variadic function
  is done with processing all the arguments. It must be called after dealing with
  all variable arguments. Not doing so may trigger undefined behaviour.
- `va_list`: A data structure for holding the list of variable arguments.
