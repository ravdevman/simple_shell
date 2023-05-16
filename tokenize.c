#include "shell.h"
/**
 * tokenize - create an array of tokens (parameters).
 * @buff: pointer .
 *
 * Return: pointer to array.
 */
char **tokenize(char *buff)
{
	char *token;
	int x = 0, word_count = 0
	char *d = " \n";
	char **argv;

	word_count = split_str(buff);
	if (word_count = NULL)
		return (NULL);

	argv = malloc((word_count + 1) * sizeof(char *));

	if (!argv)
		exit(1);

	token = strtok(buff, d);

	while (token)
	{
		argv[x] = _strdup(token);
		token = strtok(NULL, d);
		x++;
	}
	argv[x] = NULL;
	return (argv);
}
