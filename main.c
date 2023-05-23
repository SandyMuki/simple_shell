#include "main.h"
/**
 * execute - fork and run a program
 * @search: location in PATH variable
 * @arr: input parameters
 * @env: environment variables
 *
 * Return: execution status
 */

int execute(char *search, char **arr, char **env)

{
	int pid, status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if ((execve(search, arr, env)) == -1)
		{
			exit(1);
		}
		exit(0);
	}
	else
		wait(&status);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (status);
}
/**
 * signal_handler - handles SIGINT interrupt
 * @signum: interrupt integer
 *
 * Return: nothing
 */

void signal_handler(int signum)
{
	(void)signum;/*signal hanlder function*/
	write(1, "\n$ ", 3);
}
/**
 * main - main function to couple shell functions
 * @argc: number of input parameters
 * @argv: number input variables
 * @env: environment variables
 *
 * Return: state of program termination
 */

int main(int argc, char **argv, char **env)
{
	char **arr, **mpath, *search;
	int p_case = 0, exit_stat = 0;
	int runstat = 0;

	mpath = main_path();
	(void)argc, (void)argv;
	signal(SIGINT, signal_handler);
	while (1)
	{
		arr = getntok(mpath, exit_stat);
		runstat++;
		if (arr[0] == NULL)
		{
			free_arr(arr);
			continue;
		}
		ourexit(arr[0], mpath, arr, arr[1], exit_stat);
		if (__strcmp(arr[0], "cd") == 0)
		{
			exit_stat = cd(arr);
			free_arr(arr);
			continue;
		}
		search = searchexec(mpath, arr[0], &p_case);
		if (search == NULL)
		{
			exit_stat = 1;
			printem(argv[0], runstat, arr[0]);
			free_arr(arr);
			continue;
		}
		exit_stat = execute(search, arr, env);
		if (p_case == 1)
			free(search);
		p_case = 0;
		free_arr(arr);
	}
	return (exit_stat);
}

