# The `stdio.h` header file

## Formatted I/O

- `fprintf`: Used for formatted file writing
- `fscanf`: Used for formatted file reading
- `vfprintf`: Formatted file writing with variable argument list
- `printf`: Formatted writing to console
- `scanf`: Formatted reading from console
- `vprintf`: Formatted writing to console with variable argument list
- `sprintf`: Formatted writing to a C string
- `sscanf`: Formatted reading from a C string
- `vsprintf`: Formatted writing to a C string with variable argument list

## File I/O

- `fread`: Reads a specific amount (in bytes) of data from a file and puts
  the data in a void pointer
- `fwrite`: Writes a specific amount (in bytes) of data to a file
  the data in a void pointer

# Character I/O

- `fgetc`: Reads the next character from a file stream
- `fgets`: Reads a line from a file stream
- `fputc`: Write a character to the file stream
- `fputs`: Write a C string to the file stream
- `getchar`: Reads a character from console
- `putchar`: Writes a character to console

# File Operations

- `fclose`: Closes a file and flushes buffers
- `fopen`: Opens a file
- `freopen`: Re-opens a closed file
- `fflush`: Flushes buffers. Buffers are intermediary memory locations where data
  is temporarily stored before reading from or writing to a stream.
- `setvbuf`: Sets the buffers of a stream. It takes several options. The \_IOLBF
  option will write to the specified stream when the buffer becomes full. In this case,
  the buffer acts as a **Virtual Buffer**.
- `remove`: Removes a file
- `rename`: RENAMES or MOVES a file
- `tmpfile`: Creates a temporary file

# File Positioning

- `fgetpos`: Gets the cursor location of the file stream and put it to
  a pointer. This, is used alogside `fsetpos` to save a location of a file and jump
  back to it later.
- `fsetpos`: Sets the cursor position of a file stream
- `ftell`: Returns the current location of the cursor in file stream in INTEGRAL format.
  This is where it differs from `fgetpos`.
- `fseek`: Takes the file position in INTEGRAL format and seeks to that position. This
  is where it's different from `fsetpos`.
- `rewind`: Puts the cursor at the beginning of the file stream

# Error Handling

- `clearerr`: Clears any error or EOF indicators associated with a file stream. It can
  be used for keep processing the file after an error occurs.
- `feof`: Tests EOF indicator of a file stream.
- `ferror`: Tests error indicator of a file stream.
- `perror`: Prints error message after system error.
