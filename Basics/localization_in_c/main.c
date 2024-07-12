#include<stdio.h>
#include<locale.h> // Localization related functionalities are in this file

int main(int argc, char const *argv[])
{
  // Set locale sets the localization format for the program. The first parameter
  // is the category (currency, decimal point format etc.). The second parameter is the
  // name of the locale. An empty string indicates the system default locale.
  setlocale(LC_ALL, "");

  // The "localeconv()" function returns information about the current locale in form of an
  // "lconv" struct pointer. This struct contains broken down locale information.
  const struct lconv* const currentLocale = localeconv();

  printf("In the currently selected locale, the currency symbol is %s.\n", currentLocale -> int_curr_symbol);

  return 0;
}
