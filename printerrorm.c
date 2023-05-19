#include "main.h"

/**
 * printem - printerror message to stdout
 * @shellname: name of our shell
 * @program: non existing program
 *
 * Return: nothing
 */

void printem(char *shellname, char *program)
{
	write(STDOUT_FILENO, shellname, _strlen(shellname));
	write(STDOUT_FILENO, ": 1: ", 5);
	write(STDOUT_FILENO, program, _strlen(program));
	write(STDOUT_FILENO, ": not found\n", 12);
}
