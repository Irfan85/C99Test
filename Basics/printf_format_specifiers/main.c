#include <stdio.h>

int main(int argc, char* argv[])
{

  // There are many format modifiers. A handful of them are mentioned here.
  int a = 17;
  float b = 4.5;
  char c = 'a';
  double d = 4.56758678547;
  char* e = "Hello!";
  unsigned int g = 3251235315;

  // SIGNED INTEGER in DECIMAL format
  printf("Decimal a = %d\n", a);

  // SIGNED INTEGER in HEXADECIMAL format
  printf("Hexadecimal a = %x\n", a);

  // SIGNED INTEGER in OCTAL format
  printf("Octal a = %o\n", a);

  // FLOAT
  printf("b = %.2f\n", b);

  // FLOAT in SCIENTIFIC notation
  printf("Scientific noatation b = %.2e\n", b);

  // CHARACTER
  printf("c = %c\n", c);

  // DOUBLE
  printf("d = %.2lf\n", d);

  // STRING
  printf("e = %s\n", e);

  // UNSIGNED INTEGER
  printf("g = %u\n", g);

  return 0;
}
