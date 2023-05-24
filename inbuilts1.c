#include "main.h"

/**
 * cd - change working directory
 * @arr: commandline parameters
 *
 * Return: nothing
 */

int cd(char **arr)
{
	char *dir = arr[1], *wd;

	if (dir == NULL)
		dir = getenv("HOME");

	if (__strcmp(dir, "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (dir == NULL)
		{
			perror("not set");
			return (1);
		}
	}

	if (chdir(dir) != 0)
	{
		perror("cd");
		return (1);
	}

	wd = getcwd(NULL, 0);
	if (wd == NULL)
	{
		perror("getcwd");
		exit(1);
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", wd, 1);
	free(wd);

	return (0);
}
/**
 * env - print our current working environment
 *
 * Return: exit status of function
 */

int env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}

	return (0);
}
