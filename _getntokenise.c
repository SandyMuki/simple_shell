#include "main.h"

/**
 * getntok - get string and tokenise to an array of strings
 * @mpath: pointer to array of mpath to clean
 * @exit_stat: exit status of previous program
 *
 * Return: array of input strings
 */

char **getntok(char **mpath, int exit_stat)
{
	char *lineptr = NULL, **tokens, *token;
	size_t n = 0;
	int i = 0;

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);
	if ((getline(&lineptr, &n, stdin)) == -1)
	{
		free(lineptr);
		free_arr(mpath);
		exit(exit_stat);
	}
	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == '\n')
			lineptr[i] = '\0';
	}
	tokens = malloc(sizeof(char *) * (wordcount(lineptr) + 1));
	if (tokens == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	token = strtok(lineptr, " ");
	i = 0;
	while ((token != NULL) && !(__strcmp(token, "#") == 0))
	{
		tokens[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (tokens[i] == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		_strcpy(tokens[i++], token);
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	free(lineptr);
	return (tokens);
}
