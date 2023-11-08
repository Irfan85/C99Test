#include<stdio.h>

int main(int argc, char const *argv[])
{

  // The "typedef" storage class
  // This storage class is used for structs. It makes a custom "type" from a struct
  // that can be declared using the curther keyword.
  // Note that in typedef structs, the name comes at last.
  typedef struct
  {
    char name[100];
    int age;
  } Person;

  // Since Person is typedef, we don't have to write "struct Person".
  Person p1 = { "Akkas Alil", 25};

  // The "auto" (default for local variables) class type.
  // Vaiables of this class will get AUTOMATICALLY CLEARED from the memory when their
  // scope gets destroyed.
  // Auto variables are stored in the STACK. This storage class is ONLY applicable for
  // LOCAL variables.
  auto int a = 10;

  // The "register" class types.
  // Variables of this class are stored in the CPU register instead of the RAM.
  // So, accessing time of them will be faster compared to non-register variables.
  register int b = 20;

  // The "static" (default for global variablesa) class type.
  // These variables live througout the program's lifetime. So, only a single copy of this
  // is shared throutout the program.
  static int c = 30;

  // The "extern" storage class is used for referring to a variable/function that is declared in
  // another file or outside the current scope. Extern stands for "External Reference". To
  // learn more about this, go to "StorageClasses/ExternalStorageClass.c" file.

  return 0;
}
