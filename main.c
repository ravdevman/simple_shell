#include "shell.h"

/* by Rayane Madoune && Mohamed Amine Barid */

/**
 * main - the main fucntion of simple shell (SHLILO)
 * Return: 0
*/

int main(void)
{
	char *fullpathbuffer = NULL, *copy = NULL, *userInput = NULL;
	char *PATH = NULL;
	char **argv;
	int exitstatus = 0;

	signal(SIGINT, SIG_IGN); /*ance signal*/
	PATH = _getenv("PATH");
	while (1)
	{
		blue(); /*color of the promt*/
		prompt();
		white(); /*reset to normal color*/
		userInput = read_line(); /*get the user input*/
		if (*userInput != '\0')
		{
			argv = tokenize(userInput);
			if (argv == NULL)
			{
				free(userInput);
				continue;
			}
			fullpathbuffer = _fullpathbuffer(argv, PATH, copy);
			if (checkbuiltins(argv, userInput, exitstatus) == 1)
				continue;
			exitstatus = _forkprocess(argv, userInput, fullpathbuffer);
		}
		else
			free(userInput);
	}
	return (0);
}
