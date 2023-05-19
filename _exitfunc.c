#include "main.h"

/**
 * ourexit - function to exit bash
 * @exit1: exit string
 * @mpath: path array to free memory
 * @arr: input array to free
 * @args: exit parameter
 *
 * Return: nothing
 */
void ourexit(char *exit1, char **mpath, char **arr, char *args)
{
	char *exit2 = "exit";
	int status;
	int i = 0, count = 0;

	if (_strlen(exit1) == _strlen(exit2))
	{
		for (i = 0; exit2[i]; i++)
		{
			if (exit1[i] == exit2[i])
				count += 1;
		}
	}

	/*exit and free path memory*/
	if ((count == 4) & (args == NULL))
	{
		free_arr(arr);
		free_arr(mpath);
		exit(0);
	}
	else if ((count == 4) & (args != NULL))
	{
		status = atoi(args);
		free_arr(arr);
		free_arr(mpath);
		exit(status);
	}
}
