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

	/* Check if the number of arguments is correct */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ins = make_instructions();			/* Initialize the instruction set */
	file = _calloc(1024, sizeof(char)); /* Allocate memory for the file content */
	fd = open(argv[1], O_RDONLY);		/* Open the file */
	/* Check if the file was opened successfully */
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read(fd, (void *)file, 1024); /* Read the file content */
	lines = strtolines(file);	  /*convert the file to lines*/
	if (!lines)
		return (0);
	opcode = lines[0];				  /* Get the first opcode */
	check_opcode(opcode, ins, lines); /* Check and execute the opcodes */
	free_instruction(ins);			  /* Free the instruction set */
	free(file);						  /* Free the file content */
	free_strings(lines);			  /* Free the lines */
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

	/* If args is provided, save it to the static pointer */
	if (args)
		ptr = args;
	return (ptr); /* Return the saved arguments */
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
	char **args, *a;
	stack_t *head;

	head = NULL; /* Initialize the stack head */
	/* Iterate through the lines of code */
	for (i = 1; opcode; free_strings(args), opcode = lines[i], i++)
	{
		args = from_str_to_args(opcode); /* Convert the line to arguments */
		if (!args)
			continue;
		if (opcode[0] == '#')
			continue;
		save_args(args); /* Save the arguments */
		/* Iterate through the instruction set */
		for (j = 0; ins[j].opcode; j++)
			/* If the opcode matches an instruction, execute the instruction */
			if (_strcmp(args[0], ins[j].opcode) == 0)
			{
				ins[j].f(&head, i);
				break;
			}
		/* If the opcode is not found, print an error message and exit */
		if (!(ins[j].opcode))
		{
			a = args[0];
			fprintf(stderr, "L%d: unknown instruction %s\n", i, a);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(head); /* Free the stack */
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
	/* Iterate through the stack and free each node */
	for (; p; p = head)
	{
		head = p->next;
		free(p);
	}
}
