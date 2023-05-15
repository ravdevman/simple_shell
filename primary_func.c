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

/**
 * str_cat - concatenate two strings.
 * @dest : destination.
 * @src : source.
 *
 * Return: the concatenation of the strings.
 */

char *str_cat(char *dest, char *src)
{

	int x, y;

	for (x = 0; dest[x] != '\0'; x++)
		;
	for (y = 0; src[y] != '\0'; y++, x++)
		dest[x] = src[y];
	dest[x] = '\0';
	return (dest);
}



/**
 * _strcmp - compares two strings.
 * @str1 : char.
 * @str2: char.
 * Return: integer.
 */
int _strcmp(const char *str1, const char *str2)
{
	while ((*str1 != '\0' && *str2 != '\0') && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 - *str2);
}
