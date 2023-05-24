#include "main.h"
/**
 * execute_inbuilt - this function executes inbuilt functions
 * it also modifies a flag to indicate if the inbuilt function ran or not
 * @arr: parameter passed to the function to run
 * @inbuilt_ran: track if function ran or not
 *
 * Return: exit status of inbuilt function
 */

int execute_inbuilt(char **arr, int *inbuilt_ran)
{
	int exit_stat = 0;

	if (__strcmp(arr[0], "cd") == 0)
	{
		exit_stat = cd(arr);
		*inbuilt_ran = 1;
		return (exit_stat);
	}
	/*
	else if (__strcmp(arr[0], "env") == 0)
	{
		exit_stat = env();
		*inbuilt_ran = 1;
		return (exit_stat);
	}
	*/
	return (exit_stat);
}
