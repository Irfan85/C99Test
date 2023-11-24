# Extra Notes

## Key points to remember

- In C, the `switch` statement ONLY supports CHAR and INT types. We cannot use strings like
  many high level languaes in C.
- In function prototype, use "void" keyword to indicate "no arguments" like this
  ```C
  int abc(void);
  ```
- Avoid modifying global variables directly using functions. By doing so, programs become
  hard to track. Pass variables using references in such use cases as much as possible.
