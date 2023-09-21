#include "shell.h"

/**
 * rputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void rputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_fputchar(str[i]);
		i++;
	}
}

/**
 * f_putchar - writes the character c to stderr
 * @d: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int f_putchar(char d)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (d != BUF_FLUSH)
		buf[i++] = d;
	return (1);
} 

/**
 * put_fd - writes the character d to given myfd
 * @d: The character to print
 * @myfd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int put_fd(char d, int myfd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(myfd, buf, i);
		i = 0;
	}
	if (d != BUF_FLUSH)
		buf[i++] = d;
	return (1);
}

/**
 * puts_fd - prints an input string
 * @str: the string to be printed
 * @myfd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int puts_fd(char *str, int myfd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += put_fd(*str++, myfd);
	}
	return (i);
}
