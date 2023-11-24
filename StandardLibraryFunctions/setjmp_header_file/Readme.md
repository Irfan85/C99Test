# The `setjmp.h` header file

This header file contains utilities that implement the functionality of "goto". These
functionalities are called non-local jumping. Even though the usage of jump is discouraged,
many modern programming languages implicitly uses non-local jumping under the hood while
using 'try', 'catch' and 'throw' keywords.

- `setjmp`: This macro saves the current program state (stack pointer, frame pointer,
  program counter) of the current position. This is like labelling a position of
  the program.

- `longjmp`: This macro resets the stack pointer, frame pointer and program counter
  to the point where `setjmp` was called. So, this is like jumping back to a label.

- `jmp_buf`: A data structure that holds a jump buffer.
