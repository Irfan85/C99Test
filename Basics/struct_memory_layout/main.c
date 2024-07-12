#include<stdio.h>
#include<stddef.h> // Contains the "offsetof" macro

int main(int argc, char const *argv[])
{
  // Let's say we have this structure
  // How much bytes this structure will allocate? It might seem that since int is 4
  // bytes and char is 1 byte, this would take 5 bytes in total. However that's not
  // the case. This is because in 64 bit machines, a single WORD of memory is
  // consisted of 8 bytes. For 32 bit machines, this would be 4 bytes.
  // This is because The CPU reads one WORD of memory in a single cycle.
  // So this structure will allocate 8 bytes where 5 bytes
  // will be used by the properties and 3 bytes will be kept as PADDING. Doing so is
  // important for MEMORY ALIGNMENT. So, the layout will look like this:
  // | 1 (char) | 3 (padding) | 4 (int) |
  typedef struct Grade {
    char letter;
    int rank;
  } Grade;

  Grade grade1 = { 'A', 90 };

  // "size_t" is a built-in type provided by c for storing the output produced by the
  // "sizeof" operator. Underneath, it's just an unsigned long.
  size_t letterSize = sizeof(grade1.letter);
  size_t rankSize = sizeof(grade1.rank);
  size_t paddingSize = sizeof(grade1) - (letterSize + rankSize);

  // The format specifier of "size_t" type is "%zu". Here "z" indicates "size_t" and "u"
  // indicates unsigned.
  printf("Size of letter: %zu\n", letterSize);
  printf("Size of rank: %zu\n", rankSize);
  printf("Size of padding: %zu\n", paddingSize);
  printf("Total Structure Size: %zu\n", sizeof(grade1));

  // The padding is typically placed IN-BETWEEN the properties. We can get an idea of the
  // position of properties within the memory work by using the "offsetof" macro.
  size_t letterOffset = offsetof(Grade, letter);
  size_t rankOffset = offsetof(Grade, rank);

  printf("Offset of letter: %zu\n", letterOffset);
  printf("Offset of rank: %zu\n", rankOffset);

  // Another example. Let's assume we're in a 32 bit machine where one word = 4 bytes;
  // For this structure, the machine will allocate 8 bytes in TWO SEPARATE words. The
  // first word will only conatin a1 and a2. The rest of the spaces will be left blank
  // as padding. The integer b1 will stay solely in the second word. This is because if
  // C started putting the integer from the 2 leftover bytes of the first word, evertime we
  // wanted to access the int, the CPU had to fetch the data of that int from 2 words using
  // 2 separate CPU cyles, which would cost performance. Hence, putting the int solely in
  // the next word allows the CPU to read the int using just one cycle. Here, C is compromising
  // memory space for getting better performance.
  // | 1 (char) | 1 (char) | 2 (padding) |
  // | 4 (int) |
  typedef struct TestStruct {
    char a1; // 1 byte
    char a2; // 1 byte
    int b1; // 4 byte
  } TestStruct;

  // THE ORDER OF PROPERTIES MATTERS.

  // This structure has the same properties as the previous one with different order.
  // However, this will take 12 bytes in a 32 bit system.
  // | 1 (char) | 3 (padding) |
  // | 4 (int) |
  // | 1 (char) | 3 (padding) |
  typedef struct TestStruct2 {
    char a1; // 1 byte
    int b1; // 4 byte
    char a2; // 1 byte
  } TestStruct2;

  // STUCTURE PADDING is the default baviour of C. If we want to disable it, we can write the
  // following line after the input statements.
  // #pragma pack(1)

  return 0;
}
