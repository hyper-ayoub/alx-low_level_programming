#include <stdio.h>

/**
 * print_numbers - function that prints numbers
 * Return: NULL
 */

void print_numbers(void)
{
char c;
for (c = '0'; c <= '9'; c++)
{
putchar(c);
}
putchar('\n');
}
