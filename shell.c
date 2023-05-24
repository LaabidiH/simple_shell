#include "shell.h"
/**
 * shell - Writing my shell
 * @ac : declaring void variable
 * @argv : declaring void variable
 *
 * Return: Always 0 (Success)
 */
int shell(int ac, char **argv)
{
char *prompt = "(myShell) $ ";
char *lineptr;
size_t n = 0;
(void)ac;
(void)argv;
printf("%s", prompt);
getline(&lineptr, &n, stdin);
printf("%s\n", l);
return (0);
}
