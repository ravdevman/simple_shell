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
	char *userInput, *input_cp = NULL; /*were to save the user input, and the copy of user input*/
	size_t n = 0; /*store the allocated size*/
	ssize_t checkEOF;
	char *d = " ", *token; /*separationn of strtok*/
	int tk_count = 0, i = 0;

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

	input_cp = malloc(sizeof(char) * checkEOF);
	if (input_cp == NULL)
	{
		perror("tsh: memory allocation error");
		return (-1);
	}
	strcpy(input_cp, userInput);

	token = strtok(userInput, d);
	for (tk_count = 0; token != NULL; tk_count++)
	{
		token = strtok(NULL, d);
	}

	argv = malloc(sizeof(char) * tk_count);

	token = strtok(input_cp, d);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, d);
	}
	argv[i] = NULL;

		free(userInput); /*free the allocated mempory*/
	return (0);
}
