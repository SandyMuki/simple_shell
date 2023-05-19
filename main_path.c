#include "main.h"

/**
 * main_path - gets an array of paths for multiple runs
 *
 * Return: array of paths
 */

char **main_path(void)
{
	char **pathv, **newpath;
	int i, count = 0;

	pathv = paths();
	for (i = 0; pathv[i]; i++)
		count += 1;

	newpath = malloc(sizeof(char *) * (count + 1));
	if (newpath == NULL)
		return (NULL);

	for (i = 0; pathv[i]; i++)
	{
		newpath[i] = malloc(sizeof(char) * (_strlen(pathv[i]) + 1));
		_strcpy(newpath[i], pathv[i]);
	}
	newpath[i] = NULL;

	free_arr(pathv);
	return (newpath);
}
