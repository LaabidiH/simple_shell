#include "shell.h"
/**
 * shell - Writing my shell.
 * @prompt : to write the text
 * @lineptr : the line pointer
 * @n : the size
 *
 * Return: Always 0 (Success)
 */
int shell(int ac, char **argv){
char *prompt = "(myShell) $ ";
char *lineptr;
size_t n = 0; 

  /* declaring void variables */
(void)ac; (void)argv;
printf("%s", prompt);
getline(&lineptr, &n, stdin);
printf("%s\n", lineptr);
free(lineptr);
return (0);
}
