#include "monty.h"

/**
 * free_strings - free array of strings
 *
 * @grid: The two dimensional array
*/
void free_strings(char **grid)
{
	int i;

	if (!grid)
		return;
	for (i = 0; grid[i]; i++)/*Free the rest of the the grid*/
		free(grid[i]);/*Then the array of pointers*/
	free(grid);
}
/**
 * _strdup - put a string to new memory location
 *
 * @str: The_old_string
 * Return: new_string
 */
char *_strdup(char *str)
{
	int i, j;
	char *s;

	if (str == NULL)
		return (NULL);
	i = strlen(str);
	s = _calloc(i + 1, 1);
	if (s == NULL)
		return (NULL);
	for (j = 0; j != i; j++)
		s[j] = str[j];
	return (s);
}
/**
 * _calloc -  allocates memory for an array
 *
 * @nmemb: The elements's number
 * @size: The size of each element
 * Return: void
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int j;
	unsigned char *s;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc((nmemb) * size);
	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	s = ptr;
	for (j = 0; j < nmemb * size; j++)
		s[j] = 0;
	return (ptr);
}
/**
 * from_str_to_args - a string to array of strings
 *
 * @ptr: pointer to the string
 * Return: the array of strings
 */
char **from_str_to_args(char *ptr)
{
	char **s, *p, *str;
	int i, w;

	str = _strdup(ptr);
	for (i = w = 0; str[i];)/*how many words in ptr*/
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] != ' ' && str[i])
		{
			while (str[i] != ' ' && str[i])
				i++;
			w++;
		}
	}
	if (w == 0)
	{
		free(str);
		return (NULL);
	}
	s = _calloc(w + 1, sizeof(char *));
	if (!s)
	{
		return (NULL);
	}
	p = strtok(str, " \0");
	for (i = 0; p; i++)
	{
		s[i] = _strdup(p);
		p = strtok(NULL, " ");
	}
	s[w] = NULL;
	free(str);
	return (s);
}
