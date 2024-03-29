#include "monty.h"

/**
 * pchar_opcode - prints the char at the top of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void pchar_opcode(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		dprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 1 || (*stack)->n > 128)
	{
		dprintf(stderr, "L%d: can't pchar, value out of range\n"
			, line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}
/**
 * pstr_opcode - prints the string starting at the top of the stack.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void pstr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	(void)(line_number);
	if (!(*stack))
	{
		fprintf(stderr, "\n");
		return;
	}
	for (h = (*stack); h; h = h->next)
	{
		if (h->n < 1 || h->n > 128)
			break;
		putchar(h->n);
	}
	putchar('\n');
}
