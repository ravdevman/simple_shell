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
 * read_line - reads the userinput and stores it in a buffer.
 *
 * Return: a pointer to the buffer
 */

char *read_line(void)
{
	ssize_t rd_count = 0; /* read count */
	size_t n_cahr = 0; /*the number of caracter*/
	char *buff; /* BUFFER */
	int i = 0;

	rd_count = getline(&buff, &n_cahr, stdin);
	/* if getline quit (ctrl + D) then its gonna return the value -1 */
	if (rd_count == -1)
	{
		free(buff);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "bye :( ...", 10);
		exit(0);
	}
	/*special char handling*/
	if (buff[rd_count - 1] == '\n' || buff[rd_count - 1] == '\t')
		buff[rd_count - 1] = '\0';
	for (i = 0; buff[i]; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ')
		{
			buff[i] = '\0';
			break;
		}
	}
	return (buff);
}
