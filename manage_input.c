#include "shell.h"

/* by Rayane Madoune && Mohamed Amine Barid */

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
	strcpy(input_cp, userInput);
	token = strtok(userInput, d);
	for (tk_count = 0; token != NULL; tk_count++)
		token = strtok(NULL, d);

	*argv = malloc(sizeof(char) * tk_count);
	token = strtok(input_cp, d);
	for (i = 0; token != NULL; i++)
	{
		(*argv)[i] = malloc(sizeof(char) * strlen(token));
		strcpy((*argv)[i], token);
		token = strtok(NULL, d);
	}
	(*argv)[i] = NULL;
	free(input_cp);
	free(token);
	return (0);
}
