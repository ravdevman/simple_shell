#include "shell.h"

/* by Rayane Madoune && Mohamed Amine Barid */

/**
 * tokenize - create an array of tokens (parameters)
 * @buffer: pointer
 *
 * Return: pointer to array
 */
char **tokenize(char *buffer)
{
	char *token;
	int i = 0, wordcount = 0;
	char *delimiter = " \n";
	char **av;

	wordcount = _splitstring(buffer);
	if (!wordcount)
		return (NULL);
	av = malloc((wordcount + 1) * sizeof(char *));
	if (av == NULL)
		exit(1);
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		av[i] = _strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	av[i] = NULL;
	return (av);
}
