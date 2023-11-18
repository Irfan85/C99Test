#include<stdio.h>
#include<stdlib.h> // Contains the "exit" function
#include<string.h>

struct Person
{
  char name[100];
  unsigned int age;
};


int main(int argc, char const *argv[])
{
  char* fileName = "rawData.txt";

  // Writintg raw data

  FILE* fileHandle;

  char nameInput[100];
  unsigned int ageInput;

  printf("Enter Person Name (Without space): ");

  scanf("%100s", nameInput);

  printf("Enter Person Age: ");

  scanf("%d", &ageInput);

  struct Person person;

  strcpy(person.name, nameInput);
  person.age = ageInput;

  fileHandle = fopen(fileName, "a");

  if(fileHandle == NULL)
  {
    puts("ERROR OPENING FILE");
    exit(1);
  }

  fwrite(&person, sizeof(struct Person), 1, fileHandle);

  puts("The file has been saved.");

  fclose(fileHandle);

  // Reading raw data

  fileHandle = fopen(fileName, "r");

  if(fileHandle == NULL)
  {
    puts("ERROR OPENING FILE");
    exit(1);
  }

  struct Person personFromFile;

  // Will read 1 Person at a time because of the specified size in the second parameter.
  while(fread(&personFromFile, sizeof(struct Person), 1, fileHandle))
  {
    printf("Name: %s, Age: %d\n", personFromFile.name, personFromFile.age);
  }

  fclose(fileHandle);

  return 0;
}
