#include "shell.h"

/* by Rayane Madoune && Mohamed Amine Barid */

/**
 * white - colro white
 * Return: 0
*/

int white(void)
{
	write(STDOUT_FILENO, "\x1b[0m", 4);
	return (0);
}
/**
 * red - colro red
 * Return: 0
*/
int red(void)
{
	write(STDOUT_FILENO, "\x1b[31m", 5);
	return (0);
}
/**
 * green - colro green
 * Return: 0
*/

int green(void)
{
	write(STDOUT_FILENO, "\x1b[32m", 5);
	return (0);
}
/**
 * blue - colro blue
 * Return: 0
*/

int blue(void)
{
	write(STDOUT_FILENO, "\x1b[34;1m", 7);
	return (0);
}
