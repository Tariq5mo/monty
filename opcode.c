#include "monty.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a list.
 *
 * @head:Pointer to first node of list
 * @n: the node's value
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	/* Check if the head is NULL */
	if (!head)
		return (NULL);
	new = _calloc(1, sizeof(stack_t)); /* Allocate memory for the new node */
	new->n = n;						   /* Set the value of the new node */
	new->prev = NULL;				   /* Set the previous of the new node to NULL */
	new->next = *head;				   /* Set the next of the new node to */
					   /* the current head */
	if (*head)
		(*head)->prev = new;
	/* Set the previous of the current head to the new node */
	(*head) = new; /* Update the head to the new node */
	return (new);  /* Return the new node */
}
/**
 * push_opcode - execute the push opcode
 * @stack: the head of stack
 * @line_number: the number of line in file
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	char **args;

	args = save_args(NULL); /* Get the arguments */
	/* Check if the argument is valid */
	if (!args[1] || check_int(args[1]) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Push the value to the stack */
	if (_stack(NULL) == 1)
		add_dnodeint(stack, atoi(args[1]));
	else if (_stack(NULL) == -1)
		add_dnodeint_end(stack, atoi(args[1]));
}
/**
 * check_int - check if ptr is integer
 *
 * @ptr: the string
 * Return: 0 is integer, -1 otherwise
 */
int check_int(char *ptr)
{
	int i;

	/* Iterate through the string */
	for (i = 0; ptr[i]; i++)
	{
		if (ptr[i] < '0' || ptr[i] > '9')
		{
			if (ptr[i] != '-' && i != 0)
				return (-1);
		}
	}
	return (0); /* Return 0 if it is an integer */
}
/**
 * pull_opcode - prints all the elements of a stack list.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void pull_opcode(stack_t **stack, unsigned int line_number)
{
	size_t i;
	stack_t *ptr;

	(void)(line_number);
	ptr = *stack;
	/* Iterate through the stack and print the elements */
	for (i = 0; ptr; ptr = ptr->next)
	{
		printf("%d\n", ptr->n); /*print the node's element*/
		i++;
	}
}
/**
 * pint_opcode - prints the value at the top of the stack
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void pint_opcode(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n); /* Print the top element */
}
