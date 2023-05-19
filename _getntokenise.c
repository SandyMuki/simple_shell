#include "main.h"

/**
 * getntok - get string and tokenise to an array of strings
 * @mpath: pointer to array of mpath to clean
 *
 * Return: array of input strings
 */

char **getntok(char **mpath)
{
	char *lineptr = NULL, **tokens, *token;
	size_t n = 0;
	int i = 0;

	if ((getline(&lineptr, &n, stdin)) == -1)
	{
		free(lineptr);
		free_arr(mpath);
		exit(EXIT_FAILURE);
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
	token = _strtok(lineptr, " ");
	i = 0;
	while (token != NULL)
	{
		tokens[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (tokens[i] == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		_strcpy(tokens[i++], token);
		token = _strtok(NULL, " ");
	}
	tokens[i] = NULL;
	/*Note: free memory in array in main function once usage complete*/
	free(lineptr);
	return (tokens);
}
