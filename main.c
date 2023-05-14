#include "shell.h"

/* by Rayane Madoune && Mohamed Amine Barid */

/**
 * main - the main fucntion of simple shell (SHLILO)
 *
 * @ac: the number of arguments
 * @argv: the arguments
 *
 * Return: 0
*/

int main(int ac, char **argv)
{
	char *userInput = NULL, *input_cp = NULL; /*store user input & copy of it*/
	size_t n = 0; /*store the allocated size*/
	ssize_t checkEOF;
	char *d = " ", *token; /*separationn of strtok*/

	while (1)
	{
		prompt();
		checkEOF = getline(&userInput, &n, stdin); /*get the user input*/
		/* if getline quit (ctrl + D) then its gonna return the value -1 */
		if (checkEOF == -1)
		{
			free(userInput);
			if (isatty(STDIN_FILENO) != 0) /*if it refer to the terminal*/
            	write(STDOUT_FILENO, "bye :( ...", 10); /*write bye msg*/
        	exit(0); /*exiting the shell*/
		}
		printf("%s\n", userInput); /*if input is good print it normaly*/
		split_input(userInput, input_cp, token, checkEOF, &argv);
	} /*free the allocated mempory*/
	free(argv);
	free(userInput);
	return (0);
}
