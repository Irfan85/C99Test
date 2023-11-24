#include<stdio.h>

int main(int argc, char const *argv[])
{
  FILE* file = fopen("text.txt", "w+");

  if(file == NULL)
  {
    printf("Operation failed.\n");
    return -1;
  }

  fpos_t position;
  if(fgetpos(file, &position) != 0)
  {
    printf("Operation failed.\n");
    return -1;
  }

  // The "position" variable is now pointing at the start of the file.

  // Now, let's write some content to that file.
  if(fputs("Hello World!", file) == EOF)
  {
    printf("Operation failed.\n");
    return -1;
  }

  // Now, put the cursor back to the beginning of the file using "fsetpos" and
  // applying the previously saved position.
  if(fsetpos(file, &position) != 0)
  {
    printf("Operation failed.\n");
    return -1;
  }

  // Now, let's write some more content.
  if(fputs("Hi ", file) == EOF)
  {
    printf("Operation failed.\n");
    return -1;
  }

  // Let's outptut the INTEGRAL position of the cursor
  printf("Stream position: %d\n", ftell(file));

  // We can see that the cursor is now in position "3", which makes
  // sense since we wrote 3 characters from the beginning in our last
  // write. Now, let's read the content of the file. Since the cursor is
  // in position '3', fgets will start to read from that position
  char data[128];

  if(fgets(data, 128-1, file) == NULL)
  {
    printf("Operation failed.\n");
    return -1;
  }

  printf("%s\n", data);

  // The cursor is now the the end of the file (Which is the 12th position in our case).
  printf("Stream position: %d\n", ftell(file));

  // Now, we will put the cursor at the beginning once again. But, this time, we'll
  // use "fseek".
  if(fseek(file, 0, SEEK_SET) != 0)
  {
    printf("Operation failed.\n");
    return -1;
  }

  // As expected, the cursor is at the beginning.
  printf("Stream position: %d\n", ftell(file));

  // Let's write some content again
  if(fputs("12 ", file) == EOF)
  {
    printf("Operation failed.\n");
    return -1;
  }

  return 0;
}
