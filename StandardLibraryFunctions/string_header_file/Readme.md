# The `string.h` header file

## String manupulation

- `strcpy`: Copies string
- `strncpy`: Safer version of `strcpy`
- `strcat`: Concatenate string
- `strncat`: Safer version of `strcat`
- `strxfrm`: Transforms upto 'n' characters of the source string to the currently selected
  locale.
- `strtok`: Tokenizes string.

## String comparison

- `strcmp`: Compares two string
- `strncmp`: Safer version of `strcmp`
- `strcoll`: Compares two string using the currently selected locale

## String metadata

- `strlen`: Returns the length of string WITHOUT the null termination character.
- `strchr`: Finds the first occurrence of given character
- `strrchr`: Finds the last occurrence of given character
- `strspn`: Returns the count of matching characters between two strings
- `strcspn`: Returns the count of non-matching chracters from between two strings
- `strpbrk`: Retuns the first character in string1 that matches any character in string2
  EXCLUDING the null termination character.
- `strstr`: Returns the first occurrence of substring string2 inside string1 EXCLUDING the
  null termination character.

## Error handling

- `strerror`: Used for priting the error string using the error number defined in the
  `errno.h` header file.

## Memory functions

- `memset`: Stores data in a given pointer
- `memcpy`: Copies 'n' bytes from one pointer to another. In this case the two chunks
  CANNOT overlap.
- `memmove`: Same as `memcpy`, but in this case the two chunks of memory CAN overlap
- `memcmp`: Compares upto 'n' bytes of two chunks of memory and returns 0 if they are
  equal.
- `memchr`: Finds the first occurrence of given character within the first 'n' bytes in
  the memory chunk.
