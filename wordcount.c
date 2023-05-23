#include "main.h"

/**
 * wordcount - counts number of words input
 * @str: input string
 *
 * Return: number of words
 */

int wordcount(char *str)
{
	int count = 0;
	int len = _strlen(str);
	int i = 0;

	/* check if string is empty*/
	if (__strcmp(str, "") == 0)
		return (0);

	/* skip leading spaces and tabs */
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;

	while (i < len) /* word count */
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			count++;

			/* skip consecutive spaces and tabs */
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
		}
		else
			i++;
	}

	/* increment word count if last character is not a delimiter */
	if (str[len - 1] != ' ' && str[len - 1] != '\t' && str[len - 1] != '\n')
		count++;

	return (count);
}
