#include "shell.h"

/**
 * rmnlc - function that removes new line character from
 * the user input
 * @str: the user input
 * @lnt: user input lenght
 * Return: the comand without the new line charaxter
 * at the end
 */

char *rmnlc(char *str, int lnt)
{
	if (lnt > 0 && str[lnt - 1] == '\n')

	{
		str[lnt - 1] = '\0';
	}

	return (str);
}
