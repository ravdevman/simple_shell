#include "shell.h"

/**
* _strcpy - copy a string from the source to a destination.
* @dest: destination.
* @src: source.
*
* Return: copy of the string.
*/

char *_strcpy(char *dest, const char *src)
{
	char *var = dest;

	if (dest == NULL)
		return (NULL);

	while (*src != '\0')
	{

		*dest++ = *src++;
	}

	*dest = '\0';

	return (var);
}


/**
* _strlen - length of a string.
* @str: string argument.
*
* Return: length.
*/

size_t _strlen(const char *str)
{

	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}


/**
 * _strdup - duplicates a string.
 * @s : string to duplicate.
 *
 * Return: duplicated string
 */

char *_strdup(const char *s)
{

	char *destination;
	int i = 0;

	if (s == NULL)
		return (NULL);

	while (s[i])
		i++;

	destination = malloc(sizeof(char) * (i + 1));
	if (destination == NULL)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
	{
		destination[i] = s[i];
	}
	destination[i] != '\0';
	return (destination);
}








