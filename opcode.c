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

	if (!head)
		return (NULL);
	new = _calloc(1, sizeof(stack_t));
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	(*head) = new;
	return (new);
}
/**
 * push_opcode - execute the push opcode
 * @stack: the head of stack
 * @line_number: the number of line in file
*/
void push_opcode(stack_t **stack, unsigned int line_number)
{
	char **args;

	args = save_args(NULL);
	if (!args[1] || check_int(args[1]) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
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

	for (i = 0; ptr[i]; i++)
	{
		if (ptr[i] < '0' || ptr[i] > '9')
		{
			if (ptr[i] != '-'  && i != 0)
			return (-1);
		}
	}
	return (0);
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
	for (i = 0; ptr; ptr = ptr->next)
	{
		printf("%d\n", ptr->n);/*print the node's element*/
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
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
