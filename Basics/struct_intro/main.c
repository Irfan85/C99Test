#include<stdio.h>

int main(int argc, char const *argv[])
{
  // We can hold related data in a struct
  struct Person
  {
    char name[100];
    int age;
  };

  struct Person person1 = { "Akkas Ali", 25 };

  printf("Name: %s, Age: %d\n", person1.name, person1.age);

  return 0;
}
