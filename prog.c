#include "monty.h"

/**
 * main - the core of monty program
 *
 * @argc: the number of arguments
 * @argv: the arguments of monty
 * Return: 0 Success, -1 on failure
 */
int main(int argc, char **argv)
{
	char **lines, *opcode, *file;
	int fd;
	instruction_t *ins;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ins = make_instructions();
	file = _calloc(1024, sizeof(char));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read(fd, (void *)file, 1024);
	lines = strtolines(file);/*convert the file to lines*/
	if (!lines)
		return (0);
	opcode = lines[0];
	check_opcode(opcode, ins, lines);
	free_instruction(ins);
	free(file);
	free_strings(lines);
	return (0);
}
/**
 * save_args - save the arguments of opcode
 *
 * @args: the arguments of opcode or NULL
 * Return: the arguments
 */
char **save_args(char **args)
{
	static char **ptr;

	if (args)
		ptr = args;
	return (ptr);
}
/**
 * check_opcode - check and execute opcode
 *
 * @opcode: the opcode (push, pull ...etc)
 * @ins: pointer to array of structures of instructions
 * @lines: the lines of file
 */
void check_opcode(char *opcode, instruction_t *ins, char **lines)
{
	unsigned int i, j;
	char **args;
	stack_t *head;

	head = NULL;
	for (i = 1; opcode; free_strings(args), opcode = lines[i], i++)
	{
		args = from_str_to_args(opcode);
		if (!args)
			continue;
		if (opcode[0] == '#')
			continue;
		save_args(args);
		for (j = 0; ins[j].opcode; j++)
			if (_strcmp(args[0], ins[j].opcode) == 0)
			{
				ins[j].f(&head, i);
				break;
			}
		if (!(ins[j].opcode))
		{
			fprintf(stderr, "L%d: unknown instruction\n", i);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(head);
}
/**
 * free_stack - Frees a stack list.
 *
 * @head:Pointer to first node of list
 */
void free_stack(stack_t *head)
{
	stack_t *p = head;

	if (!head)
		return;
	for (; p; p = head)
	{
		head = p->next;
		free(p);
	}
}
