#include "main.h"
/**
 * free_arr - free memory allocated for an array
 * @arr: array of integers
 *
 * Return: nada
 */

void free_arr(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);

	free(arr);
}
