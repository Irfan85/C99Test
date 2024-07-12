#include<stdio.h>
#include<string.h>

// Function pointers are useful for calling function dynamically at runtime,
// writing asynchronous code, exposing APIs etc. There are many ways to use them and
// a common use case is to use them with strures so we'll use that as example.

typedef struct
{
  char name[100];
  const char* language;
  void (*sayGreeting)(); // This is a function pointer
} Person;

void sayEnglishGreeting();
void saySpanishGreeting();

int main(int argc, char const *argv[])
{
  void (*greeting)();

  if(argc > 1)
  {
    // Just like variables, we can use the "address of" operator '&' with functions
    // for refering to their pointer.
    greeting = !strncmp("Spanish", argv[1], 7) == 0 ? &sayEnglishGreeting : &saySpanishGreeting;
  }
  else
  {
    puts("Please pass the language of ther person as an argument.");
    return 1;
  }

  Person person = {"Akkas Ali", argv[1], greeting};

  printf("Name: %s\nNationality: %s\n", person.name, person.language);
  person.sayGreeting();

  return 0;
}

void sayEnglishGreeting()
{
  puts("Hello!");
}

void saySpanishGreeting()
{
  puts("Hola!");
}
