#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
  // We can hold related data in a struct
  struct Person
  {
    char name[100];
    int age;
  };

  // We can access properties using the dot '.' operator. Apart from using that, we can
  // also initialize the properties in a single line like this. But we have to make sure
  // that they are in the CORRECT ORDER.
  struct Person person1 = { "Akkas Ali", 25 };

  printf("Name: %s, Age: %d\n", person1.name, person1.age);

  // If we want to initilize properties in a single line WITHOUT maintaining ORDER, we can
  // use DESIGTNATED INITIALIZATION.
  struct Person person2 = { .age = 30, .name = "Abdul Kuddus" };

  printf("Name: %s, Age: %d\n", person2.name, person2.age);

  // We can also declare structures and their variables at the same time
  struct Fruit
  {
    char name[100];
    char color[50];
  } apple, orange;

  // The char array properties in the structure aren't modifiable. So, we cannot assign
  // values to them directly as that would override the pointers. We have to use the
  // "strcpy" function instead for assigning values as this would simply copy the given
  // string to the locations where those pointers are pointing to.
  strcpy(apple.name, "Apple");
  strcpy(apple.color, "Red");

  strcpy(orange.name, "Orange");
  strcpy(orange.color, "Orange");

  printf("Fruit Name: %s, Color: %s\n", apple.name, apple.color);
  printf("Fruit Name: %s, Color: %s\n", orange.name, orange.color);

  // We can declare a structure and initialize their variables like this as well.
  struct Shape
  {
    char name[100];
    char color[50];
  } circle1= {"Circle 1", "Red"}, cube1 = { "Cube 1", "Blue"} ;

  printf("Shape Name: %s, Color: %s\n", circle1.name, circle1.color);
  printf("Shape Name: %s, Color: %s\n", cube1.name, cube1.color);

  return 0;
}
