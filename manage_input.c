#include "shell.h"

/* by Rayane Madoune && Mohamed Amine Barid */

/**
 * prompt - writes a prompt
 * Return: 0 when sucess
 */

int prompt(void)
{
	char *prompt = "SHLILO $ "; /*the name of our shell*/
	ssize_t write_number = 0; /*store the number of character writen*/

	if (isatty(STDIN_FILENO) == 1) /*if it refer to the terminal*/
	{
		write_number = write(STDOUT_FILENO, prompt, 9); /*print the prompt*/
		if (write_number == -1) /*if it fail the writing*/
			exit(0);
	}
	return (0);
}

/**
 * split_input - this function tokenize the userinput
 * @userInput: the input of the user
 * @input_cp: a copy of the input
 * @token: tokens
 * @checkEOF: the number of char
 * @argv: the arguments
 *
 * Return: 0
*/


int split_input(char *userInput, char *input_cp, char *token, ssize_t checkEOF, char ***argv)
{
	char *d = " ";
	int tk_count = 0, i = 0;

	input_cp = malloc(sizeof(char) * checkEOF);
	if (input_cp == NULL)
	{
		perror("tsh: memory allocation error");
		return (-1);
	}
	_strcpy(input_cp, userInput);
	token = strtok(userInput, d);
	for (tk_count = 0; token != NULL; tk_count++)
		token = strtok(NULL, d);

	*argv = malloc(sizeof(char) * tk_count);
	token = strtok(input_cp, d);
	for (i = 0; token != NULL; i++)
	{
		(*argv)[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy((*argv)[i], token);
		token = strtok(NULL, d);
	}
	(*argv)[i] = NULL;
	free(input_cp);
	free(token);
	return (0);
}
