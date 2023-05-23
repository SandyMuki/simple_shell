#include "main.h"
#define BS 1024

/**
 * printem - printerror message to stdout
 * @shellname: name of our shell
 * @program: non existing program
 * @runstat: number of times commands have been run
 *
 * Return: nothing
 */

void printem(char *shellname, int runstat, char *program)
{
	char revbuff[BS];
	char buff[BS];
	int i = 0, len;

	while (runstat != 0)
	{
		revbuff[i++] = (runstat % 10) + '0';
		runstat /= 10;
	}
	revbuff[i] = '\0';


	len = _strlen(revbuff) - 1;
	for (i = 0; revbuff[i]; i++)
		buff[i] = revbuff[len--];
	buff[i] = '\0';

	write(STDOUT_FILENO, shellname, _strlen(shellname));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, buff, _strlen(buff));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, program, _strlen(program));
	write(STDOUT_FILENO, ": not found\n", 12);
}
