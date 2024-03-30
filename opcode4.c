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
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 1 || (*stack)->n > 128)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n"
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
/**
 * rotl_opcode - rotates the stack to the top.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void rotl_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)(line_number);
	if (!(*stack) || !((*stack)->next))
		return;
	temp = (*stack);
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	for (last = (*stack); last->next;)
		last = last->next;
	temp->next = NULL;
	temp->prev = last;
	last->next = temp;
}
/**
 * rotr_opcode - rotates the stack to the bottom.
 *
 * @stack:Pointer to first node of list
 * @line_number: the number of line in file
 */
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
        stack_t *last;

        (void)(line_number);
        if (!(*stack) || !((*stack)->next))
                return;
	for (last = (*stack); last->next;)
                last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack)->prev = last;
	last->next = (*stack);
	(*stack) = last;
}
