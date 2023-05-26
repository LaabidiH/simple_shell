#include <shell.h>

/**
 * set - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *set1(char *g, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		g[i] = b;
	return (g);
}
/**
 * free - frees a string of strings
 * @pp: string of strings
 */
void free1(char **ss)
{
	char **a = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(a);
}
/**
 * Ralloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *Ralloc1(void *pr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!pr)
		return (malloc(new_size));
	if (!new_size)
		return (free(pr), NULL);
	if (new_size == old_size)
		return (pr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)pr)[old_size];
	free(pr);
	return (p);
}
