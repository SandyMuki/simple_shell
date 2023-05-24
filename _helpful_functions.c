#include "main.h"

/**
 * _strcpy - copy string from one location to another
 * @dest: destination to copy str
 * @src: location to copy from
 *
 * Return: copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - get the length of a string
 * @s: string to calculate its length
 * Description: function gets the length of a string
 *
 * Return: length of integer
 **/

int _strlen(char *s)
{
	int len = 0;

	for (len = 0; s[len]; len++)
		;

	return (len);
}

/**
 * *_strcat - concatenate strings
 * @dest: string to be concatenated to
 * @src: second string to concatenate from
 * Description: function that concatenates a string to another.
 *
 * Return: destination string
 **/

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';

	return (dest);
}
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
