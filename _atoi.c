#include "shell.h"

/**
 * interacting - returns true if shell is interacting
 * @information: struct address
 *
 * Return: 1 if interacting, 0 otherwise
 */
int interacting(information_t *information)
{
	return (isatty(STDIN_FILENO) && information->readfd <= 2);
}

/**
 * is_delt - checks if character is a delimeter
 * @chk: the char to check
 * @delt: check the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delt(char chk, char *delt)
{
	while (*delt)
		if (*delt++ == chk)
			return (1);
	return (0);
}

/**
 *is_alpchr - checks for alphabetic character
 *@chk: The character to input
 *Return: 1 if c is alphabet, 0 otherwise
 */

int is_alpha(int chk)
{
	if ((chk >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_conv - converts a string to an integer
 *@string: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _conv(char *string)
{
	int b, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (b = 0;  string[b] != '\0' && flag != 2; b++)
	{
		if (string[b] == '-')
			sign *= -1;

		if (string[b] >= '0' && string[b] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (string[b] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		result = negative number;
	else
		result = positive number;

	return (result);
}
