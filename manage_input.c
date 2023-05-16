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
		{
			red(); /*adding color*/
			write(STDOUT_FILENO, "bye :( ...", 10);
		}
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

/**
 * _fullpathbuffer - finds the string to call execve on
 * @av: pointer to array of user of strings
 * @PATH: pointer to PATH string
 * @copy: pointer to copy of PATH string
 *
 * Return: a pointer to string to call execve on
 */
char *_fullpathbuffer(char **av, char *PATH, char *copy)
{
	char *tok, *fullpathbuffer = NULL, *concatstr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullpathflag = 0, /*len = 0,*/ z = 0, toklen = 0;
	struct stat h;

	copy = NULL;
	copy = _strdup(PATH);
	PATHcount = _splitPATH(copy);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatstr = _concat(tmp, av, tok);
		if (stat(concatstr, &h) == 0)
		{
			fullpathbuffer = concatstr;
			fullpathflag = 1;
			break;
		}
		if (z < PATHcount - 2)
		{
			toklen = _strlen(tok);
			if (tok[toklen + 1] == ':')
			{
				if (stat(av[0], &h) == 0)
				{
					fullpathbuffer = av[0];
					fullpathflag = 1;
					break;
				}
			}
		}
		z++;
		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		fullpathbuffer = av[0];
	free(copy);
	return (fullpathbuffer);
}
/**
 * checkbuiltins - check if first user string is a built-in
 * @av: pointer to array of user of strings
 * @buffer: pointer to user string
 * @exitstatus: exit status of execve
 * Return: 1 if user string is equal to env or 0 otherwise
 */
int checkbuiltins(char **av, char *buffer, int exitstatus)
{
	int i;

	if (_strcmp(av[0], "env") == 0)
	{
		_env();
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		return (1);
	}
	else if (_strcmp(av[0], "exit") == 0)
	{
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		exit(exitstatus);
	}
	else
		return (0);
}
/**
 * _forkprocess - create child process to execute based on user input
 * @av: pointer to array of user of strings
 * @buffer: pointer to user string
 * @fullpathbuffer: pointer to user input
 *
 * Return: 0 on success
 */
int _forkprocess(char **av, char *buffer, char *fullpathbuffer)
{
	int i, status, result, exitstatus = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		green(); /*green color on result*/
		result = execve(fullpathbuffer, av, environ);
		if (result == -1)
		{
			red(); /*color red on error*/
			perror(av[0]);
			for (i = 0; av[i]; i++)
				free(av[i]);
			free(av);
			free(buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
	}
	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
	free(buffer);
	return (exitstatus);
}
