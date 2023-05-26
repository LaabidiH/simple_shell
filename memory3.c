#include "shell.h"

/**
 * active - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if active mode, 0 otherwise
 */
int active(comm_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int delim(char a, char *c_delim)
{
	while (*c_delim)
		if (*delim++ == a)
			return (1);
	return (0);
}

/**
 * alpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int alpha(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int atoi(char *w)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; w[i] != '\0' && flag != 2; i++)
	{
		if (w[i] == '-')
			sign *= -1;

		if (w[i] >= '0' && w[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (w[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
