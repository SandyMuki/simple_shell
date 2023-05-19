#include "main.h"
/**
 * __strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: nothing
 */

int __strcmp(const char *s1, const char *s2)
{
	int i = 0, vl;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}

	vl = (s1[i] - s2[i]);

	return (vl);
}

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

