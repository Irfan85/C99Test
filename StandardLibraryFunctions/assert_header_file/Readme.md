# The `assert.h` header file

- `assert`: This macro takes and expression. If that expression evaluates to true,
  nothing happends. If it evaluates to false, then it writes an error message in the
  `stderr` stream and aborts the program immediately. Assertion is useful where fail-safety
  is crucial. They are also useful for writing tests.
