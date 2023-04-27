#include "shell.h"

/**
 *e_puts - prints an input string
 * @str: this is the string to be printed
 * Return: Nothing is returned
 */
void e_puts(char *str)
{
	int e = 0;

	if (!str)
		return;
	while (str[e] != '\0')
	{
		e_putchar(str[e]);
		e++;
	}
}

/**
 * e_putchar - writes the character c to stderr
 * @c: The character is to be printed
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int e_putchar(char c)
{
	static int e;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || e >= WRITE_BUF_SIZE)
	{
		write(2, buf, e);
		e = 0;
	}
	if (c != BUF_FLUSH)
		buf[e++] = c;
	return (1);
}

/**
 * put_fd - writes the character c to given fd
 * @c: The character is to be printed
 * @fd: The filedescriptor to write on
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int put_fd(char c, int fd)
{
	static int e;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || e >= WRITE_BUF_SIZE)
	{
		write(fd, buf, e);
		e = 0;
	}
	if (c != BUF_FLUSH)
		buf[e++] = c;
	return (1);
}

/**
 *put_sfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write on
 * Return: the number of chars put
 */
int put_sfd(char *str, int fd)
{
	int e = 0;

	if (!str)
		return (0);
	while (*str)
	{
		e += put_fd(*str++, fd);
	}
	return (e);
}
