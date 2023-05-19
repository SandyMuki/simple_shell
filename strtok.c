#include "main.h"

/**
 * _strtok - tokenising our string
 * @str: string to tokenise
 * @delimit: delimiting pointer
 *
 * Return: string token
 */

char *_strtok(char *str, const char *delimit)
{
	const char *d;
	static char *token;

	if (str != NULL)
	{
		token = str;
	}
	else
	{
		if (*token == '\0')
		{
			return (NULL);
		}
		str = token;
	}
	while (*token != '\0')
	{
		d = delimit;
		while (*d != '\0')
		{
			if (*token == *d)
			{
				*token = '\0';
				token++;
				if (str == token)
				{
					str++;
					continue;
				}
				return (str);
			}
			d++;
		}
		token++;
	}
	return (str);
}
