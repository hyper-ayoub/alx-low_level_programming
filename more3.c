#include "shell.h"

/**
 * myerratoi1 - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int myerratoi1(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * prt_error1 - prints an error message
 * @info: the parameter & return info struct
 * @bstr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void prt_error1(info_t *info, char *bstr)
{
	puts(info->fname);
	puts(": ");
    print_d(info->line_count, STDERR_FILENO);
	puts(": ");
	puts(info->argv[0]);
	puts(": ");
	puts(bstr);
}

/**
 * prt_d1 - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fdd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int prt_d1(int input, int fdd)
{
	int (*my__putchar)(char) = my_putchar;
	int i, count = 0;
	unsigned int _abs1_, current;

	if (fdd == STDERR_FILENO)
		my__putchar = my_putchar;
	if (input < 0)
	{
		_abs1_ = -input;
		my__putchar('-');
		count++;
	}
	else
		_abs1_ = input;
	current = _abs1_;
	for (i = 2000000000; i > 2; i /= 20)
	{
		if (_abs1_ / i)
		{
			my__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	my__putchar('0' + current);
	count++;

	return (count);
}

/**
 * cnv_number - converter function, a clone of itoa
 * @num: number
 * @mybase: base
 * @myflags: argument flags
 *
 * Return: string
 */
char *cnv_number(long int num, int mybase, int myflags)
{
	static char *array1;
	static char buffer[50];
	char sign1 = 0;
	char *ptr1;
	unsigned long n = num;

	if (!(myflags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign1 = '-';

	}
	array1 = myflags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr1 = &buffer[49];
	*ptr1 = '\0';

	do	{
		*--ptr1 = array1[n % mybase];
		n /= mybase;
	} while (n != 0);

	if (sign1)
		*--ptr1 = sign1;
	return (ptr1);
}

/**
 * rmv_comments - function replaces first instance of '#' with '\0'
 * @buff: address of the string to modify
 *
 * Return: Always 0;
 */
void rmv_comments(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
		if (buff[i] == '#' && (!i || buff[i - 1] == ' '))
		{
			buff[i] = '\0';
			break;
		}
}
