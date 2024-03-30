#include "monty.h"

/**
 * _strcmp - compare between two strings
 *
 * @s1: first string
 * @s2: second string
 * Return: 0 are equals, 1 s1 > s2, -1 s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++)
		;
	j = s1[i] - s2[i];
	return (j);
}
/**
 * set_null - set first '#' to '\0'
 *
 * @s: the string
 */
void set_null(char *s)
{
	for (; *s; s++)
		if (*s == '#')
		{
			*s = '\0';
			return;
		}
}
/**
 * strtolines - convert a string to array of lines
 *
 * @ptr: pointer to the string
 * Return: the array of lines
*/
char **strtolines(char *ptr)
{
	char **s, *p, *str;
	int i, line;

	str = _strdup(ptr);
	for (i = line = 0;;)/*how many lines in ptr*/
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
		{
			line++;
			i++;
		}
		if (!str[i])
		{
			line++;
			break;
		}
	}
	if (line == 0)
	{
		free(str);
		return (NULL);
	}
	s = _calloc(line + 1, sizeof(char *));
	p = strtok(str, "\n");
	for (i = 0; p; i++)
	{
		s[i] = _strdup(p);
		p = strtok(NULL, "\n");
	}
	s[line] = NULL;
	for (i = 0; s[i]; i++)
		;
	free(str);
	return (s);
}
/**
 * make_instructions - make array of structures for instruction
 *
 * Return: array of structures
 */
instruction_t *make_instructions(void)
{
	instruction_t *ptr;

	ptr = _calloc(16, sizeof(instruction_t));
	ptr[0].opcode = _strdup("push");
	ptr[0].f = push_opcode;
	ptr[1].opcode = _strdup("pall");
	ptr[1].f = pull_opcode;
	ptr[2].opcode = _strdup("pint");
	ptr[2].f = pint_opcode;
	ptr[3].opcode = _strdup("pop");
	ptr[3].f = pop_opcode;
	ptr[4].opcode = _strdup("swap");
	ptr[4].f = swap_opcode;
	ptr[5].opcode = _strdup("add");
	ptr[5].f = add_opcode;
	ptr[6].opcode = _strdup("nop");
	ptr[6].f = nop_opcode;
	ptr[7].opcode = _strdup("sub");
	ptr[7].f = sub_opcode;
	ptr[8].opcode = _strdup("div");
	ptr[8].f = div_opcode;
	ptr[9].opcode = _strdup("mul");
	ptr[9].f = mul_opcode;
	ptr[10].opcode = _strdup("mod");
	ptr[10].f = mod_opcode;
	ptr[11].opcode = _strdup("pchar");
	ptr[11].f = pchar_opcode;
	ptr[12].opcode = _strdup("pstr");
	ptr[12].f = pstr_opcode;
	ptr[13].opcode = _strdup("rotl");
	ptr[13].f = rotl_opcode;
	ptr[14].opcode = _strdup("rotr");
	ptr[14].f = rotr_opcode;
	ptr[15].opcode = NULL;
	ptr[15].f = NULL;
	return (ptr);
}
/**
 * free_instruction - free array of structures
 *
 * @ptr: pointer to stack
 */
void free_instruction(instruction_t *ptr)
{
	int i;

	for (i = 0; ptr[i].opcode; i++)
	{
		free(ptr[i].opcode);
	}
	free(ptr);
}
