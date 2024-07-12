#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/*
    This is a simple demonstration of the internal working of the printf function. There are two versions
    of printf created in this file. One utilizes C's built in variable argument functionality. Other
    goes a bit lower level and accesses the arguments of a function directly from the stack 
*/

int printf_new(char *pszFormatString, ...);
int printf_manual(char *pszFormatString, ...);

int _cdecl main(int argc, char *argv[])
{
    printf_new(argv[0]);
    printf_new("\nHello\n");
    printf_new("Test String %s with integer %i and %% test\n", argv[0], argc);

    printf_manual(argv[0]);
    printf_manual("\nHello\n");
    printf_manual("Test String %s with integer %i and %% test\n", argv[0], argc);

    return 0;
}

// This method demonstrates "printf" using built in "va_list" data structure
int printf_new(char *pszFormatString, ...)
{
    int CharacterCount = 0;
    int PrintInteger;
    char IntegerString[10];
    char *pPrintString;
    va_list VaList;

    va_start(VaList, pszFormatString);

    while (*pszFormatString)
    {
        if (*pszFormatString == '%')
        {
            pszFormatString++;
            switch (*pszFormatString)
            {
            case 's':
                pPrintString = va_arg(VaList, char *);
                // "puts()" automatically adds a newline character which we don't want. So, we're using
                // "fputs()" and directly writing to stdout instead 
                fputs(pPrintString, stdout);
                // Point to the next character of the format string
                pszFormatString++;
                CharacterCount += strlen(pPrintString);
                break;
            case 'i':
                PrintInteger = va_arg(VaList, int);
                _itoa(PrintInteger, IntegerString, 10);
                fputs(IntegerString, stdout);
                pszFormatString++;
                CharacterCount += strlen(IntegerString);
                break;
            case '%':
                putchar('%');
                pszFormatString++;
                CharacterCount++;
                break;
            case '\0':
                break;
            default:
                putchar('%');
                putchar(*pszFormatString);
                pszFormatString++;
                CharacterCount += 2;
            }
        }
        else
        {
            putchar(*pszFormatString);
            pszFormatString++;
            CharacterCount++;
        }
    }

    va_end(VaList);

    return CharacterCount;
}

// This methods reads arguments from the stack manually
int printf_manual(char *pszFormatString, ...)
{
    int CharacterCount = 0;
    int PrintInteger;
    char IntegerString[10];
    char *pPrintString;
    // We need a void pointer to store the memory address of the current argument in the stack
    void *StackLocation;

    // Firstly, we point to the fixed argument that is just before the variable argumet list
    StackLocation = &pszFormatString;
    // Then we incrememnt the pointer to point to the next stack element form where the list actually
    // begins. Here "StackLocation" itself is a void pointer that will point to any argument in that stack that
    // might be an int, double, char or string whatever. Now, we want to increase the stack position by one. So,
    // we need to point to the entire stack itself which will be a pointer to a pointer (void **)
    StackLocation = ((void **)StackLocation) + 1;

    while (*pszFormatString)
    {
        if (*pszFormatString == '%')
        {
            pszFormatString++;
            switch (*pszFormatString)
            {
            case 's':
                // If the argument is a string (char *), the stack location will be a pointer to a character
                // pointer. We will derefeerence that pointer to the character pointer and cast it to a char *
                pPrintString = (char *)*((char **)StackLocation);
                // Then we again incrase the stack location by 1
                StackLocation = ((void **)StackLocation) + 1;
                // "puts()" automatically adds a newline character which we don't want. So, we're using
                // "fputs()" and directly writing to stdout instead 
                fputs(pPrintString, stdout);
                // Point to the next character of the format string
                pszFormatString++;
                CharacterCount += strlen(pPrintString);
                break;
            case 'i':
                PrintInteger = (int)*((int *)StackLocation);
                StackLocation = ((void **)StackLocation) + 1;
                _itoa(PrintInteger, IntegerString, 10);
                fputs(IntegerString, stdout);
                pszFormatString++;
                CharacterCount += strlen(IntegerString);
                break;
            case '%':
                putchar('%');
                pszFormatString++;
                CharacterCount++;
                break;
            case '\0':
                break;
            default:
                putchar('%');
                putchar(*pszFormatString);
                pszFormatString++;
                CharacterCount += 2;
            }
        }
        else
        {
            putchar(*pszFormatString);
            pszFormatString++;
            CharacterCount++;
        }
    }

    return CharacterCount;
}