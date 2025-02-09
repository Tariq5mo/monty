#include "monty.h"

/**
 * free_strings - Free the memory of a two dimensional array
 * of strings
 *
 * @grid: The array of strings
 */
void free_strings(char **grid)
{
	int i;

	if (!grid)
		return;
	/* Iterate through the array and free each string */
	for (i = 0; grid[i]; i++) /*Free the rest of the the grid*/
		free(grid[i]);		  /*Then the array of pointers*/
	free(grid);
}
/**
 * _strdup - Make a copy of a string and return it
 *
 *
 * @str: The string to copy
 * Return: The copy of the string
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
	/* Copy the string */
	for (j = 0; j != i; j++)
		s[j] = str[j];
	return (s);
}
/**
 * _calloc -  Allocates memory for an array of nmemb elements of size bytes
 * each and returns a pointer to the allocated memory
 * The memory is set to zero
 *
 * @nmemb: The number of elements
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
	/* Set the memory to zero */
	for (j = 0; j < nmemb * size; j++)
		s[j] = 0;
	return (ptr);
}
/**
 * from_str_to_args - Make an array of strings from a string
 * that contains words separated by spaces
 * The last element of the array is NULL
 *
 * @ptr: Pointer to the string
 * Return: The array of strings
 */
char **from_str_to_args(char *ptr)
{
	char **s, *p, *str;
	int i, w;

	str = _strdup(ptr);
	/* Count the number of words in the string */
	for (i = w = 0; str[i];) /*how many words in ptr*/
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
	/* If there are no words, free the string and return NULL */
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
	/* Tokenize the string and store the words in the array */
	for (i = 0; p; i++)
	{
		s[i] = _strdup(p);
		p = strtok(NULL, " ");
	}
	s[w] = NULL;
	free(str);
	return (s);
}
