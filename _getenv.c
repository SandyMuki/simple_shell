#include "main.h"
/**
 * _getenv - get path environment variable
 *
 *
 * Return: value of path variable
 */
char *_getenv()
{
	char *path = "PATH";
	int k;

	for (k = 0; environ[k]; k++)
	{
		if ((environ[k][0] == path[0]) &
				(environ[k][1] == path[1]) &
				(environ[k][2] == path[2]) &
				(environ[k][3] == path[3]))
			break;

	}
	return (&environ[k][5]);
}

/**
 * paths - concatenates path variable to an array
 *
 *
 * Return: an array of path location
 */
#define PATHCP 2024
char **paths(void)
{
	char *pathvr, **paths, *token;
	char pathcopy[PATHCP];
	int count = 0, i;

	pathvr = _getenv();
	/*copy PATH variables to fixed size array of chars*/
	_strcpy(pathcopy, pathvr);
	for (i = 0; pathcopy[i]; i++)
	{
		if (pathcopy[i] == ':')
			count += 1;
	}
	count += 1;

	i = 0;
	paths = malloc(sizeof(char *) * (count + 1));
	if (paths == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(pathcopy, ":");
	while (token != NULL)
	{
		paths[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (paths[i] == NULL)
		{
			perror("malloc");
			return (NULL);
		}

		_strcpy(paths[i++], token);
		token = strtok(NULL, ":");
	}
	paths[i] = NULL;

	return (paths);
}

/**
 * searchexec - search for executable files in the path
 * @paths: array of address to the path of executable file
 * @file: file to execute
 * @p_case: pointer to variable to keep track of memory cleaning from main func
 *
 * Return: link to an executable file
 */

char *searchexec(char **paths, char *file,  int *p_case)
{
	int i;
	char *link;

	/*search for file in PATH*/
	for (i = 0; paths[i]; i++)
	{
		link = malloc(sizeof(char) * (_strlen(paths[i]) + _strlen(file) + 2));
		if (link == NULL)
		{
			perror("malloc");
			return ("(null)");
		}

		link = _strcpy(link, paths[i]);
		link = _strcat(link, "/");
		link = _strcat(link, file);
		if (access(link, F_OK) != -1)
		{
			*p_case = 1;
			return (link);
		}
		free(link);
	}

	/*check if file is an executable link and it is present*/
	if (access(file, F_OK) != -1)
		return (file);

	return (NULL);
}
