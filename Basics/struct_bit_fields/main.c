#include<stdio.h>

int main(int argc, char const *argv[])
{
  // We can manually specify how many bits a property of a strucure
  // can occpy using bit fields. This helps us to grain more granular
  // controls.
  struct
  {
    unsigned int jerseyNumber : 5; // This property will take 5 BITS.
    unsigned int rank : 2;  // This property will take 3 BITS.
  } player1;

  // We can see that this structure is taking only 4 bytes of memory instead
  // of taking 8 bytes.
  printf("With bit fields: %zu\n", sizeof(player1));

  // Here's an example of a structure without bit fields just for comparison.
  struct {
    unsigned int jerseyNumber;
    unsigned int rank;
  } player2;

  printf("Without bit fields: %zu\n", sizeof(player2));

  return 0;
}
