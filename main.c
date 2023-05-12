#include "shell.h"

/* by Rayane Madoune && Mohamed Amine Barid */

/**
 * main - the main fucntion of simple shell
 *
 * @ac: the number of arguments
 * @argv: the arguments
 *
 * Return: 0
*/

int main(int ac, char **argv)
{
	char *prompt = "SHLILO $ "; /*the name*/
	char *userInput; /*were to save the user input*/
	size_t n = 0; /*store the allocated size*/
	ssize_t checkEOF;

	while (1)
	{
		printf("%s", prompt); /*print the name*/
		checkEOF = getline(&userInput, &n, stdin); /*get the user input*/
		/* if getline quit (ctrl + D) then its gonna return the value -1 */
		if (checkEOF == -1)
		{
			printf("bye bye ciaooo man !\n");
			free(userInput);
			return (-1); /*exiting the shell*/
		}
		printf("%s\n", userInput); /*if input is good print it normaly*/
	}
		free(userInput); /*free the allocated mempory*/
	return (0);
}
