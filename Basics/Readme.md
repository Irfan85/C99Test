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
- In pointer arithmatic, if we have any pointer, for instance, an integer pointer pInt,
  the statement "pInt + 1" is implicitly calculated as "PInt + sizeof(int) \* 1".
  Similarly, the statement "pInt - 2" is implicitly calculated as
  "pInt + (sizeof(int) - 2)".
  That's how pointer arithmatic is different from numerical arithmatic.
