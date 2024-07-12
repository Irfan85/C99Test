#include<stdio.h>
#include<time.h> // Date-time related functionalities are in this file

int main(int argc, char const *argv[])
{
  // The time_t macro is used for storing an unix-time. It'a actually an ordinary
  // "long" under the hood.
  time_t rawTime = time(NULL);

  printf("Unix-Time: %ld\n", rawTime);

  // The "tm" structure holds broken down unix-time into year, month, date etc individual properties.
  // Note that "tm" starts counting year relative to year "1900". So, we have to add 1900
  // to the year value to get the actual year. We also have to add 1 to month as it starts counting
  // monts from 0.
  // The localtime takes an unix-time and break it down to a "tm". It then returns a pointer to that "tm" structure.
  struct tm *ptm = localtime(&rawTime);

  printf("The time is: %02d/%02d/%04d %02d:%02d:%02d\n",
            ptm -> tm_mday, ptm -> tm_mon + 1, ptm -> tm_year + 1900,
            ptm -> tm_hour, ptm -> tm_min, ptm -> tm_sec);

  return 0;
}
