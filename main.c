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
	char *d = " ", *token; /*separationn of strtok*/

	while (1)
	{
		prompt();
		userInput = read_line(); /*get the user input*/
		printf("%s\n", userInput); /*testing if the userinput work*/
	}
	/*free the allocated mempory*/
	free(argv);
	free(userInput);
	return (0);
}
