# Undefining and Re-defining Macros

## Undefining macros

Use `#undef <MACRO_NAME>` for undefining a macro. It will have no effect if the
macro doesn't exist.

## Re-defining macros

If we want to re-define a macro, we can do so using `#define <MACRO_NAME`, again.
But the new value of the macro must follow these rules to be valid re-definition:

- The type of macro cannot change. So, if a macro is object-like, the new value must
  be object-like. Same goes for function-like macros.
- The new value must consist of same set of tokens.
- If the macro is function-like, it must have same set of parameters.
- Whitespaces between token should be in the same position. However, the count of
  whitespaces can change. So, "2 + 2 + 3" can be re-defined to "2 + 2 + 2", but not
  "2+2+2".
