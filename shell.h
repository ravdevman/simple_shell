#ifndef SHELL_H
#define SHELL_H
								/* by Rayane Madoune && Mohamed Amine Barid */
										/*Libraries*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <ctype.h>
#include <errno.h>
/*functions prototypes*/
int split_input(char *userInput, char *input_cp, char *token, ssize_t checkEOF, char ***argv);
/*Primary Functions*/
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
#endif
